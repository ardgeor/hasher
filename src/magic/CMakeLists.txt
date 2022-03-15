set(target "magic")

add_library(
    "${target}" STATIC 
    magic.c    
    util.c  
)

target_link_libraries(${target} PRIVATE sodium)

# Set the header files directory
target_include_directories("${target}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_compile_definitions("${target}" PUBLIC HASH_SIZE=32)
    # PUBLIC:       both lib and consumer receive the value
    # PRIVATE:      only lib receives the value
    # INTERFACE:    only consumer receives the value
