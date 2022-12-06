#include "terminal_io.hpp"

void print_welcome() {
    system("clear"); 
    fmt::print("Welcome to in memory file system simulator (Author: Tianhao Lee 20101110201)\n\n"); 
}

void print_interaction_text(const std::string &username, const std::string &path) {
    fmt::print(fmt::emphasis::italic, "(ramfs) "); 
    fmt::print(fg(fmt::color::aquamarine), "{}", username); 
    fmt::print(":"); 
    fmt::print(fg(fmt::color::aquamarine), "{}", path); 
    fmt::print(" >>> "); 
}

void print_help() {
    fmt::print("- sbi: show basic info\n"); 
    fmt::print("- pwd: print work directory\n"); 
    fmt::print("- ls\n"); 
    fmt::print("- touch\n"); 
    fmt::print("- mkdir\n"); 
    fmt::print("- rm\n"); 
    fmt::print("- rmdir\n"); 
}

void print_undefined_command(const std::string &rhs) {
    fmt::print("Undefine command detected: "); 
    fmt::print(fg(fmt::color::red), "{}\n", rhs); 
}

void print_system_basic_information(const VDisk &rhs) {
    fmt::print("- Block size:\t{} Bytes\n", rhs.get_block_size()); 
    fmt::print("- Disk size:\t{} Bytes\n", rhs.get_disk_size()); 
    fmt::print("- Disk amount:\t{}\n", rhs.get_disk_amount()); 
}