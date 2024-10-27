workspace "Theme Park Designer"
    architecture "x64"
    configurations
    {
        "Debug",
        "Release"
    }

project "Theme Park Designer"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    location("%{prj.name}/")

    targetdir("bin/%{cfg.buildcfg}/%{prj.name}")
    objdir("bin-obj/%{cfg.buildcfg}/%{prj.name}")

    pchsource "%{prj.name}/src/pch.cpp"
    pchheader "pch.h"

    files
    {
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.h",

        "%{prj.name}/libs/glad/src/glad.c",
        "%{prj.name}/libs/glm/glm/**.hpp",
        "%{prj.name}/libs/entt/**.hpp"
    }

    includedirs
    {
        "%{prj.name}/src/",

        "%{prj.name}/libs/glad/include/",
        "%{prj.name}/libs/GLFW/include/",
        "%{prj.name}/libs/glm",
        "%{prj.name}/libs/entt/src",
    }

    links
    {
        "opengl32",
        "glfw3_mt"
    }

    libdirs
    {
        "%{prj.name}/libs/GLFW/lib/"
    }

    filter "files:**/glad.c"
        flags { "NoPCH" }

    filter "configurations:Debug"
        defines "TPD_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "TPD_RELEASE"
        optimize "On"