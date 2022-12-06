#include "block_manage.hpp"
#include "block_io.hpp"

void BlockManage::init() {
    // init FAT
    const size_t bound_fat { 8388608 }; // 8M (8388608) Items in FAT
    ramfs::fat_item_t prototype_fat { -1, 0, -1, 0 }; 
    ramfs::fat_item_t *curr_fat = reinterpret_cast<ramfs::fat_item_t *>(bread(0)); 
    for (size_t i = 0; i < bound_fat - 10; ++i) {
        prototype_fat.idx = i; 
        *curr_fat = prototype_fat; 
        ++curr_fat; 
    }

    // init DAT
    const size_t bound_dat { 2097152 }; // 2M (2097152) Items in DAT
    ramfs::dat_item_t prototype_dat { -1, "", -1, 0 }; 
    ramfs::dat_item_t *curr_dat = reinterpret_cast<ramfs::dat_item_t *>(curr_fat); 
    for (size_t i = 0; i < bound_dat - 10; ++i) {
        prototype_dat.idx = i; 
        *curr_dat = prototype_dat; 
        ++curr_dat; 
    }

    // init directory
    this->pt.put(
        boost::property_tree::basic_ptree<std::string, std::vector<int>>::path_type{"$/root", '/'}, 
        std::vector<int>{}
    ); 
}

int BlockManage::balloc(size_t n) {
    const size_t bound_fat { 8388608 }; // 8M (8388608) Items in FAT
    ramfs::fat_item_t tmp { }; 
    ramfs::fat_item_t *last { nullptr }; 
    ramfs::fat_item_t *curr_fat = reinterpret_cast<ramfs::fat_item_t *>(bread(0)); 
    size_t allocated { 0 }; 
    size_t number { n }; 
    
    // return value: block descriptor
    int bd {-1}; 

    for (size_t i = 0; i < bound_fat - 10; ++i) {
        tmp = *curr_fat; 
        if (!tmp.is_busy) {
            if (bd == -1) bd = tmp.idx;                       // first block
            if (last != nullptr) last->next = curr_fat->idx;  // link
            last = curr_fat;                                  // update ptr |last|
            curr_fat->is_busy = 1;
            ++allocated; 
            if (allocated == number) break;                   // return if enough block allocated 
        }
        ++curr_fat; 
    }

    return bd; 
}

void BlockManage::bfree(size_t idx) {
    const size_t bound_fat { 8388608 }; // 8M (8388608) Items in FAT
    ramfs::fat_item_t *curr_fat = reinterpret_cast<ramfs::fat_item_t *>(bread(0)); 

    for (size_t i = 0; i < bound_fat - 10; ++i) {
        if ((curr_fat)->idx != idx) {++curr_fat; continue; }
        do {
            curr_fat->is_busy = 0;
        } while (curr_fat->next != -1 && ++curr_fat); 
        break; 
    }

}

void BlockManage::make_dir(const std::string &dirname, const std::string &path) {
    this->pt.put(
        boost::property_tree::basic_ptree<std::string, std::vector<int>>::path_type{path + '/' + dirname, '/'}, 
        std::vector<int>{}
    ); 
}

void BlockManage::log_file(const std::string &filename, const std::string &path) {
    // Allocate disk for new file
    int bd = this->balloc(2); 

    // log filename -> block descriptor
    this->filename_to_bd.insert(std::make_pair(filename, bd)); 

    // Add file
    this->pt.get_child(
        boost::property_tree::basic_ptree<std::string, std::vector<int>>::path_type{path, '/'}
    ).data().push_back(bd); 
}

void BlockManage::unlog_file(const std::string &filename, const std::string &path) {
    std::vector<int> & data { this->pt.get_child(
        boost::property_tree::basic_ptree<std::string, std::vector<int>>::path_type{path, '/'}
    ).data() }; 

    std::remove_if(data.begin(), data.end(), [this, filename](int val) { return val == this->filename_to_bd[filename]; }); 

    this->filename_to_bd.erase(filename); 
}