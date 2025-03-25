file(GLOB_RECURSE src "Source/*" "Headers/*")

add_library(qdge SHARED "${src}")
target_include_directories(qdge PUBLIC "Headers/")
target_compile_definitions(qdge PRIVATE QDGE_BUILD)
target_precompile_headers(qdge PUBLIC "Headers/pch.h")

if(WIN32)
	target_compile_definitions(qdge PUBLIC QDGE_WINDOWS)
endif()

set_target_properties(qdge PROPERTIES FOLDER "Core")
