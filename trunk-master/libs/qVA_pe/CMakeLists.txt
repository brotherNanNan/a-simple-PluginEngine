cmake_minimum_required(VERSION 3.0)

#include_directories( ${CC_CORE_LIB_SOURCE_DIR}/include )
#include_directories( ${CC_FBO_LIB_SOURCE_DIR}/include )
if( MSVC )
	#include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/msvc )
endif()

project( QVA_PE_LIB )

file( GLOB header_list *.h)
file( GLOB source_list *.cpp)

add_library( ${PROJECT_NAME} SHARED ${header_list} ${source_list} )

#target_link_libraries( ${PROJECT_NAME} CC_CORE_LIB )
#target_link_libraries( ${PROJECT_NAME} CC_FBO_LIB )

# Qt
qt5_use_modules(${PROJECT_NAME} Core Gui Widgets OpenGL)

# install (shared) lib to specified destinations
if( WIN32)
	foreach( dest ${INSTALL_DESTINATIONS} )
		install_shared( ${PROJECT_NAME} ${dest} 1 )
	endforeach()
endif()
