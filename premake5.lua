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
			"%{prj.location}/qdgeCore/**.cpp",
			"%{prj.location}/qdgeCore/**.hpp",
			"%{prj.location}/qdgeCore.hpp"
		}
		includedirs "%{prj.location}/qdgeCore"

		pchsource "%{prj.location}/qdgeCore/pch.cpp"
		pchheader "pch.hpp"
	
		systemversion "latest"

		filter "system:windows"
			files {
				"%{prj.location}/Platform/Win32/**.cpp",
				"%{prj.location}/Platform/Win32/**.hpp"
			}
			defines "QDGE_PLATFORM_WIN32"

		filter "configurations:Debug"
			symbols "On"
	
		filter "configurations:Testing"
			optimize "On"
	
		filter "configurations:Release"
			optimize "On"

	project "Example"
		kind "WindowedApp"
		language "C++"
		cppdialect "C++20"

		location "Example"
		targetdir ("Binary/" .. outputDirFormat)
		objdir ("BinaryInt/" .. outputDirFormat)
		files {
			"%{prj.location}/Example/**.cpp",
			"%{prj.location}/Example/**.hpp"
		}
		includedirs {
			"%{prj.location}/Example",
			"qdgeCore"
		}

		pchsource "%{prj.location}/Example/pch.cpp"
		pchheader "pch.hpp"

		links "qdgeCore"

		systemversion "latest"

		filter "configurations:Debug"
			symbols "On"
	
		filter "configurations:Testing"
			optimize "On"
	
		filter "configurations:Release"
			optimize "On"
