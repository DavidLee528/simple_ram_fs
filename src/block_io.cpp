#include "block_io.hpp"

// std::shared_ptr<ramfs::byte_t> BlockIO::bread(size_t block, ramfs::disk_amount_t disk) {
ramfs::byte_t *BlockIO::bread(size_t block, ramfs::disk_amount_t disk) {
    if (block > ((this->disk_size / this->block_size) - 1)) throw std::invalid_argument("Invaild block #"); 
    size_t start_byte_idx = block * this->block_size; 
    // return std::shared_ptr<ramfs::byte_t>(this->disk_array.at(disk).get() + start_byte_idx); 
    return (this->disk_array.at(disk).get() + start_byte_idx); 
}

int BlockIO::bwrite(size_t block, const void *buf, ramfs::disk_amount_t disk) {

}