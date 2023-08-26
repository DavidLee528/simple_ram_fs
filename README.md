# NCUT OS Lab 3: File System

## 0x00 Introduction 

This is a simple in memory file system simulator. 

## 0x01 Dependencies

- [CMake](https://github.com/Kitware/CMake)
  - CMake is a cross-platform, open-source build system generator. For full documentation visit the CMake Home Page and the CMake Documentation Page. The CMake Community Wiki also references useful guides and recipes.
- [fmt](https://github.com/fmtlib/fmt)
  -  An open-source formatting library providing a fast and safe alternative to C stdio and C++ iostreams.
- [Boost](https://www.boost.org/)
  - Boost provides free peer-reviewed portable C++ source libraries.
- [tabulate]()

## 0x02 Design Architecture

- There are following concepts for the ram disk
  - block
- Architecture
  - Level 4: Application Layer
    - ls / pwd
    - rm / rmdir -> bfree()
    - touch / mkdir -> balloc()
  - Level 3: File Management Layer
    - Create file
    - Remove file
    - Read file
    - Write file
    - Modifiy file
  - Level 2: Block Management Layer
    - balloc()
    - bfree()
  - Level 1: Block I/O Layer
    - `class BlockIO: public VDisk` in file `block_io.hpp && block_io.cpp`
      - bread()
      - bwrite()
  - Level 0: Abstract In-memory Disk Layer
    - `class VDisk` in file `disk.hpp && disk.cpp`
      - virtual_disk_create()
      - virtual_disk_open()
      - virtual_disk_close()

## 0x03 Usage

1. Compile
2. Edit configuration file
3. Run simulator

## 0x04 Original Statement

I sincerely promise that: 

- I have done the entire program, from problem analysis, top-level design, to code implement by **MYSELF**. 
- If i encountered any difficulties in the above process and i asked fro advice, i will include in my lab report a detailed list. 
- Where i referenced other program of documents in my programs, i have clearly indicated the source of reference. 
- I have never written this program with the intention of disrupting or impeding the proper functioning of other computer system. 

## 0x05 Reference

- https://fmt.dev/latest/api.html

## 006F About Author

- Tianhao Li
- Information Security 20-2
- litianhao.life
- davidlee0x01@proton.me
