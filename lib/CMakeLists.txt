cmake_minimum_required(VERSION 3.20)

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
