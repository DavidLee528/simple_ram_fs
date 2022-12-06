find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK) 
include_directories(${PROJECT_SOURCE_DIR}/include)
add_compile_options(-g)

set(source_list 
    ${PROJECT_SOURCE_DIR}/src/disk.cpp
    ${PROJECT_SOURCE_DIR}/src/block_io.cpp
    ${PROJECT_SOURCE_DIR}/src/block_manage.cpp
    ${PROJECT_SOURCE_DIR}/src/file_manage.cpp
    ${PROJECT_SOURCE_DIR}/src/terminal_io.cpp
)

add_executable(test_disk test_disk.cpp ${source_list}) 
add_executable(test_block_io test_block_io.cpp ${source_list}) 
add_executable(test_block_manage test_block_manage.cpp ${source_list}) 
add_executable(test_file_manage test_file_manage.cpp ${source_list}) 
add_executable(test_applications test_applications.cpp ${source_list}) 

target_link_libraries(test_disk
                      ${Boost_FILESYSTEM_LIBRARY}
                      ${Boost_SYSTEM_LIBRARY}
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                      libfmt.a
                      )
target_link_libraries(test_block_io
                      ${Boost_FILESYSTEM_LIBRARY}
                      ${Boost_SYSTEM_LIBRARY}
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                      libfmt.a
                      )
target_link_libraries(test_block_manage
                      ${Boost_FILESYSTEM_LIBRARY}
                      ${Boost_SYSTEM_LIBRARY}
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                      libfmt.a
                      )
target_link_libraries(test_file_manage
                      ${Boost_FILESYSTEM_LIBRARY}
                      ${Boost_SYSTEM_LIBRARY}
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                      libfmt.a
                      )
target_link_libraries(test_applications
                      ${Boost_FILESYSTEM_LIBRARY}
                      ${Boost_SYSTEM_LIBRARY}
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                      libfmt.a
                      )

enable_testing()
add_test(DISK_TEST test_disk)
add_test(BLOCK_IO_TEST test_block_io)
add_test(BLOCK_MANAGE_TEST test_block_manage)
add_test(FILE_MANAGE_TEST test_file_manage)
add_test(APPLICATIONS_TEST test_applications)