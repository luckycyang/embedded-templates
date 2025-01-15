all:
	build
build:
	cmake --no-warn-unused-cli -S. -Bbuild -GNinja
	cmake --build build --config Debug --target all --

clean:
  rm -rf build


flash:
	probe-rs download build/demo.elf --chip PY32F002Bx5

run:
	probe-rs run build/demo.elf --chip PY32F002Bx5


