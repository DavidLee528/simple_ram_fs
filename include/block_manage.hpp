#ifndef _BLOCK_MANAGE_HPP_
#define _BLOCK_MANAGE_HPP_

#include "block_io.hpp"
#include "definations.hpp"

class BlockManage: public BlockIO {
public:
    using BlockIO::BlockIO; 
public:

    /**
     * @brief Initial FAT and DAT with prototype variable
     */
    void init(); 

    /**
     * @brief Allocate space disk block
     * 
     * @param n how many block do you want?
     * @return int return -1 when no spare block 
     */
    int balloc(size_t n); 

    /**
     * @brief Release block by given index |idx|
     * 
     * @param idx the block index has been allocated
     */
    void bfree(size_t idx); 


    void log_file(const std::string &filename, const std::string &path); 
}; 

#endif /* _BLOCK_MANAGE_HPP_ */