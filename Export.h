#pragma once

#ifdef _MSC_VER
  #define EXPORTTEST_IMPORT __declspec(dllimport)
  #define EXPORTTEST_EXPORT __declspec(dllexport)
#else
  #define EXPORTTEST_IMPORT
  #define EXPORTTEST_EXPORT __attribute__((visibility("default")))
#endif

#ifdef ExportTest_EXPORTS
  #define EXPORTTEST_API EXPORTTEST_EXPORT
#else
  #define EXPORTTEST_API EXPORTTEST_IMPORT
#endif
