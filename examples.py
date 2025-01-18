lists = []
raw = ""
def generate_cmake(project_name, source_files, libraries):
    cmake_template = f"""
project({project_name})
add_executable({project_name} {' '.join(source_files)} ${{CMAKE_SOURCE_DIR}}/startup/cortex-m.c ${{CMAKE_SOURCE_DIR}}/src/py32f0xx_it.c ${{CMAKE_SOURCE_DIR}}/src/system_py32f0xx.c ${{CMAKE_SOURCE_DIR}}/src/py32f0xx_hal_msp.c)
target_link_libraries({project_name} PRIVATE {' '.join(libraries)} RTT CONFIG CMSIS Device HAL)
"""
    return cmake_template

# 示例用法
cmsis_device_cmake = generate_cmake("cmsis_device", ["./cmsis_device.c"], [])
justprint_cmake = generate_cmake("justprint", ["./justprint.c"], [])
hal_delay = generate_cmake("hal_delay", ["./hal_delay.c"], [])
hal_gpio = generate_cmake("hal_gpio", ["./hal_gpio.c"], [])
exti_key = generate_cmake("exti_key", ["./exti_key.c"], [])
freertos_hello = generate_cmake("freertos_hello", ["./freertos_hello.c"], ["FreeRTOS"])

lists.append(cmsis_device_cmake)
lists.append(justprint_cmake)
lists.append(hal_delay)
lists.append(hal_gpio)
lists.append(exti_key)
lists.append(freertos_hello)

for i in lists:
    raw += i
    raw += "\n\n"

with open("examples/CMakeLists.txt", "w") as f:
    f.write(raw)
    print("生成CMakeLists.txt成功")
