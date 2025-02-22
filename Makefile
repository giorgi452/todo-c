all:
	rm -rf build
	cmake -B build
	cmake --build build
	cmake --build build --target package
