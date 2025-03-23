file(GLOB_RECURSE src "Source/*" "Headers/*")

add_library(qdge SHARED "${src}")
target_include_directories(qdge PUBLIC "Headers/")
target_compile_definitions(qdge PRIVATE QDGE_BUILD)

if(WIN32)
	target_compile_definitions(qdge PUBLIC QDGE_WINDOWS)
endif()
