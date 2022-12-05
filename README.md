# NCUT OS Lab 3: File System

## 0x00 Overall 

This is a simple in memory file system simulator. 

## 0x01 Dependencies

- [CMake](https://github.com/Kitware/CMake)
  - CMake is a cross-platform, open-source build system generator. For full documentation visit the CMake Home Page and the CMake Documentation Page. The CMake Community Wiki also references useful guides and recipes.
- [fmt](https://github.com/fmtlib/fmt)
  -  An open-source formatting library providing a fast and safe alternative to C stdio and C++ iostreams.
- [Boost](https://www.boost.org/)
  - Boost provides free peer-reviewed portable C++ source libraries.

## 0x02 Project Structure

## 0x03 Design Architecture

- There are following concepts for the ram disk
  - block
- Architecture
  - Level 3: Application Layer
    - ls / pwd
    - rm / rmdir -> bfree()
    - touch / mkdir -> balloc()
  - Level 2: Block Management Layer
    - balloc()
    - bfree()
  - Level 1: Block I/O Layer
    - bread()
    - bwrite()

## 0x04 Usage

1. Compile
2. Edit configuration file
3. Run simulator

## 0xFD Original Statement

I sincerely promise that: 

- I have done the entire program, from problem analysis, top-level design, to code implement by **MYSELF**. 
- If i encountered any difficulties in the above process and i asked fro advice, i will include in my lab report a detailed list. 
- Where i referenced other program of documents in my programs, i have clearly indicated the source of reference. 
- I have never written this program with the intention of disrupting or impeding the proper functioning of other computer system. 

## 0xFE Reference

- https://fmt.dev/latest/api.html

## 0xFF About Author

- Tianhao Lee
- Information Security 20-2
- 20101110201
- 13121515269@163.com