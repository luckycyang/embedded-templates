cmake_minimum_required(VERSION 3.10)
# set(CMAKE_EXPORT_COMPILE_COMMANDS true) set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_TOOLCHAIN_FILE ../toolchain/gcc.cmake)

add_compile_options(-nostdlib)
add_link_options(-T ../linker/standalone.ld)

project(cmsis_device)
add_executable(cmsis_device ./cmsis_device.c ../startup/cortex-m.c)
target_link_libraries(cmsis_device PRIVATE CMSIS Device)
