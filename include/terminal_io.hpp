#ifndef _TERMINAL_IO_HPP_
#define _TERMINAL_IO_HPP_ 1

#include <string>
#include <fmt/color.h>
#include <fmt/chrono.h>
#include <fmt/format.h>

#include "disk.hpp"
#include "file_manage.hpp"
#include "table.hpp"
#include "font_align.hpp"
#include "color.hpp"

// use for fmt::print
// $ david: ~/tmp/src/code >>> touch main.cpp
const std::string tag {"(ramfs) {}:{}>>> "}; 

void print_welcome(); 
void print_interaction_text(const std::string &username, const std::string &path); 
void print_help(); 
void print_undefined_command(const std::string &rhs); 
void print_system_basic_information(const VDisk &rhs); 
void print_current_work_directory(const std::string &curr_path); 
void make_directory(const std::string &dirname, const std::string &curr_path); 
void make_file(FileManage *t, const std::string &dirname, const std::string &curr_path); 
void cat_file(FileManage *t, const std::string &filename, const std::string &curr_path); 
void alter_file(FileManage *t, const std::string &filename, const std::string &curr_path); 
void list_file(FileManage *t); 
void print_tree(FileManage t); 
void print_bit_map(FileManage t); 

void init_interactive_system(FileManage *t); 

#endif /* _TERMINAL_IO_HPP_ */