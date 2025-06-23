cmake_minimum_required(VERSION 3.25)
project(qdge CXX)

option(qdgeSharedLib "Build qdge as a shadred library" OFF)

file(GLOB_RECURSE src
    "com/*"
    "net/*"
    "enduser/*"
)

if(qdgeSharedLib)
    add_library(qdge SHARED "${src}")
    target_compile_definitions(qdge PUBLIC QDGE_SHARED_LIB)
else()
    add_library(qdge STATIC "${src}")
endif()

target_include_directories(qdge PUBLIC "com/" "net/" "enduser/" "enduser/include/")

target_compile_definitions(qdge PRIVATE QDGE_BUILD)

target_compile_definitions(qdge PUBLIC
    "$<$<CONFIG:Debug>:QDGE_DEV>"
    "$<$<CONFIG:Release>:QDGE_RELEASE>"
    "$<$<CONFIG:RelWithDebInfo>:QDGE_TESTING>"
    "$<$<CONFIG:MinSizeRel>:QDGE_MINIMAL>"
)

if(WIN32)
    target_compile_definitions(qdge PUBLIC QDGE_OS_WINDOWS)
elseif(LINUX)
    target_compile_definitions(qdge PUBLIC QDGE_OS_LINUX)
endif()

add_subdirectory("example")

# Libraries
add_subdirectory("lib/spdlog")
target_link_libraries(qdge PUBLIC "spdlog")
