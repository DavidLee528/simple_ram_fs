#include "disk.hpp"
#include "terminal_io.hpp"
#include "file_manage.hpp"

int main(int argc, const char **argv) {
    // try to initial system
    try {
        FileManage *disk = new FileManage(); 
        disk->init(); 
        // init_interactive_system(disk); 
        disk->make_dir("wgssb", "$"); 
        disk->make_dir("david", "$"); 
        disk->make_dir("sub_wgssb_1", "$/wgssb"); 
        disk->make_dir("sub_wgssb_2", "$/wgssb"); 
        disk->make_dir("sub_wgssb_3", "$/wgssb"); 
        disk->make_dir("sub_wgssb_11", "$/wgssb/sub_wgssb_1"); 
        disk->make_dir("sub_wgssb_12", "$/wgssb/sub_wgssb_1"); 
        disk->make_dir("sub_wgssb_111", "$/wgssb/sub_wgssb_1/sub_wgssb_11"); 
        disk->make_dir("sub_wgssb_1111", "$/wgssb/sub_wgssb_1/sub_wgssb_11/sub_wgssb_111"); 

        disk->log_file("wgssb.y", "$/wgssb/sub_wgssb_1"); 
        disk->log_file("wgssb.yes", "$/wgssb/sub_wgssb_1/sub_wgssb_11/sub_wgssb_111/sub_wgssb_1111"); 
        disk->log_file("wgssb.yesyes", "$/wgssb/sub_wgssb_1/sub_wgssb_11/sub_wgssb_111/sub_wgssb_1111"); 
        disk->log_file("hello.txt", "$/david"); 

        disk->make_dir("test_dir", "$/david"); 


        disk->printTree(disk->pt, 0); 
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return -1; 
    }
     
    return 0; 
}