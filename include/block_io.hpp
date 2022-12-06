/**
 * @file block_io.hpp
 * @author David Lee (13121515269@163.com)
 * @brief The Level-1 of the whole file system
 * @version 0.1
 * @date 2022-12-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _BLOCK_IO_HPP_
#define _BLOCK_IO_HPP_ 1

#include <iostream>
#include <exception>

#include "disk.hpp"
#include "definations.hpp"

class BlockIO: public VDisk {

public: 
    using VDisk::VDisk; 

public:

    /**
     * @brief Read a block from disk
     * 
     * @param block Index of the block to read from
     * @param buf Data buffer to be filled with content of block
     * @param disk The number of disk
     * @return int -1 for error, 0 otherwise
     */
    // std::shared_ptr<ramfs::byte_t> bread(size_t block, ramfs::disk_amount_t disk = 0); 
    ramfs::byte_t *bread(size_t block, ramfs::disk_amount_t disk = 0); 

    /**
     * @brief Write a block to disk
     * 
     * @param block Index of the block to write to
     * @param buf Data buffer to write in the block
     * @param disk The number of disk
     * @return int -1 for error, 0 otherwise
     */
    void bwrite(size_t block, const void *buf, ramfs::disk_amount_t disk = 0); 

}; 



#endif /* _BLOCK_IO_HPP_ */