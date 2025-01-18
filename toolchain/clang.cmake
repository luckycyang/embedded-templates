set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(TOOLCHAIN_PREFIX $ENV{CLANG_EMBEDDED_PATH})

set(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}clang)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}clang++)
set(CMAKE_OBJCOPY ${TOOLCHAIN_PREFIX}llvm-objcopy)
set(CMAKE_SIZE ${TOOLCHAIN_PREFIX}llvm-size)

set(CMAKE_EXECUTABLE_SUFFIX_ASM ".elf")
set(CMAKE_EXECUTABLE_SUFFIX_C ".elf")
set(CMAKE_EXECUTABLE_SUFFIX_CXX ".elf")

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
