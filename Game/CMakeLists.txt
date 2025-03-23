file(GLOB_RECURSE src "Source/*" "Headers/*")

add_executable(Game "${src}")
target_include_directories(Game PRIVATE "Headers/")

target_link_libraries(Game PRIVATE qdge)
target_link_libraries(Game PRIVATE qdgeRuntime)
