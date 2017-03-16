cmake_minimum_required(VERSION 3.0)

option( INSTALL_QGEO_PLUGIN "Check to install qGeo plugin" ON )

# CloudCompare 'ANIMATION' plugin
if (INSTALL_QGEO_PLUGIN)
	project( QGEO_PLUGIN )
	include( ../CMakePluginTpl.cmake )
endif()
