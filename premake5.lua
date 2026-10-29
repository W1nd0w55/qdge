local vcpkgRoot = os.getenv("VCPKG_ROOT")

local function getVcpkgTriplet()
	if os.istarget("windows") then
		if _OPTIONS["architecture"] == "x86" then
			return "x86-windows"
		else
			return "x64-windows"
		end
	elseif os.istarget("linux") then
		return "x64-linux"
	elseif os.istarget("macosx") then
		return "x64-osx"
	end
end

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
			"%{prj.location}/Source/**.hpp",
			"%{prj.location}/qdgeCore.hpp"
		}
		includedirs {
			"%{prj.location}/Source",
			vcpkgRoot .. "/installed/" .. getVcpkgTriplet() .. "/include" 
		}

		libdirs {
			vcpkgRoot .. "/installed/" .. getVcpkgTriplet() .. "/lib" 
		}

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
			"%{wks.location}/qdgeCore"
		}

		pchsource "%{prj.location}/Source/pch.cpp"
		pchheader "pch.hpp"
	
		systemversion "latest"

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

		links "qdgeCore"

		pchsource "%{prj.location}/Source/pch.cpp"
		pchheader "pch.hpp"

		filter "system:windows"
			links "Win32Runtime"

		systemversion "latest"

		filter "configurations:Debug"
			symbols "On"
	
		filter "configurations:Testing"
			optimize "On"
	
		filter "configurations:Release"
			optimize "On"
