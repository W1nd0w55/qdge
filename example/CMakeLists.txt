add_executable(qdgeGame "main.cpp")
target_link_libraries(qdgeGame PRIVATE "qdge")

set_target_properties(qdge PROPERTIES CMAKE_BINARY_DIR "build/")
