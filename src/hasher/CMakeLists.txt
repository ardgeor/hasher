# Add executable target
add_executable(hasher main.c util.c)

# Set the header files directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

# Set static linking
SET(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
SET(CMAKE_EXE_LINKER_FLAGS "-static")
SET_TARGET_PROPERTIES(hasher PROPERTIES LINK_SEARCH_END_STATIC 1)


# Integrate libsodium-cmake, to compile libsodium through cmake
include(FetchContent)

FetchContent_Declare(Sodium
    GIT_REPOSITORY https://github.com/robinlinden/libsodium-cmake.git
)
set(SODIUM_DISABLE_TESTS ON)
FetchContent_MakeAvailable(Sodium)

target_link_libraries(hasher PRIVATE sodium)