source_dir = .
build_dir = ${source_dir}/build

all:
	cmake -G "Visual Studio 17 2022" -S ${source_dir} -B ${build_dir}
	cmake --build ./build --config Release
	cd ${source_dir} & python tests/test.py
