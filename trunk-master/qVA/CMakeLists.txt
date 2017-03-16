cmake_minimum_required(VERSION 3.0)

project( VirtualAssembly VERSION 2.8.0 )

include_directories( ${QVA_PE_LIB_SOURCE_DIR} )
#include_directories( ${QCC_GL_LIB_SOURCE_DIR} )
#include_directories( ${CloudComparePlugins_SOURCE_DIR} )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )
#include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/db_tree )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/ui_templates )
include_directories( ${CMAKE_CURRENT_BINARY_DIR} )

file( GLOB header_list *.h ${QXT_HEADERS} )
file( GLOB source_list *.cpp ${QXT_SOURCES} )

file( GLOB ui_list ui_templates/*.ui )
#file( GLOB qrc_list *.qrc )

qt5_wrap_ui( generated_ui_list ${ui_list} )
#qt5_add_resources( generated_qrc_list ${qrc_list} )

if( MSVC )
	# App icon with MSVC
	set( rc_list images/icon/cc_icon.rc )

	#to get rid of the (system) console
	add_executable( ${PROJECT_NAME} WIN32 ${header_list} ${source_list} ${generated_ui_list} ${generated_qrc_list} )
endif()

target_link_libraries( ${PROJECT_NAME} QVA_PE_LIB )


# Qt
qt5_use_modules(${PROJECT_NAME} Core Gui Widgets OpenGL PrintSupport)
if (WIN32)
	target_link_libraries( ${PROJECT_NAME} Qt5::WinMain )
endif()

#target_link_contrib( ${PROJECT_NAME} ${VIRTUALASSEMBLY_DEST_FOLDER} )


if( WIN32 )
	#set_property( TARGET ${PROJECT_NAME} APPEND PROPERTY COMPILE_DEFINITIONS CC_USE_AS_DLL QCC_DB_USE_AS_DLL QCC_IO_USE_AS_DLL )
	if (MSVC)
		#SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES LINK_FLAGS " /MANIFEST:NO")
	endif()
endif()

# App icon with Code::Blocks/MinGW
if( WIN32 )
	if( MINGW )
		if (NOT CMAKE_RC_COMPILER)
			set( CMAKE_RC_COMPILER windres )
		endif()
		add_custom_command( TARGET ${PROJECT_NAME} PRE_BUILD COMMAND ${CMAKE_RC_COMPILER} -i ${CMAKE_CURRENT_SOURCE_DIR}/images/icon/cc_icon.rc --input-format=rc -o ${CMAKE_CURRENT_BINARY_DIR}/cc_icon.res -O coff )
	endif()
endif()

# install program
install_ext( TARGETS ${PROJECT_NAME} ${VIRTUALASSEMBLY_DEST_FOLDER} )

if( WIN32 )
	# Export Qt dlls
	install_Qt_Dlls( ${VIRTUALASSEMBLY_DEST_FOLDER} )
	install_Qt_ImageFormats( ${VIRTUALASSEMBLY_DEST_FOLDER} )
	install_Qt5_plugins( ${VIRTUALASSEMBLY_DEST_FOLDER} )
endif()

