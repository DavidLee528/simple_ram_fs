add_compile_options(-g)

add_executable(ramfs ramfs.cpp disk.cpp terminal_io.cpp)

target_link_libraries(ramfs libfmt.a)
# target_link_libraries(ramfs libboost_stacktrace_backtrace.a)