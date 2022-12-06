#ifndef _BLOCK_MANAGE_HPP_
#define _BLOCK_MANAGE_HPP_

#include "block_io.hpp"
#include "definations.hpp"

class BlockManage: public BlockIO {
public:
    using BlockIO::BlockIO; 
public:

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
}; 

#endif /* _BLOCK_MANAGE_HPP_ */