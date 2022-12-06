#include "block_io.hpp"

ramfs::byte_t *BlockIO::bread(size_t block, ramfs::disk_amount_t disk) {
    if (block > ((this->disk_size / this->block_size) - 1)) throw std::invalid_argument("Invaild block # when invoking BlockIO::bread"); 
    size_t start_byte_idx { block * this->block_size }; 
    return (this->disk_array.at(disk).get() + start_byte_idx); 
}

void BlockIO::bwrite(size_t block, const void *buf, ramfs::disk_amount_t disk) {
    if (block > ((this->disk_size / this->block_size) - 1)) throw std::invalid_argument("Invaild block # when invoking BlockIO::bwrite"); 
    size_t start_byte_idx { block * this->block_size }; 
    memcpy(this->disk_array.at(disk).get() + start_byte_idx, buf, this->block_size); 
}