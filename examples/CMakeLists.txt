
project(cmsis_device)
add_executable(cmsis_device ./cmsis_device.c ${CMAKE_SOURCE_DIR}/startup/cortex-m.c ${CMAKE_SOURCE_DIR}/src/py32f0xx_it.c ${CMAKE_SOURCE_DIR}/src/system_py32f0xx.c ${CMAKE_SOURCE_DIR}/src/py32f0xx_hal_msp.c)
target_link_libraries(cmsis_device PRIVATE  RTT CONFIG CMSIS Device HAL)



project(justprint)
add_executable(justprint ./justprint.c ${CMAKE_SOURCE_DIR}/startup/cortex-m.c ${CMAKE_SOURCE_DIR}/src/py32f0xx_it.c ${CMAKE_SOURCE_DIR}/src/system_py32f0xx.c ${CMAKE_SOURCE_DIR}/src/py32f0xx_hal_msp.c)
target_link_libraries(justprint PRIVATE  RTT CONFIG CMSIS Device HAL)



project(hal_delay)
add_executable(hal_delay ./hal_delay.c ${CMAKE_SOURCE_DIR}/startup/cortex-m.c ${CMAKE_SOURCE_DIR}/src/py32f0xx_it.c ${CMAKE_SOURCE_DIR}/src/system_py32f0xx.c ${CMAKE_SOURCE_DIR}/src/py32f0xx_hal_msp.c)
target_link_libraries(hal_delay PRIVATE  RTT CONFIG CMSIS Device HAL)



project(hal_gpio)
add_executable(hal_gpio ./hal_gpio.c ${CMAKE_SOURCE_DIR}/startup/cortex-m.c ${CMAKE_SOURCE_DIR}/src/py32f0xx_it.c ${CMAKE_SOURCE_DIR}/src/system_py32f0xx.c ${CMAKE_SOURCE_DIR}/src/py32f0xx_hal_msp.c)
target_link_libraries(hal_gpio PRIVATE  RTT CONFIG CMSIS Device HAL)



project(exti_key)
add_executable(exti_key ./exti_key.c ${CMAKE_SOURCE_DIR}/startup/cortex-m.c ${CMAKE_SOURCE_DIR}/src/py32f0xx_it.c ${CMAKE_SOURCE_DIR}/src/system_py32f0xx.c ${CMAKE_SOURCE_DIR}/src/py32f0xx_hal_msp.c)
target_link_libraries(exti_key PRIVATE  RTT CONFIG CMSIS Device HAL)



project(freertos_hello)
add_executable(freertos_hello ./freertos_hello.c ${CMAKE_SOURCE_DIR}/startup/cortex-m.c ${CMAKE_SOURCE_DIR}/src/py32f0xx_it.c ${CMAKE_SOURCE_DIR}/src/system_py32f0xx.c ${CMAKE_SOURCE_DIR}/src/py32f0xx_hal_msp.c)
target_link_libraries(freertos_hello PRIVATE FreeRTOS RTT CONFIG CMSIS Device HAL)


