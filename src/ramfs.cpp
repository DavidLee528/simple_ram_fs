#include "disk.hpp"
#include "terminal_io.hpp"

int main(int argc, const char **argv) {
    // try to initial system
    try {
        VDisk disk; 
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return -1; 
    }
     
    return 0; 
}