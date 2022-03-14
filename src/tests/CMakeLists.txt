# Function for making tests
function(make_test name)
    # Add executable target
    add_executable(
        ${name}
        ${ARGN}
    )

    # Set the header files directory
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

    # Link libraries
    target_link_libraries(${name} PRIVATE sodium)
    target_link_libraries(${name} PRIVATE magic)
    
    # Add test
    add_test(
        NAME ${name}
        COMMAND ${name}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/workdir
    )
endfunction()

# Test list
make_test(
    test_hash
    ${CMAKE_CURRENT_SOURCE_DIR}/test_hash.c
)
