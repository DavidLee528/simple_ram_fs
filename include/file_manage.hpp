#ifndef _FILE_MANAGE_HPP_
#define _FILE_MANAGE_HPP_ 1

#include "block_manage.hpp"
#include "definations.hpp"

#include <string>
#include <map>

class FileManage: public BlockManage {
public: 
    using BlockManage::BlockManage; 

public: 
    int make_file(const std::string &name, const std::string &path) {
        // calculate how many block(s) to be allocate
        // default value is 2
        size_t block_amount { ramfs::file_init_size / this->block_size }; 

        // add to directory
        // get block descriptor
        int bd { this->log_file(name, path, block_amount) }; 

        // return block descriptor
        return bd; 
    }

    int remove_file(const std::string &name, const std::string &path) {
        this->unlog_file(name, path); 
    }

    int modify_file(const std::string &name, const std::string &path, const std::string &content) {

    }

    std::string get_file(const std::string &name, const std::string &path) {

    }

    std::string indent(int level) {
        std::string s; 
        for (int i = 0; i < level; ++i) s += "  ";
        return s; 
    } 

    void printTree(boost::property_tree::basic_ptree<std::string, std::vector<int>> &pt, int level) {
        if (pt.empty()) {
            // std::cerr << "\"" << pt.data() << "\"";
            for (const auto & elem : pt.data()) std::cerr << "\"" << this->bd_to_filename[elem] << "\""; 
        } else {
            if (level) std::cerr << std::endl; 

            std::cerr << indent(level) << "{" << std::endl;         

            for (boost::property_tree::basic_ptree<std::string, std::vector<int>>::iterator pos = pt.begin(); pos != pt.end();) {
            std::cerr << indent(level + 1) << "\"" << pos->first << "\": "; 

            printTree(pos->second, level + 1); 
            ++pos; 
            if (pos != pt.end()) {
                std::cerr << ","; 
            }
            std::cerr << std::endl;
        } 

        std::cerr << indent(level) << " }";     
        }

    return; 
    }


// private: 
    // std::vector<std::pair<std::string, std::string>> data { };  // <filename, <idx, content>>
    std::map<std::string, std::pair<int, std::string>> data { }; 
    int curr_idx { }; 
}; 

#endif /* _BLOCK_MANAGE_HPP_ */