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

		pchsource "%{prj.location}/Source/pch.cpp"
		pchheader "pch.hpp"
	
		systemversion "latest"

		filter "configurations:Debug"
			symbols "On"
	
		filter "configurations:Testing"
			optimize "On"
	
		filter "configurations:Release"
			optimize "On"

group "Platform"
if os.target() == "windows" then
	project "Win32Runtime"
		kind "StaticLib"
		language "C++"
		cppdialect "C++20"
	
		location "Platform/Win32Runtime"
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

		pchsource "%{prj.location}/Source/pch.cpp"
		pchheader "pch.hpp"
	
		systemversion "latest"
		entrypoint "wWinMainCRTStartup"

		filter "configurations:Debug"
			symbols "On"
	
		filter "configurations:Testing"
			optimize "On"
	
		filter "configurations:Release"
			optimize "On"
end
group ""

	project "Example"
		kind "WindowedApp"
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

		pchsource "%{prj.location}/Source/pch.cpp"
		pchheader "pch.hpp"

		links "qdgeCore"

		filter "system:windows"
			links "Win32Runtime"
			linkoptions "/include:wWinMain"

		systemversion "latest"

		filter "configurations:Debug"
			symbols "On"
	
		filter "configurations:Testing"
			optimize "On"
	
		filter "configurations:Release"
			optimize "On"
