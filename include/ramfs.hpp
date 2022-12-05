#ifndef _RAMFS_HPP_
#define _RAMFS_HPP_ 1

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

typedef uint16_t block_size_t; 
typedef uint64_t disk_size_t; 
typedef uint8_t disk_amount_t; 


class Ramfs {
public: 
    Ramfs() {
        this->init_ramfs(); 
        this->init_interactive_system(); 
    }
    ~Ramfs() {
        // free disk allocation
        for (std::vector<std::vector<char>*>::iterator iter = this->disk_array.begin(); iter != this->disk_array.end(); ++iter) {
            delete *iter; 
        }
    }
public: // return system basic information
    block_size_t get_block_size() const { return this->block_size; }
    disk_size_t get_disk_size() const { return this->disk_array.at(0)->size(); }
    disk_size_t get_disk_amount() const { return this->disk_array.size();  }

public: // block I/O
    /**
     * @brief block read
     * 
     * @param dn    disk number
     * @param idx   index of block
     * @param buf   read buffer
     * @param len   length of block
     */
    void bread(disk_amount_t dn, std::vector<char>::size_type idx, std::vector<char> &buf, std::vector<char>::size_type len = 0); 

    /**
     * @brief block write
     * 
     * @param dn    disk number
     * @param idx   index of block
     * @param buf   write buffer
     */
    void bwrite(disk_amount_t dn, std::vector<char>::size_type idx, const std::vector<char> &buf); 

public: // block allocate/free
    std::vector<char> *balloc(block_size_t block_size); 
    void bfree(std::vector<char> *ptr_block); 

private: 
    void init_ramfs(); 
    std::tuple<block_size_t, disk_size_t, disk_amount_t> get_config_from_file(const std::string &rpath); 
    void init_interactive_system(); 


private: 
    block_size_t block_size {0}; 
    std::vector<std::vector<char>*> disk_array {}; 
}; 

#endif /* _RAMFS_HPP_ */