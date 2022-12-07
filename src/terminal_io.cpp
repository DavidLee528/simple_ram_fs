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

void make_directory(const std::string &dirname, const std::string &curr_path) {

}

void make_file(FileManage *t, const std::string &filename, const std::string &curr_path) {
    t->make_file(filename, curr_path); 
    t->data.insert(std::make_pair(filename, std::make_pair(t->curr_idx++, ""))); 
}

void cat_file(FileManage *t, const std::string &filename, const std::string &curr_path) {
    fmt::print("{}\n", t->data[filename].second); 
}

void alter_file(FileManage *t, const std::string &filename, const std::string &curr_path) {
    std::string content { }; 
    fmt::print("Enter file content: "); std::cin >> content; 
    t->data[filename] = std::make_pair(t->data[filename].first, content); 
    fmt::print("Updated!\n"); 
}

void list_file(FileManage *t) {
    for (const auto &elem : t->data) {
        fmt::print("{}\n", elem.first); 
    }
}

void print_tree(FileManage t) {
    t.printTree(t.pt, 0); 
}
void print_bit_map(FileManage t) {
    tabulate::Table table;
    table.add_row({"--- Bit Map ---"});
    table[0][0]
      .format()
      .font_background_color(tabulate::Color::blue)
      .font_align(tabulate::FontAlign::center);

    tabulate::Table sub_table;

    std::vector<std::pair<std::string, std::string>> tmp { }; 
    for (const auto &elem : t.data) {
        tmp.push_back(std::make_pair(elem.first, elem.second.second)); 
    }

    for (size_t i = 0; i < tmp.size(); ++i) {
        sub_table.add_row({fmt::format("{}", i), tmp.at(i).first, tmp.at(i).second});
    }

    table.add_row({sub_table}); 
    std::cout << table << std::endl;
}

void init_interactive_system(FileManage *t) {
    std::string username { }; 
    std::string password { }; 
    fmt::print("username: "); std::cin >> username; 
    fmt::print("password: "); std::cin >> password; 


    print_welcome(); 

    std::string curr_username {}; 
    std::string curr_path {}; 

    // Initial work directory
    curr_username = username; 
    curr_path = "$/" + username; 
    t->make_dir(username, curr_path); 

    while (true) {
        print_interaction_text(curr_username, curr_path); 

        std::string op {}; 
        std::getline(std::cin, op); 
        std::vector<std::string> token { }; 
        boost::split(token, op, boost::is_any_of(" "), boost::token_compress_on); 
        op = token.at(0); 

        if (op == "") continue; 
        else if (op == "help") print_help(); 
        else if (op == "sbi") print_system_basic_information(*t); 
        else if (op == "pwd") print_current_work_directory(curr_path); 
        else if (op == "mkdir") make_directory(token.at(1), curr_path); 
        else if (op == "touch") make_file(t, token.at(1), curr_path); 
        else if (op == "cat") cat_file(t, token.at(1), curr_path); 
        else if (op == "alter") alter_file(t, token.at(1), curr_path); 
        else if (op == "ls") list_file(t); 
        else if (op == "tree") print_tree(*t); 
        else if (op == "bit_map") print_bit_map(*t); 
        else if (op == "") ; 
        else print_undefined_command(op); 
    }
}