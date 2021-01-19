workspace "Wolfen"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Wolfen"
	location "Wolfen"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/thirdparty/spdlog/include",
		"%{prj.name}/thirdparty/SuperString/include"
	}

	filter "system:windows"	
		staticruntime "On"
		systemversion = "latest"

		defines
		{
			"WF_PLATFORM_WINDOWS",
			"WF_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
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

project "Sandbox"

	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Wolfen/thirdparty/spdlog/include",
		"Wolfen/thirdparty/SuperString/include",
		"Wolfen/src"
	}

	links
	{
		"Wolfen"
	}

	filter "system:windows"
		staticruntime "On"
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
