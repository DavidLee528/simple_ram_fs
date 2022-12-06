add_compile_options(-g)

add_executable(ramfs ramfs.cpp disk.cpp block_io.cpp block_manage.cpp file_manage.cpp terminal_io.cpp)

target_link_libraries(ramfs libfmt.a)
# target_link_libraries(ramfs libboost_stacktrace_backtrace.a)