#ifndef _FILE_MANAGE_HPP_
#define _FILE_MANAGE_HPP_ 1

#include "block_manage.hpp"
#include "definations.hpp"

#include <string>

class FileManage: public BlockManage {
public: 
    using BlockManage::BlockManage; 

public: 
    int make_file(const std::string &name, const std::string &path) {
        // calculate how many block(s) to be allocate
        // default value is 2
        size_t block_amount { ramfs::file_init_size / this->block_size }; 

        // get block descriptor
        int bd { this->balloc(block_amount) }; 


        // add to directory


        return bd; 
    }

    int remove_file(const std::string &name, const std::string &path) {

    }

    int modify_file(const std::string &name, const std::string &path, const std::string &content) {

    }

    std::string get_file(const std::string &name, const std::string &path) {

    }


}; 

#endif /* _BLOCK_MANAGE_HPP_ */