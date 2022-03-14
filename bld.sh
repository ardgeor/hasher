#!/bin/bash 


. ./config.sh

current_dir=${PWD}
cd ${build_dir}; make; cd ${current_dir}

