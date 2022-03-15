# hasher
Cross-platform program exercise

[TOC]


## Description
This tool is a command-line program which performs a hash of a string given as a parameter. 

The program is written in C and it is intended to be built for x86/ARM64 Android devices/emulators. It is, hence, a cross-platform program.
The hash relies on the generic hash functionality [1] provided by the libsodium library [2].



## Build

Two build modes are supported:

* **Regular build**, which generates an executable binary to run on x86-64 Linux environments. This mode is used to run the tests.
* **Cross-compilation**, which generates an executable binary to run on x86/ARM64 Android devices or emulators.

### Regular build

The steps are enumerated below:

1. **Configuration:**

   The configuration file is `config.sh`. Nothing needs to be set for this type of build

2. **Initial build:**

   Run the following command:

   ```console
   $ ./initial_bld.sh
   ```

   This will generate the executable file `build/hasher/hasher`

3. **Subsequent builds:**

   Run the following command:

   ```console
   $ ./bld.sh
   ```

   This will generate the executable file `build/hasher/hasher` without needing to restart from scratch

### Cross-compilation for an Android device

The steps are listed below:

1. **Configuration:**

   The configuration file is `config.sh`. The path to the NDK, the ABI and the minimum version of SDK need to be specified:

   ```sh
   # Cross-compilation
   export NDK="/home/test/Android/Sdk/ndk/23.1.7779620"
   export ABI="${ARM64}"
   export MIN_SDK_VERSION="19"
   ```

2. **Initial build:**

   Run the following command:

   ```console
   $ ./initial_bld_cc.sh
   ```

   This will generate the executable file `build_${ABI}/hasher/hasher`

3. **Subsequent builds:**

   Run the following command:

   ```console
   $ ./bld_cc.sh
   ```

   This will generate the executable file `build_${ABI}/hasher/hasher` without needing to restart from scratch

**NOTE:** TLS segment underalignment might need to be corrected. It is automatized in case that it is needed.



## Testing

A battery of tests is specified in the `src/tests/CMakeLists.txt` file. Given  the scope of the exercise, only one test is implemented: `test_hash`

A list of test cases for `test_hash` is implemented in the `src/tests/test_hash.c` file. This consists of pairs of strings and their corresponding hash in hexadecimal. For each pair, the hash is computed and the output is compared with the expected hash. The hashing algorithm used in the generic hash functionality of libsodium is blake2b-256.

### Running the tests

In order to run the tests a "regular build" needs to be done before. Once this is done, the tests can be run through the `run_tests.sh` script. An example is shown below:

```console
$ ./run_tests.sh 
Running tests...
Test project /home/test/Challenge/repo/hasher/build
    Start 1: test_hash
1/1 Test #1: test_hash ........................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.02 sec
```



**Note:** Ensure that the `ENABLE_TESTS` variable is set to `ON` in the `src/CMakeLists.txt` file.



## Execution

As mentioned above, after a cross-compilation build,  an executable binary with name `hasher`  is generated in `build_${ABI}/hasher/`, as shown in the example below:

```
$ file build_arm64-v8a/hasher/hasher 
build_arm64-v8a/hasher/hasher: ELF 64-bit LSB executable, ARM aarch64, version 1 (SYSV), statically linked, with debug_info, not stripped
```

Note that the libraries are statically linked.

This binary can be pushed onto an Android device and executed from a command line:

````
bullhead:/data/local/tmp $ ./hasher              
Usage:  hasher [-i] <input string> 

options:
    -i  info

bullhead:/data/local/tmp $ ./hasher "ou yeah"
[*] hashing 'ou yeah'
'85a4a057e822f434d3d29902f56749278de7d9b0e190aa13b02b6d19ea7a9704'
````



## Credits
This software relies on the following tools :

[1] libsodium, a library for cryptography operations
    https://github.com/jedisct1/libsodium

[2] libsodium, documentation:
    https://download.libsodium.org/doc/hashing/generic_hashing

[3] align_fix.py patch for fixing TLS segment underalignment:
    https://github.com/Lzhiyong/termux-ndk/blob/master/patches/align_fix.py

[4] libsodium-cmake, a cmake wrapper for libsodium, for an easier build: 
    https://github.com/robinlinden/libsodium-cmake.git
