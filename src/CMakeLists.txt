cmake_minimum_required(VERSION 3.5)
project(Hasher 
    VERSION 0.0.1
    DESCRIPTION "Cross-platform program exercise")

set(ENABLE_TESTS ON)

add_subdirectory(magic)
add_subdirectory(hasher) 

if(ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
                    