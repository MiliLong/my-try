source_dir = .
build_dir = ${source_dir}\build

all:
	cmake -G "Ninja" \
	-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
	-DCMAKE_C_COMPILER=x86_64-w64-mingw32-gcc \
	-DCMAKE_CXX_COMPILER=x86_64-w64-mingw32-g++ \
	-S ${source_dir} -B ${build_dir}
	
	ninja -C ${build_dir} 
	
	python src/test.py
