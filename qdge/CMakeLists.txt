file(GLOB_RECURSE src
    "Source/*"
    "include/*"
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

if(WIN32)
    target_compile_definitions(qdge PUBLIC QDGE_OS_WINDOWS)
elseif(APPLE)
    target_compile_definitions(qdge PUBLIC QDGE_OS_MAC)
elseif(LINUX)
    target_compile_definitions(qdge PUBLIC QDGE_OS_LINUX)
endif()

set_target_properties(qdge PROPERTIES FOLDER "Core")
