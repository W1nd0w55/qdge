file(GLOB_RECURSE src "Source/*" "Headers/*")

add_library(qdgeRuntime STATIC "${src}")
target_include_directories(qdgeRuntime PRIVATE "../qdge/Headers/")

if(WIN32)
	target_compile_definitions(qdgeRuntime PRIVATE QDGERT_USE_WINMAIN)
endif()

set_target_properties(qdgeRuntime PROPERTIES FOLDER "Core")
