workspace "qdge"
	configurations { "Debug", "Testing", "Release" }
	architecture "x64"
	
	outputDirFormat = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"

project "qdgeCore"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	location "qdgeCore"
	targetdir ("Binary/" .. outputDirFormat)
	objdir ("BinaryInt/" .. outputDirFormat)
	files {
		"%{prj.location}/Source/**.cpp",
		"%{prj.location}/Source/**.hpp"
	}
	includedirs "%{prj.location}/Source"
	
	systemversion "latest"

	filter "configurations:Debug"
		symbols "On"
	
	filter "configurations:Testing"
		optimize "On"
	
	filter "configurations:Release"
		optimize "On"

project "Example"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	location "Example"
	targetdir ("Binary/" .. outputDirFormat)
	objdir ("BinaryInt/" .. outputDirFormat)
	files {
		"%{prj.location}/Source/**.cpp",
		"%{prj.location}/Source/**.hpp"
	}
	includedirs {
		"%{prj.location}/Source",
		"qdgeCore"
	}

	links "qdgeCore"
	
	systemversion "latest"

	filter "configurations:Debug"
		symbols "On"
	
	filter "configurations:Testing"
		optimize "On"
	
	filter "configurations:Release"
		optimize "On"
