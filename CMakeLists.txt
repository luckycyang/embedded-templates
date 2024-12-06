cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(CMAKE_TOOLCHAIN_FILE ./toolchain/gcc.cmake)

# set the project name
project(demo)

# add the executable
add_executable(demo src/main.c startup/cortex-m.c)

target_compile_options(
  ${PROJECT_NAME} PRIVATE -mcpu=cortex-m3 -mthumb $<$<CONFIG:Debug>:-g>
                          $<$<CONFIG:Release>:-O3>)

target_link_options(${PROJECT_NAME} PRIVATE -mcpu=cortex-m3 -mthumb -T
                    ${PROJECT_SOURCE_DIR}/linker/standalone.ld)
