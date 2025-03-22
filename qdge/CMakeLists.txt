file(GLOB_RECURSE src "Source/*" "Headers/*")

add_library(qdge SHARED "${src}")
target_include_directories(qdge PUBLIC "Headers/")
