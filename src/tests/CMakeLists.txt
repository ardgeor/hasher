function(make_test name)
    # Add executable target
    add_executable(
        ${name}
        ${ARGN}
    )

    # Set the header files directory
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

    # Link libsodium 
    target_link_libraries(${name} PRIVATE sodium)
    
    # Add test
    add_test(
        NAME ${name}
        COMMAND ${name}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/workdir
    )
endfunction()

make_test(
    test_hash
    ${CMAKE_CURRENT_SOURCE_DIR}/test_hash.c
)


# set(name "test_hash")

# # Add executable target
# add_executable(${name} test_hash.c)

# # Set the header files directory
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

# # # Set static linking
# # SET(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
# # SET(CMAKE_EXE_LINKER_FLAGS "-static")
# # SET_TARGET_PROPERTIES(tests PROPERTIES LINK_SEARCH_END_STATIC 1)


# target_link_libraries(${name} PRIVATE sodium)



# add_test(
#     NAME ${name}
#     COMMAND ${name}
#     WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/workdir
# )