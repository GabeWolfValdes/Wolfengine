workspace "Wolfen"
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
IncludeDir["GLFW"] = "Wolfen/thirdParty/GLFW/include"
IncludeDir["Glad"] = "Wolfen/thirdParty/Glad/include"
IncludeDir["glm"] = "Wolfen/thirdParty/glm/include"
--IncludeDir["maths"] = "Wolfen/src/Maths/" dont think i need this one
--IncludeDir["fbx"] = "Wolfen/thirdParty/Fbx_ImportScene"

include "Wolfen/thirdParty/GLFW"
include "Wolfen/thirdParty/Glad"
include "Wolfen/thirdParty/Fbx_ImportScene"

project "Wolfen"
	location "Wolfen"
	kind "StaticLib"
	staticruntime "On"
	systemversion = "latest"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "wfpch.h"
	pchsource "Wolfen/src/wfpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/thirdParty/spdlog/include",
		"%{prj.name}/thirdParty/SuperString/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"--,
		--"%{IncludeDir.fbx}"
	}

	links
	{
		"Glad",
		"GLFW",
		"opengl32.lib"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	filter "system:windows"	
		defines
		{
			"WF_PLATFORM_WINDOWS",
			"WF_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		--postbuildcommands
		--{
		--	("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		--}

	filter "configurations:Debug"
		defines "WF_DEBUG"
		symbols "On"
		runtime "Debug"

	filter "configurations:Release"
		defines "WF_RELEASE"
		optimize "On"
		runtime "Release"

	filter "configurations:Dist"
		defines "WF_DIST" 
		optimize "On"
		runtime "Release"

project "Sandbox"

	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++latest"
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
		"Wolfen/thirdParty/spdlog/include",
		"Wolfen/thirdParty/SuperString/include",
		"Wolfen/src",
		"Wolfen/thirdParty"
	}

	links
	{
		"Wolfen"
	}

	filter "system:windows"
	systemversion = "latest"

		defines
		{
			"WF_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "WF_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "WF_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "WF_DIST"
		optimize "On"
