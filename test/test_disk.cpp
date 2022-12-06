#define BOOST_TEST_MODULE DISK_TEST
#include <boost/test/unit_test.hpp>

#include "definations.hpp"
#include "terminal_io.hpp"
#include "disk.hpp"
#include "block_io.hpp"

#include <algorithm>

/**
 * @brief Construct a new boost auto test case object
 *        ALL TEST DATA SHOULD BE CONSISTENT WITH |ramfs.conf|
 */
BOOST_AUTO_TEST_CASE(PassTest) {
    try {
        /**
         * @brief turn on the debug mode when construct
         */
        VDisk disk("debug"); 

        /**
         * @brief check size of single block
         */
        BOOST_CHECK_EQUAL(disk.get_block_size(), 4096); 
        
        /**
         * @brief check size of total disk
         */
        BOOST_CHECK_EQUAL(disk.get_disk_size(), 4294967296); 

        /**
         * @brief check amount of disk, when RAID=OFF in ramfs.conf, 
         *        the amount should be 1
         */
        BOOST_CHECK_EQUAL(disk.get_disk_amount(), 1); 

        /**
         * @brief check the member variable disk_array
         */
        BOOST_CHECK_EQUAL(disk.get_disk_array().size(), disk.get_disk_amount()); 

        /**
         * @brief check memset for each virtual disk
         */
        const ramfs::byte_t byte_zero {static_cast<ramfs::byte_t>(0)}; 
        for (ramfs::disk_amount_t i = 0; i < disk.get_disk_amount(); ++i) {
            BOOST_CHECK_EQUAL(*(disk.get_disk_array().at(i).get() + 0), byte_zero); 
            BOOST_CHECK_EQUAL(*(disk.get_disk_array().at(i).get() + disk.get_disk_size() - 1), byte_zero); 
        }
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    
}


