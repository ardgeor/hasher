#!/bin/bash 


. ./config.sh

current_dir=${PWD}
build_dir="${build_dir}_${ABI}"
rm -rf ${build_dir}/*

cmake -S ${source_dir} -B ${build_dir} \
    -DCMAKE_TOOLCHAIN_FILE=${NDK}/build/cmake/android.toolchain.cmake \
    -DANDROID_ABI=${ABI} \
    -DANDROID_NATIVE_API_LEVEL=${MIN_SDK_VERSION}
    
cd ${build_dir}; make; cd ${current_dir}

if [ "${ABI}" = "${ARM64}" ]
then
    path_to_exec="${build_dir}/hasher/hasher"
    fix_binary ${path_to_exec}
fi

echo -e "\n[*] Executable file generated: ${build_dir}/hasher/hasher"