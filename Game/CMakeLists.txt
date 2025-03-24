file(GLOB_RECURSE src "Source/*" "Headers/*")

add_executable(Game WIN32 "${src}")
target_include_directories(Game PRIVATE "Headers/")

target_link_libraries(Game PRIVATE qdge)
target_link_libraries(Game PRIVATE qdgeRuntime)

set_target_properties(Game PROPERTIES FOLDER "App")
