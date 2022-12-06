#define BOOST_TEST_MODULE BLOCK_IO_TEST
#include <boost/test/unit_test.hpp>

#include "definations.hpp"
#include "terminal_io.hpp"
#include "disk.hpp"
#include "block_io.hpp"

BOOST_AUTO_TEST_CASE(PassTest) {
    try {
        /**
         * @brief turn on the debug mode when construct
         */
        BlockIO *disk = new BlockIO("debug"); 
        
        /**
         * @brief Expect throw
         */
        BOOST_CHECK_THROW(disk->bread(1048576), std::invalid_argument); 
        
        /**
         * @brief Expect normal
         */
        BOOST_CHECK_NO_THROW(disk->bread(0)); 
        BOOST_CHECK_NO_THROW(disk->bread(1048575)); 

        
        ramfs::byte_t *ret0 = disk->bread(0); 
        ramfs::byte_t *ret1 = disk->bread(1); 
        ramfs::byte_t *ret2 = disk->bread(2); 
        ramfs::byte_t *ret3 = disk->bread(3); 
        ramfs::byte_t *ret1048575 = disk->bread(1048575); 
        ramfs::byte_t arr[disk->get_block_size()]; 

        /**
         * @brief Check offset of ret*, namely block size
         */
        BOOST_CHECK_EQUAL(ret1 - ret0, 0x1000); // 1000H == 4096D == BLOCK_SIZE
        BOOST_CHECK_EQUAL(ret2 - ret1, 0x1000); 
        BOOST_CHECK_EQUAL(ret3 - ret2, 0x1000); 
        BOOST_CHECK_EQUAL(ret3 - ret0, 0x3000); 
        BOOST_CHECK_EQUAL(ret1048575 - ret0, 0xFFFFF000); // last block - first block

        /**
         * @brief Check write
         */
        memset(arr, 1, disk->get_block_size()); 
        disk->bwrite(0, arr); 
        for (ramfs::block_size_t i = 0; i < disk->get_block_size(); ++i) {
            BOOST_CHECK_EQUAL(*(ret0 + i), 1); 
        }
        memset(arr, 128, disk->get_block_size()); 
        disk->bwrite(2, arr); 
        for (ramfs::block_size_t i = 0; i < disk->get_block_size(); ++i) {
            BOOST_CHECK_EQUAL(*(ret2 + i), 128); 
        }
        memset(arr, 255, disk->get_block_size()); 
        disk->bwrite(1048575, arr); 
        for (ramfs::block_size_t i = 0; i < disk->get_block_size(); ++i) {
            BOOST_CHECK_EQUAL(*ret1048575, 255); 
        }
        for (ramfs::block_size_t i = 0; i < disk->get_block_size(); ++i) {
            BOOST_CHECK_EQUAL(*ret1, 0); 
            BOOST_CHECK_EQUAL(*ret3, 0); 
        }

    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}




