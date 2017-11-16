cmake_minimum_required( VERSION 3.6 )

set( BUILD_SHARED_LIBS True )
set( CMAKE_CXX_STANDARD 11 )

add_library( ExportTestLib TypedData.cpp )
set_target_properties( ExportTestLib PROPERTIES CXX_VISIBILITY_PRESET hidden )

add_executable( exportTest ExportTest.cpp )
target_link_libraries( exportTest LINK_PUBLIC ExportTestLib )
