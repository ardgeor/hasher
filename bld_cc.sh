#!/bin/bash 


. ./config.sh

current_dir=${PWD}
build_dir="${build_dir}_${ABI}"
cd ${build_dir}; make; cd ${current_dir}

if [ "${ABI}" = "${ARM64}" ]
then
    path_to_exec="${build_dir}/hasher/hasher"
    fix_binary ${path_to_exec}
fi

echo -e "\n[*] Executable file generated: ${build_dir}/hasher/hasher"