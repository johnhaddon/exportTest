cmake_minimum_required( VERSION 3.6 )

set( BUILD_SHARED_LIBS True )
set( CMAKE_CXX_STANDARD 11 )

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake )

find_package( TBB REQUIRED )
find_package( Boost REQUIRED )

include_directories( ${TBB_INCLUDE_DIRS} )
include_directories( ${Boost_INCLUDE_DIRS} )

add_library( ExportTestLib TypedData.cpp TypedData.h )
target_link_libraries( ExportTestLib LINK_PRIVATE ${TBB_LIBRARIES} )
set_target_properties( ExportTestLib PROPERTIES CXX_VISIBILITY_PRESET hidden )

add_executable( exportTest ExportTest.cpp )
target_link_libraries( exportTest LINK_PUBLIC ExportTestLib LINK_PRIVATE ${TBB_LIBRARIES} )
