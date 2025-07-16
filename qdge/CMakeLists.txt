file(GLOB_RECURSE src
	"${CMAKE_CURRENT_SOURCE_DIR}/*"
)

if(qdgeSharedLib)
	add_library(qdge SHARED "${src}")
	target_compile_definitions(qdge PUBLIC QDGE_SHARED_LIB)
else()
	add_library(qdge STATIC "${src}")
endif()

target_include_directories(qdge PUBLIC "Source/" "include/")

target_compile_definitions(qdge PRIVATE QDGE_BUILD)

target_compile_definitions(qdge PUBLIC
	"$<$<CONFIG:Debug>:QDGE_DEV>"
	"$<$<CONFIG:Release>:QDGE_RELEASE>"
	"$<$<CONFIG:RelWithDebInfo>:QDGE_TESTING>"
	"$<$<CONFIG:MinSizeRel>:QDGE_MINIMAL>"
)

target_precompile_headers(qdge PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Source/pch.hpp")

if(WIN32)
	target_compile_definitions(qdge PUBLIC QDGE_OS_WINDOWS)
elseif(APPLE)
	target_compile_definitions(qdge PUBLIC QDGE_OS_MAC)
elseif(LINUX)
	target_compile_definitions(qdge PUBLIC QDGE_OS_LINUX)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	target_compile_definitions(qdge PUBLIC QDGE_COMPILER=0)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	target_compile_definitions(qdge PUBLIC QDGE_COMPILER=1)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	target_compile_definitions(qdge PUBLIC QDGE_COMPILER=2)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
	target_compile_definitions(qdge PUBLIC QDGE_COMPILER=3)
endif()

set_target_properties(qdge PROPERTIES FOLDER "Core")

GroupSourcesByFolder(qdge)
