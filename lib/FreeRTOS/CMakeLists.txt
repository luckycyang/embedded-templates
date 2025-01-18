project(FreeRTOS)
add_library(FreeRTOS)

file(GLOB FreeRTOS_SOURCES src/*.c portable/GCC/ARM_CM0/*.c)

target_sources(FreeRTOS PRIVATE ${FreeRTOS_SOURCES} portable/MemMang/heap_2.c)
target_include_directories(FreeRTOS PUBLIC inc portable/GCC/ARM_CM0)
target_link_libraries(FreeRTOS PUBLIC CONFIG)
