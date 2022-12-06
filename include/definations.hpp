#ifndef _DEFINATIONS_HPP_
#define _DEFINATIONS_HPP_ 1

// #define NDEBUG

#include <vector>

namespace ramfs {

/**
 * @brief Describe a Byte
 */
// typedef uint8_t byte_t; 
using byte_t = uint8_t; 

/**
 * @brief Data type decribe a block size (Byte)
 */
// typedef uint16_t block_size_t; 
using block_size_t = uint16_t; 

/**
 * @brief Data type decribe a disk size (Byte)
 */
// typedef uint64_t disk_size_t;
using disk_size_t = uint64_t; 

/**
 * @brief Data type decribe the disk amount 
 */
// typedef uint8_t disk_amount_t; 
using disk_amount_t = uint8_t; 

/**
 * @brief Describe an item in File Allocation Table
 *        (16 Bytes)
 */
using fat_item_t = struct {
    int idx; 
    int is_busy; 
    int next; 
    int reserve; 
}; 

/**
 * @brief Describe an item in Directory Allocation Table
 *        (16 Bytes)
 */
using dat_item_t = struct {
    char filename[32]; 
    int start_idx; 
    uint16_t reserve; 
}; 

using data_block_t = struct {
    ramfs::byte_t data[4096];   // to be modify to dynamic
}; 

/**
 * @brief Index of first byte in each section 
 */
static const size_t idx_fat      {         0UL };    // Byte
static const size_t idx_dat      { 134217728UL };    // Bytes
static const size_t idx_reserve  { 268435456UL };    // Bytes
static const size_t idx_data     { 536870912UL };    // Bytes

/**
 * @brief Length of each section
 */
static const size_t size_fat     { 134217728UL };    // Bytes
static const size_t size_dat     { 134217728UL };    // Bytes
static const size_t size_reserve { 268435456UL };    // Bytes

} /* namespace ramfs */

#endif /* _DEFINATIONS_HPP_ */