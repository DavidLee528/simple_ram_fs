#ifndef _BLOCK_MANAGE_HPP_
#define _BLOCK_MANAGE_HPP_

#include "block_io.hpp"
#include "definations.hpp"

#include <algorithm>
#include <boost/property_tree/ptree.hpp>
#include <vector>

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

    /**
     * @brief make a new directory
     * 
     * @param dirname new directory base on |path|
     * @param path current exist path (e.g. $/root/dev)
     */
    void make_dir(const std::string &dirname, const std::string &path); 

    // not test
    void remove_dir(const std::string &dirname, const std::string &path); 

    /**
     * @brief log new file to directory tree
     * 
     * @param filename 
     * @param path the path must exists (e.g. $/wgssb)
     */
    int log_file(const std::string &filename, const std::string &path, size_t block_amount = 2); 

    /**
     * @brief unlog_file
     * 
     * @param filename 
     * @param path the path must exists (e.g. $/wgssb)
     */
    void unlog_file(const std::string &filename, const std::string &path); 

    void dump(); 

public: 

    /**
     * @brief directory
     * template: <path, vector<index of FAT>>
     */
    boost::property_tree::basic_ptree<std::string, std::vector<int>> pt { }; 


    std::map<std::string, int> filename_to_bd { }; 
    std::map<int, std::string> bd_to_filename { }; 
}; 

#endif /* _BLOCK_MANAGE_HPP_ */