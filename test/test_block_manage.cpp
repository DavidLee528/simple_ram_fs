#define BOOST_TEST_MODULE BLOCK_MANAGE_TEST
#include <boost/test/unit_test.hpp>

#include "definations.hpp"
#include "terminal_io.hpp"
#include "disk.hpp"
#include "block_io.hpp"
#include "block_manage.hpp"

BOOST_AUTO_TEST_CASE(PassTest) {
    try {
        /**
         * @brief turn on the debug mode when construct
         */
        BlockManage *disk = new BlockManage("debug"); 
        
        /**
         * @brief Type check
         */
        BOOST_CHECK_EQUAL(sizeof(ramfs::fat_item_t), sizeof(int) * 4); 
        BOOST_CHECK_EQUAL(sizeof(ramfs::dat_item_t), sizeof(char) * 32 + sizeof(int) + sizeof(uint16_t)); 



    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}


