workspace "VitDragonEngine"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "VitDragonEngine/vendor/GLFW/include"

include "VitDragonEngine/vendor/GLFW" -- Search for lua files

project "VitDragonEngine"
	location "VitDragonEngine"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "vdepch.h"
	pchsource "VitDragonEngine/src/vdepch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"VDE_PLATFORM_WINDOWS",
			"VDE_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
		}

	filter "configurations:Debug"
		defines "VDE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VDE_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "VDE_DIST"
		symbols "On"

project "SandBox"
	location "SandBox"
	kind "consoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"VitDragonEngine/vendor/spdlog/include",
		"VitDragonEngine/src"
	}

	links {
		"VitDragonEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"VDE_PLATFORM_WINDOWS"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
		}

	filter "configurations:Debug"
		defines "VDE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VDE_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "VDE_DIST"
		symbols "On"