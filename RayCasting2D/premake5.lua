workspace "RayCasting2D"
    architecture "x64"

    configurations{
        "Debug",
        "Release"
    }

    startproject "RayCasting2D"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "RayCasting2D"

newaction {
    trigger = "clean",
    description = "Remove all binaries and intermediate binaries, and vs files.",
    execute = function()
        print("Removing binaries")
        os.rmdir("./build/bin")
        print("Removing intermediate binaries")
        os.rmdir("./build/bin-int")
        print("Removing project files")
        os.rmdir("./.vs")
        os.remove("**.sln")
        os.remove("**.vcxproj")
        os.remove("**.vcxproj.filters")
        os.remove("**.vcxproj.user")
        print("Done")
    end
}