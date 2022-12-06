#include "block_io.hpp"

ramfs::block_t BlockIO::bread(ramfs::block_size_t block, ramfs::disk_amount_t disk) {
    // Index of start byte of block to read
    ramfs::byte_t start_byte_idx = block * this->block_size; 
    
    ramfs::block_t buffer {}; 
    for (ramfs::byte_t i = 0; i < this->block_size; ++i) {
        buffer.bvec.push_back(*(this->disk_array.at(disk).get() + start_byte_idx + i)); 
    }
    buffer.bvec.shrink_to_fit(); 

    return buffer; 
}

int BlockIO::bwrite(ramfs::block_size_t block, const void *buf, ramfs::disk_amount_t disk) {

}