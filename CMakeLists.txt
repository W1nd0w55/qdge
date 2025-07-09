cmake_minimum_required(VERSION 3.25)
project(qdge CXX)

set(CMAKE_CXX_STANDARD 20)

option(qdgeSharedLib "Build qdge as a shared library" ON)
option(includeExample "Build the example game" ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")

add_subdirectory("qdge")

if(includeExample)
    add_subdirectory("Example")
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "Utilities")

# Libraries
add_subdirectory("Dependencies/spdlog")
target_link_libraries(qdge PUBLIC "spdlog")
set_target_properties(spdlog PROPERTIES FOLDER "Dependencies")
