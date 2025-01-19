project(CMSIS)
add_library(CMSIS INTERFACE)
target_include_directories(CMSIS
                           INTERFACE ./PY32F0xx_Firmware/Drivers/CMSIS/Include)

project(CONFIG)
add_library(CONFIG INTERFACE)
target_include_directories(CONFIG INTERFACE ./inc)

project(Device)
add_library(
  Device STATIC
  ./PY32F0xx_Firmware/Drivers/CMSIS/Device/PY32F0xx/Source/system_py32f0xx.c)
target_include_directories(
  Device PUBLIC ./PY32F0xx_Firmware/Drivers/CMSIS/Device/PY32F0xx/Include)
target_link_libraries(Device PUBLIC CMSIS)

project(RTT)
add_library(
  RTT STATIC
  ./RTT/RTT/SEGGER_RTT.c ./RTT/RTT/SEGGER_RTT_printf.c
  ./RTT/Syscalls/SEGGER_RTT_Syscalls_GCC.c ./RTT/RTT/SEGGER_RTT_ASM_ARMv7M.S)
target_include_directories(RTT PUBLIC ./RTT/RTT)
target_link_libraries(RTT PRIVATE CONFIG)

# add_library(freertos_config INTERFACE) target_include_directories(
# freertos_config SYSTEM INTERFACE inc) # The config file directory #
# target_compile_definitions(freertos_config PUBLIC projCOVERAGE_TEST=0)
# set(FREERTOS_PORT GCC_ARM_CM0) add_subdirectory(FreeRTOS-Kernel)

file(GLOB HAL_SRC ./PY32F0xx_Firmware/Drivers/PY32F0xx_HAL_Driver/Src/*.c)
project(HAL)
add_library(HAL STATIC)
target_sources(HAL PRIVATE ${HAL_SRC})
target_include_directories(
  HAL PUBLIC ./PY32F0xx_Firmware/Drivers/PY32F0xx_HAL_Driver/Inc)
target_link_libraries(HAL PUBLIC Device CONFIG)

add_subdirectory(FreeRTOS)
