#define BOOST_TEST_MODULE FILE_MANAGE_TEST
#include <boost/test/unit_test.hpp>

#include "definations.hpp"
#include "terminal_io.hpp"
#include "disk.hpp"
#include "block_io.hpp"
#include "file_manage.hpp"

BOOST_AUTO_TEST_CASE(PassTest) {
    try {
        FileManage *disk = new FileManage("debug"); 

        


    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl; 
    }

}


