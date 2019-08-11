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

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "WOLF_HAZEL/vendor/GLFW/include"
IncludeDir["Glad"] = "WOLF_HAZEL/vendor/Glad/include"
IncludeDir["ImGui"] = "WOLF_HAZEL/vendor/imgui"
IncludeDir["glm"] = "WOLF_HAZEL/vendor/glm"

group "Dependencies"
	include "WOLF_HAZEL/vendor/GLFW"
	include "WOLF_HAZEL/vendor/Glad"
	include "WOLF_HAZEL/vendor/imgui"

group ""

project "WOLF_HAZEL"
	location "WOLF_HAZEL"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "WHpch.h"
	pchsource "WOLF_HAZEL/src/WHpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
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
		"WOLF_HAZEL/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"WOLF_WOLF_HAZEL"
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