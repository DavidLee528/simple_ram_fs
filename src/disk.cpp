#include "disk.hpp"
#include "terminal_io.hpp"

VDisk::VDisk() {
    this->init_ramfs(); 
    this->init_interactive_system(); 
}

VDisk::~VDisk() {
    // free disk allocation
    for (std::vector<std::vector<char>*>::iterator iter = this->disk_array.begin(); iter != this->disk_array.end(); ++iter) {
        delete *iter; 
    }
}

void VDisk::init_ramfs() {
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

std::tuple<block_size_t, disk_size_t, disk_amount_t> VDisk::get_config_from_file(const std::string &rpath) {
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

void VDisk::init_interactive_system() {
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

        if (op == "") continue; 
        else if (op == "help") print_help(); 
        else if (op == "sbi") print_system_basic_information(*this); 
        else print_undefined_command(op); 
    }
}