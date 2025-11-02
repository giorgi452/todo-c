win:
	rm -rf build
	cmake --build build
	cmake --build build --target package

linux: 
	rm -rf build
	cmake -B build 
	cmake --build build
	cmake --build build --target package
