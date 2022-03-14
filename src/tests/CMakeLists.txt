message(STATUS "testing!")
set(name "test_hash")

# Add executable target
add_executable(${name} tests.c)

# Set the header files directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

# # Set static linking
# SET(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
# SET(CMAKE_EXE_LINKER_FLAGS "-static")
# SET_TARGET_PROPERTIES(tests PROPERTIES LINK_SEARCH_END_STATIC 1)


target_link_libraries(${name} PRIVATE sodium)



add_test(
    NAME ${name}
    COMMAND ${name}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/workdir
)