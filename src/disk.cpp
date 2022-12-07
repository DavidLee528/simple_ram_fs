#include "disk.hpp"
#include "terminal_io.hpp"
#include <definations.hpp>

VDisk::VDisk() {
    this->init_ramfs(); 
}

VDisk::~VDisk() {
    // free disk allocation - RAII - shared_pointer
    // for (std::vector<std::shared_ptr<ramfs::byte_t>>::iterator iter = this->disk_array.begin(); iter != this->disk_array.end(); ++iter) {
    //     delete *iter; 
    // }
}

void VDisk::init_ramfs() {
    // get configuration
    std::tuple<ramfs::block_size_t, ramfs::disk_size_t, ramfs::disk_amount_t> config {get_config_from_file("../../ramfs.conf")}; 
    assert(std::get<0>(config) % 1024 == 0);                            // BLOCK_SIZE must be integral multiple of 1024
    assert(std::get<1>(config) % std::get<0>(config) == 0);             // DISK_SIZE must be integral multiple of BLOCK_SIZE

    this->block_size = std::get<0>(config); 
    this->disk_size = std::get<1>(config); 
    this->disk_amount = std::get<2>(config); 

    // allocate memory space for every disk
    for (ramfs::disk_amount_t i = 0; i < this->disk_amount; ++i) {
        std::shared_ptr<ramfs::byte_t> new_disk {new ramfs::byte_t[this->disk_size]}; 
        memset(new_disk.get(), 0, this->disk_size); 
        this->disk_array.push_back(new_disk); 
    }
}

std::tuple<ramfs::block_size_t, ramfs::disk_size_t, ramfs::disk_amount_t> VDisk::get_config_from_file(const std::string &rpath) {
    static const std::string config_path = std::filesystem::current_path().append(rpath); 
    std::ifstream config_file {}; 
    config_file.open(config_path, std::ios::in); 
    if (!config_file.is_open()) throw std::runtime_error("Cannot open configure file"); 
    
    ramfs::block_size_t block_size {}; 
    ramfs::disk_size_t disk_size {}; 
    ramfs::disk_amount_t disk_amount {}; 

    std::string tmp {}; 
    for (size_t cnt {0}; std::getline(config_file, tmp); ++cnt) {
        if (cnt != 1 && cnt != 5 && cnt != 8) continue; 
        std::vector<std::string> split_res {}; 
        boost::split(split_res, tmp, boost::is_any_of("="));    // in config file: KEY=VALUE
        switch (cnt) {
            case 1: block_size = static_cast<ramfs::block_size_t>(std::stoul(split_res.at(1))); break; 
            case 5: disk_size = static_cast<ramfs::disk_size_t>(std::stoull(split_res.at(1))); break; 
            case 8: disk_amount = static_cast<ramfs::disk_amount_t>(std::stoul(split_res.at(1))); break; 
        }
    }

    config_file.close(); 
    return std::make_tuple(block_size, disk_size, disk_amount); 
}

