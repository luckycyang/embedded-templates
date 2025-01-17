cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_TOOLCHAIN_FILE ./toolchain/gcc.cmake)

add_definitions(-DPY32F030x8 -DSEGGER_RTT_MEMCPY_USE_BYTELOOP)
add_compile_options(
  -mcpu=cortex-m0plus
  -mthumb
  -mthumb-interwork
  -ffunction-sections
  -fdata-sections
  -fno-common
  -fmessage-length=0)
add_link_options(-T ${CMAKE_SOURCE_DIR}/linker/standalone.ld
                 -Wl,--print-memory-usage -Wl,--gc-sections)

# set the project name
project(demo C ASM)

add_subdirectory(lib)
add_subdirectory(examples)

# add the executable
add_executable(demo src/main.c startup/cortex-m.c)

target_compile_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-g>
                                               $<$<CONFIG:Release>:-O3>)
target_link_directories(${PROJECT_NAME} PRIVATE /usr/arm-none-eabi/lib)

target_link_libraries(${PROJECT_NAME} PRIVATE Device)
target_include_directories(${PROJECT_NAME} PRIVATE /usr/arm-none-eabi/include)
