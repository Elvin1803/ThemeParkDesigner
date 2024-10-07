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

    files
    {
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.h",

        "%{prj.name}/libs/glad/src/glad.c"
    }

    includedirs
    {
        "%{prj.name}/src/",
        
        "%{prj.name}/libs/glad/include/",
        "%{prj.name}/libs/GLFW/include/"
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

    filter "configurations:Debug"
        defines "TPD_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "TPD_RELEASE"
        optimize "On"