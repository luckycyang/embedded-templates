cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_TOOLCHAIN_FILE ./toolchain/gcc.cmake)

add_definitions(-DPY32F030x8)
add_compile_options(-mcpu=cortex-m0plus -mthumb)

# set the project name
project(demo)

add_subdirectory(lib)
add_subdirectory(examples)

# add the executable
add_executable(demo src/main.c startup/cortex-m.c)

target_compile_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-g>
                                               $<$<CONFIG:Release>:-O3>)

target_link_options(${PROJECT_NAME} PRIVATE -T
                    ${PROJECT_SOURCE_DIR}/linker/standalone.ld)
target_link_libraries(${PROJECT_NAME} PRIVATE Device)
