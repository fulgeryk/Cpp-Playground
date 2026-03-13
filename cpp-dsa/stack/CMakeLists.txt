cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE "D:/vcpkg/scripts/buildsystems/vcpkg.cmake"
	CACHE STRING "Vcpkg toolchain file")

project(cpp_stack)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp_stack
	src/stack.cpp
)

find_package(fmt CONFIG REQUIRED)

target_link_libraries(cpp_stack PRIVATE fmt::fmt)