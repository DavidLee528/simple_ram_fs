#ifndef _TERMINAL_IO_HPP_
#define _TERMINAL_IO_HPP_ 1

#include <string>
#include <fmt/color.h>

#include "ramfs.hpp"

// use for fmt::print
// $ david: ~/tmp/src/code >>> touch main.cpp
const std::string tag {"(ramfs) {}:{}>>> "}; 

void print_welcome(); 
void print_interaction_text(const std::string &username, const std::string &path); 
void print_help(); 
void print_undefined_command(const std::string &rhs); 
void print_system_basic_information(const Ramfs &rhs); 


#endif /* _TERMINAL_IO_HPP_ */