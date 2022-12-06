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
    fmt::print("- ls: list files on |pwd|\n"); 
    fmt::print("- touch: create a new file on |pwd|\n"); 
    fmt::print("- mkdir: create a new directory on |pwd|\n"); 
    fmt::print("- rm: remove a exist file on |pwd|\n"); 
    fmt::print("- rmdir: remove a exist directory on |pwd|\n"); 
    fmt::print("- echo: write file\n"); 
    fmt::print("- cat: read file\n"); 
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

void print_current_work_directory(const std::string &curr_path) {
    fmt::print("{}\n", curr_path); 
}