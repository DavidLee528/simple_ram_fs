#include "block_manage.hpp"
#include "block_io.hpp"

void BlockManage::init() {
    const size_t bound { 8388608 }; // 8MB (8388608) Items in FAT / DAT
    ramfs::fat_item_t prototype_fat {
        -1,     // to be fill by |i|
        0, 
        -1, 
        0
    }; 
    ramfs::dat_item_t prototype_dat {
        "", 
        0, 
        static_cast<uint16_t>(0)
    }; 

    // init FAT
    ramfs::fat_item_t *curr_fat = reinterpret_cast<ramfs::fat_item_t *>(bread(0)); 
    for (size_t i = 0; i < bound; ++i) {
        prototype_fat.idx = i; 
        *curr_fat = prototype_fat; 
        ++curr_fat; 
    }
    // init DAT
    ramfs::dat_item_t *curr_dat = reinterpret_cast<ramfs::dat_item_t *>(curr_fat); 
    for (size_t i = 0; i < bound; ++i) {
        *curr_dat = prototype_dat; 
        ++curr_dat; 
    }
}

int BlockManage::balloc(size_t n) {
    ramfs::fat_item_t tmp {}
    
}

void BlockManage::bfree(size_t idx) {

}