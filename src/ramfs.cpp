#include "ramfs.hpp"
#include "terminal_io.hpp"

int main(int argc, const char **argv) {
    // try to initial system
    try {
        Ramfs ramfs; 
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return -1; 
    }
     
    return 0; 
}

void Ramfs::init_ramfs() {
    // get configuration
    std::tuple<block_size_t, disk_size_t, disk_amount_t> config {get_config_from_file("../../ramfs.conf")}; 
    assert(std::get<0>(config) % 1024 == 0);                            // BLOCK_SIZE must be integral multiple of 1024
    assert(std::get<1>(config) % std::get<0>(config) == 0);             // DISK_SIZE must be integral multiple of BLOCK_SIZE

    // allocate memory space
    for (disk_amount_t i = 0; i < std::get<2>(config); ++i) {
        std::vector<char> *new_disk = new std::vector<char>(std::get<1>(config)); 
        this->disk_array.push_back(new_disk); 
    }

    this->block_size = std::get<0>(config); 
}

std::tuple<block_size_t, disk_size_t, disk_amount_t> Ramfs::get_config_from_file(const std::string &rpath) {
    static const std::string config_path = std::filesystem::current_path().append(rpath); 
    std::ifstream config_file {}; 
    config_file.open(config_path, std::ios::in); 
    if (!config_file.is_open()) throw std::runtime_error("Cannot open configure file"); 
    
    block_size_t block_size {}; 
    disk_size_t disk_size {}; 
    disk_amount_t disk_amount {}; 

    std::string tmp {}; 
    for (size_t cnt {0}; std::getline(config_file, tmp); ++cnt) {
        if (cnt != 1 && cnt != 5 && cnt != 8) continue; 
        std::vector<std::string> split_res {}; 
        boost::split(split_res, tmp, boost::is_any_of("="));    // in config file: KEY=VALUE
        switch (cnt) {
            case 1: block_size = static_cast<block_size_t>(std::stoul(split_res.at(1))); break; 
            case 5: disk_size = static_cast<disk_size_t>(std::stoull(split_res.at(1))); break; 
            case 8: disk_amount = static_cast<disk_amount_t>(std::stoul(split_res.at(1))); break; 
        }
    }

    config_file.close(); 
    return std::make_tuple(block_size, disk_size, disk_amount); 
}

void Ramfs::init_interactive_system() {
    print_welcome(); 

    std::string curr_username {}; 
    std::string curr_path {}; 

    // to delete
    curr_username = "david"; 
    curr_path = "~/dev/code/src"; 

    while (true) {
        print_interaction_text(curr_username, curr_path); 

        std::string op {}; 
        std::getline(std::cin, op); 

        if (op == "help") print_help(); 
        else if (op == "sbi") print_system_basic_information(*this); 
        else print_undefined_command(op); 
    }
}

// to be test
void Ramfs::bread(disk_amount_t dn, std::vector<char>::size_type idx, std::vector<char> &buf, std::vector<char>::size_type len = 0) {
    for (std::vector<char>::size_type i = idx * this->block_size; i < idx * this->block_size + len * this->block_size; ++i) {
        buf.push_back(this->disk_array.at(dn)->at(i)); 
    }
    buf.shrink_to_fit(); 
}

// to be test
void Ramfs::bwrite(disk_amount_t dn, std::vector<char>::size_type idx, const std::vector<char> &buf) {
    assert(buf.size() % 8 == 0); 
    assert(buf.size() % this->block_size == 0); 

    for (std::vector<char>::size_type i = 0; i < buf.size(); ++i) {
        this->disk_array.at(dn)->at(idx * this->block_size + i) = buf.at(i); 
    }
}