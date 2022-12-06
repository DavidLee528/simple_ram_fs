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

#include "disk.hpp"

class BlockIO: public VDisk {

public:

    /**
     * @brief Read a block from disk
     * 
     * @param block Index of the block to read from
     * @param buf Data buffer to be filled with content of block
     * @return int -1 for error, 0 otherwise
     */
    static inline int bread(size_t block, void *buf); 

    /**
     * @brief Write a block to disk
     * 
     * @param block Index of the block to write to
     * @param buf Data buffer to write in the block
     * @return int -1 for error, 0 otherwise
     */
    static inline int bwrite(size_t block, const void *buf); 

}; 



#endif /* _BLOCK_IO_HPP_ */