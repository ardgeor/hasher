#!/bin/bash


# ------------------------
# Functions
# ------------------------
function fix_binary() {
    local path
    path="${1}"
    python3 ${bin_dir}/align_fix.py "${path}"
}


# ------------------------
# Constants
# ------------------------
export ARM64="arm64-v8a"
export x86="x86"


# ------------------------
# Configuration parameters
# ------------------------
# Generic
source_dir="src"
build_dir="build"
bin_dir="bin"

# Cross-compilation
export NDK="/home/test/Android/Sdk/ndk/23.1.7779620"
export ABI="${ARM64}"
export MIN_SDK_VERSION="29"
