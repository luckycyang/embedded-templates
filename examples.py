lists = []
raw = ""
def generate_cmake(project_name, source_files, libraries):
    cmake_template = f"""
project({project_name})
add_executable({project_name} {' '.join(source_files)} ${{CMAKE_SOURCE_DIR}}/startup/cortex-m.c)
target_link_libraries({project_name} PRIVATE {' '.join(libraries)})
"""
    return cmake_template

# 示例用法
cmsis_device_cmake = generate_cmake("cmsis_device", ["./cmsis_device.c"], ["CMSIS", "Device"])
justprint_cmake = generate_cmake("justprint", ["./justprint.c"], ["RTT"])
hal_delay = generate_cmake("hal_delay", ["./hal_delay.c"], ["HAL", "RTT"])

lists.append(cmsis_device_cmake)
lists.append(justprint_cmake)
lists.append(hal_delay)

for i in lists:
    raw += i
    raw += "\n\n"

with open("examples/CMakeLists.txt", "w") as f:
    f.write(raw)
    print("生成CMakeLists.txt成功")
