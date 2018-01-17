#pragma once

#ifdef _MSC_VER
  #define EXPORTTEST_IMPORT __declspec(dllimport)
  #define EXPORTTEST_EXPORT __declspec(dllexport)
#else
  #define EXPORTTEST_IMPORT
  #define EXPORTTEST_EXPORT __attribute__((visibility("default")))
#endif

#ifdef __GNUC__
#define EXPORTTEST_PUSH_DEFAULT_VISIBILITY _Pragma( "GCC visibility push(default)" )
#define EXPORTTEST_POP_DEFAULT_VISIBILITY _Pragma( "GCC visibility pop" )
#else
#define EXPORTTEST_PUSH_DEFAULT_VISIBILITY
#define EXPORTTEST_POP_DEFAULT_VISIBILITY
#endif

#ifdef ExportTestLib_EXPORTS
  #define EXPORTTEST_API EXPORTTEST_EXPORT
#else
  #define EXPORTTEST_API EXPORTTEST_IMPORT
#endif
