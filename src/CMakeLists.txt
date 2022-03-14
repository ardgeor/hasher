cmake_minimum_required(VERSION 3.5)
project(Hasher 
    VERSION 0.0.1
    DESCRIPTION "Cross-platform program exercise")

set(DISABLE_TESTS OFF)

add_subdirectory(hasher) 

if(NOT DISABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
                    