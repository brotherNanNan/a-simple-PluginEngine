FIND_PATH(osgVirtualAssembly_INCLUDE_DIR osgDragger/DraggerManager
  PATHS
  $ENV{OVADIR}/include
  $ENV{OVA_ROOT}/include
  $ENV{OVAHOME}/include
  /usr/include
  /usr/local/include
)

FIND_PATH(osgVirtualAssembly_LIB_DIR osgDragger.lib libosgDragger.so
  PATHS
  $ENV{OVADIR}/lib
  $ENV{OVA_ROOT}/lib
  $ENV{OVAHOME}/lib
  /usr/lib 
  /usr/local/lib
)

SET(OVA_FOUND "NO")
IF(osgVirtualAssembly_INCLUDE_DIR AND osgVirtualAssembly_LIB_DIR)
  SET(OVA_FOUND "YES")
ENDIF(osgVirtualAssembly_INCLUDE_DIR AND osgVirtualAssembly_LIB_DIR)
