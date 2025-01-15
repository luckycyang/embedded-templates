all: build
build:
	cmake -Bbuild -GNinja
	ninja -C build

clean:
	rm -rf build


flash:
	probe-rs download build/demo.elf --chip PY32F002Bx5

run:
	probe-rs run build/demo.elf --chip PY32F002Bx5


