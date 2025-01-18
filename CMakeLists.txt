cmake_minimum_required(VERSION 3.20)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/toolchain/clang.cmake)

add_definitions(-DPY32F030x8 -DDebugLog)

add_compile_options(--target=armv6m-none-eabi -march=armv6m -mfpu=none
                    -fno-exceptions -fno-rtti)

add_link_options(
  --target=armv6m-none-eabi -T ${CMAKE_SOURCE_DIR}/linker/standalone.ld
  -lcrt0-semihost -lsemihost -nostartfiles)

include_directories(/usr/arm-none-eabi/include)

add_subdirectory(lib)
add_subdirectory(examples)

# set the project name
project(demo)

# add the executable
add_executable(demo src/main.c startup/cortex-m.c src/system_py32f0xx.c)

target_link_libraries(${PROJECT_NAME} PRIVATE HAL RTT CONFIG)
