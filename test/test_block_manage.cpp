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
        BOOST_CHECK_EQUAL(sizeof(char), 1); 
        BOOST_CHECK_EQUAL(sizeof(int), 4); 
        BOOST_CHECK_EQUAL(sizeof(uint64_t), 8); 
        BOOST_CHECK_EQUAL(sizeof(ramfs::fat_item_t), 16); 
        BOOST_CHECK_EQUAL(sizeof(ramfs::dat_item_t), 64); 

        /**
         * @brief Check init()
         *        - Initial FAT
         *        - Initial DAT
         */
        disk->init(); 

        
        /**
         * @brief Test block allocate
         */
        int bd1 = disk->balloc(3); 
        int bd2 = disk->balloc(1); 
        int bd3 = disk->balloc(4); 

        /**
         * @brief Test block free
         */
        disk->bfree(bd2); 
        disk->bfree(bd3); 
        disk->bfree(bd1); 

        std::cout << std::endl; 

    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}


