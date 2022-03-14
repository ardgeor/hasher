#!/bin/bash 


. ./config.sh

current_dir=${PWD}
rm -rf ${build_dir}/*
cmake -S ${source_dir} -B ${build_dir} 
cd ${build_dir}; make; cd ${current_dir}
