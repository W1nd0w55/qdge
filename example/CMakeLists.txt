add_executable(qdgeGame "main.cpp")
target_link_libraries(qdgeGame PRIVATE "qdge")

set_target_properties(qdgeGame PROPERTIES FOLDER "App")
