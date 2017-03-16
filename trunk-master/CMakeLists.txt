cmake_minimum_required(VERSION 3.0)

project( VirtualAssemblyProjects )


# Default debug suffix for libraries.
set( CMAKE_DEBUG_POSTFIX "d" )

# One shouldn't generate the BUILD project directly in the SOURCES folder!
if ( ${CMAKE_CURRENT_BINARY_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR} )
	if ( NOT SAME_BUILD_AND_SOURCE_FOLDER_WARNING_ALREADY_ISSUED )
		message(FATAL_ERROR "It is not advised to BUILD the binaries directly in the SOURCE folder!\n If you want to proceed with this option, just CONFIGURE the project once again" )
		set( SAME_BUILD_AND_SOURCE_FOLDER_WARNING_ALREADY_ISSUED TRUE )
	endif()
endif()

if( WIN32 )
    set( VIRTUALASSEMBLY_DEST_FOLDER VirtualAssembly )
    # (on Windows - msvc generator - the '_debug' suffix is automatically added for debug configurations)
    set( INSTALL_DESTINATIONS ${VIRTUALASSEMBLY_DEST_FOLDER} )
endif()

include( CMakeInclude.cmake )

add_subdirectory( VA )

# Add external libraries
include( CMakeExternalLibs.cmake )

# Contrib. libraries (mainly for I/O)
#include( contrib/AllSupport.cmake )

# Libs requested by both qCC & ccViewer
add_subdirectory( libs/qVA_pe )

add_subdirectory( plugins )

add_subdirectory( qVA )
