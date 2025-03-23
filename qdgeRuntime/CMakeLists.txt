file(GLOB_RECURSE src "Source/*" "Headers/*")

add_library(qdgeRuntime STATIC "${src}")

target_include_directories(qdgeRuntime PRIVATE "../qdge/Headers/")
