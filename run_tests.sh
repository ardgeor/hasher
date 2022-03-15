#!/bin/bash 


. ./config.sh

function error() {
    echo -e "/!\\ An error occurred. Ensure the project has been built before running tests."
    exit 1
}

current_dir=${PWD}
cd ${build_dir}
[ $? -eq 0 ] || error
make test
[ $? -eq 0 ] || error
cd ${current_dir}

