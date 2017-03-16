### DEFAULT  "STANDARD" PLUGIN CMAKE SCRIPT ###

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )
include_directories( ${CMAKE_CURRENT_BINARY_DIR} )
include_directories( ${QVA_PE_LIB_SOURCE_DIR} )
#include_directories( ${VirtualAssemblyPlugins_SOURCE_DIR} )

file( GLOB header_list *.h)
file( GLOB source_list *.cpp)
# force the link with ccStdPluginInterface.cpp
#list( APPEND source_list ${CloudComparePlugins_SOURCE_DIR}/ccStdPluginInterface.cpp )
file( GLOB ui_list *.ui )
file( GLOB qrc_list *.qrc )
file( GLOB rc_list *.rc )

if ( CC_PLUGIN_CUSTOM_HEADER_LIST )
    list( APPEND header_list ${CC_PLUGIN_CUSTOM_HEADER_LIST} )
endif()

if ( CC_PLUGIN_CUSTOM_SOURCE_LIST )
    list( APPEND source_list ${CC_PLUGIN_CUSTOM_SOURCE_LIST} )
endif()

if (CC_PLUGIN_CUSTOM_UI_LIST)
    list( APPEND ui_list ${CC_PLUGIN_CUSTOM_UI_LIST} )
endif()


qt5_wrap_ui( generated_ui_list ${ui_list} )
qt5_add_resources( generated_qrc_list ${qrc_list} )

add_library( ${PROJECT_NAME} SHARED ${header_list} ${source_list} ${moc_list} ${generated_ui_list} ${generated_qrc_list})


# Plugins need the QT_NO_DEBUG preprocessor in release!
if( NOT CMAKE_CONFIGURATION_TYPES )
    set_property( TARGET ${PROJECT_NAME} APPEND PROPERTY COMPILE_DEFINITIONS QT_NO_DEBUG )
else()
	#Anytime we use COMPILE_DEFINITIONS_XXX we must define this policy!
	#(and setting it outside of the function/file doesn't seem to work...)
	cmake_policy(SET CMP0043 OLD)

    set_property( TARGET ${PROJECT_NAME} APPEND PROPERTY COMPILE_DEFINITIONS_RELEASE QT_NO_DEBUG)
endif()

target_link_libraries( ${PROJECT_NAME} QVA_PE_LIB )

# Qt
qt5_use_modules(${PROJECT_NAME} Core Gui Widgets OpenGL Concurrent)

install_shared( ${PROJECT_NAME} ${VIRTUALASSEMBLY_DEST_FOLDER} 1 /plugins )


### END OF DEFAULT CC PLUGIN CMAKE SCRIPT ###
