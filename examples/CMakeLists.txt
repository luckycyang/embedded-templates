project(cmsis_device)
add_executable(cmsis_device ./cmsis_device.c ../startup/cortex-m.c)
target_link_libraries(cmsis_device PRIVATE CMSIS Device)

project(justprint)
add_executable(justprint ./justprint.c ../startup/cortex-m.c)
target_link_directories(justprint PRIVATE /usr/arm-none-eabi/lib)
target_link_libraries(justprint PRIVATE RTT gcc m c rdimon)
target_include_directories(justprint PRIVATE /usr/arm-none-eabi/include)
