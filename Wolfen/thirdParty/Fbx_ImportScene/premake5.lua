project "FBXImporter"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++latest"
    staticruntime "on"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    -- CHANGE FBX HERE!!! (todo add some easier functionality to this)
    modelName = "sphere"

    debugargs { modelName .. ".fbx", modelName ..".txt" }

    debugdir "{%prj.name}/Output"


    
	files
	{
        --"%{prj.name}/**.cpp",
        --"%{prj.name}/**.cxx",
        --"%{prj.name}/**.h"
        "vodka.cpp",
        "liu.cpp",
        "md5.cpp",
        "DisplayAnimation.cxx",
        "DisplayCache.cxx",
        "DisplayCamera.cxx",
        "DisplayCommon.cxx",
        "DisplayGenericInfo.cxx",
        "DisplayGlobalSettings.cxx",
        "DisplayHierarchy.cxx",
        "DisplayLight.cxx",
        "DisplayLink.cxx",
        "DisplayMarker.cxx",
        "DisplayMaterial.cxx",
        "DisplayMesh.cxx",
        "DisplayNurb.cxx",
        "DisplayPatch.cxx",
        "DisplayLodGroup.cxx",
        "DisplayPivotsAndLimits.cxx",
        "DisplayPose.cxx",
        "DisplayShape.cxx",
        "DisplaySkeleton.cxx",
        "DisplayTexture.cxx",
        "DisplayUserProperties.cxx",
        "main.cxx",
        "DisplayAnimation.h",
        "DisplayCache.h",
        "DisplayCamera.h",
        "DisplayCommon.h",
        "DisplayGenericInfo.h",
        "DisplayGlobalSettings.h",
        "DisplayHierarchy.h",
        "DisplayLight.h",
        "DisplayLink.h",
        "DisplayMarker.h",
        "DisplayMaterial.h",
        "DisplayMesh.h",
        "DisplayNurb.h",
        "DisplayPatch.h",
        "DisplayLodGroup.h",
        "DisplayPivotsAndLimits.h",
        "DisplayPose.h",
        "DisplayShape.h",
        "DisplaySkeleton.h",
        "DisplayTexture.h",
        "DisplayUserProperties.h",
        "Common.h",
        "Common.cxx"
    }
    
	postbuildcommands
	{
		("{COPY} {%{prj.name}/Output/".. modelName ..".wfm} \"../Wolfen/src/Assets/Models/\"")
    }
    
	filter "system:linux"
        pic "On"
		systemversion "latest"
		staticruntime "On"

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
