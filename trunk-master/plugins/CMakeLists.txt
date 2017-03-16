cmake_minimum_required(VERSION 3.0)

project( VirtualAssemblyPlugins )


# Auto add all subdirectories
file(GLOB subdirectories *)

foreach(dir ${subdirectories})
    if(IS_DIRECTORY ${dir})
		add_subdirectory (${dir})
	endif()
endforeach()
