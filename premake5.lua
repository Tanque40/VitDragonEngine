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
IncludeDir["Glad"] = "VitDragonEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "VitDragonEngine/vendor/imgui/"
IncludeDir["glm"] = "VitDragonEngine/vendor/glm/"

include "VitDragonEngine/vendor/GLFW" -- Search for lua files
include "VitDragonEngine/vendor/Glad" -- Search for lua files
include "VitDragonEngine/vendor/imgui" -- Search for lua files

project "VitDragonEngine"
	location "VitDragonEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "vdepch.h"
	pchsource "VitDragonEngine/src/vdepch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"

		defines {
			"VDE_PLATFORM_WINDOWS",
			"VDE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "VDE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "VDE_RELEASE"
		runtime "Release"
		symbols "on"

	filter "configurations:Dist"
		defines "VDE_DIST"
		runtime "Release"
		symbols "on"

project "SandBox"
	location "SandBox"
	kind "consoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"VitDragonEngine/vendor/spdlog/include",
		"VitDragonEngine/src",
		"VitDragonEngine/vendor",
		"%{IncludeDir.glm}"
	}

	links {
		"VitDragonEngine"
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"

		defines {
			"VDE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "VDE_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "VDE_RELEASE"
		runtime "Release"
		symbols "On"

	filter "configurations:Dist"
		defines "VDE_DIST"
		runtime "Release"
		symbols "On"