
project(cmsis_device)
add_executable(cmsis_device ./cmsis_device.c ${CMAKE_SOURCE_DIR}/startup/cortex-m.c)
target_link_libraries(cmsis_device PRIVATE CMSIS Device)



project(justprint)
add_executable(justprint ./justprint.c ${CMAKE_SOURCE_DIR}/startup/cortex-m.c)
target_link_libraries(justprint PRIVATE RTT)


