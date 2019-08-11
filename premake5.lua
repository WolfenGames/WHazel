workspace "WOLF_HAZEL"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}

group "Dependencies"
	include "WOLF_HAZEL/vendor/Glad"

group ""

project "WOLF_HAZEL"
	location "WOLF_HAZEL"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"WH_PLATFORM_WINDOWS",
			"WH_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "WH_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "WH_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "WH_DIST"
		runtime "Release"
		optimize "on"

	project "Sandbox"
		location "Sandbox"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs
		{
			"WOLF_HAZEL/vendor/spdlog/include",
			"WOLF_HAZEL/src",
			"WOLF_HAZEL/vendor"
		}

		links
		{
			"WOLF_HAZEL"
		}

		filter "system:windows"
			systemversion "latest"

			defines
			{
				"WH_PLATFORM_WINDOWS"
			}

		filter "configurations:Debug"
			defines "WH_DEBUG"
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines "WH_RELEASE"
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines "WH_DIST"
			runtime "Release"
			optimize "on"