cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE "D:/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(cpp_hash_table)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp_hash_table
	src/hash-table.cpp
)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(cpp_hash_table PRIVATE fmt::fmt)