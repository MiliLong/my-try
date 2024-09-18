source_dir = .
build_dir = ${source_dir}/build

all:
	cmake -G "Ninja" \
	-DCMAKE_C_COMPILER=cl \
	-DCMAKE_CXX_COMPILER=cl \
	-S ${source_dir} -B ${build_dir}

	ninja -C build
	
	cd ${source_dir} & python tests/test.py
