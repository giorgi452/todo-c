win:
	rm -rf build
	cmake -B build -DCMAKE_TOOLCHAIN_FILE=toolchain-mingw.cmake
	cmake --build build
	cmake --build build --target package

linux: 
	rm -rf build
	cmake -B build 
	cmake --build build
	cmake --build build --target package
