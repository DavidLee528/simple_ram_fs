/**
 * @file disk.hpp
 * @author David Lee (13121515269@163.com)
 * @brief Implements of Level-0 Virtual In-memory Disk Layer
 * @version 0.1
 * @date 2022-12-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _DISK_HPP_
#define _DISK_HPP_ 1

#include <iostream>
#include <map>
#include <filesystem>
#include <fstream>
#include <tuple>
#include <array>
#include <fmt/chrono.h>
#include <fmt/color.h>
#include <boost/stacktrace.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

#include "definations.hpp"

class VDisk {

/**
 * @brief Constructor and Destructor
 */
public: 
    VDisk(); 
    ~VDisk(); 

/**
 * @brief Getters for system basic information
 */
public: 
    block_size_t get_block_size() const { return this->block_size; }
    disk_size_t get_disk_size() const { return this->disk_array.at(0)->size(); }
    disk_size_t get_disk_amount() const { return this->disk_array.size();  }

public: 
    void init_ramfs(); 
    std::tuple<block_size_t, disk_size_t, disk_amount_t> get_config_from_file(const std::string &rpath); 
    void init_interactive_system(); 

private: 
    block_size_t block_size {0}; 
    std::vector<std::vector<char>*> disk_array {}; 

}; 

#endif /* _DISK_HPP_ */