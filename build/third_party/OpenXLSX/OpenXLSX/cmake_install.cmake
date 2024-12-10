# Install script for directory: /home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/llvm-objdump-18")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OpenXLSX/headers" TYPE FILE FILES "/home/kamilg/vsc_cpp/sorting/build/third_party/OpenXLSX/OpenXLSX/OpenXLSX-Exports.hpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OpenXLSX/headers" TYPE FILE FILES
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/IZipArchive.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLCell.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLCellIterator.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLCellRange.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLCellReference.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLCellValue.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLColor.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLColumn.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLCommandQuery.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLComments.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLConstants.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLContentTypes.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLDateTime.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLDocument.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLException.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLFormula.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLIterator.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLMergeCells.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLProperties.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLRelationships.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLRow.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLRowData.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLSharedStrings.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLSheet.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLStyles.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLWorkbook.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLXmlData.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLXmlFile.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLXmlParser.hpp"
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/headers/XLZipArchive.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OpenXLSX" TYPE FILE FILES "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/OpenXLSX.hpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "lib" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/kamilg/vsc_cpp/sorting/build/output/libOpenXLSXd.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX" TYPE FILE FILES
    "/home/kamilg/vsc_cpp/sorting/third_party/OpenXLSX/OpenXLSX/OpenXLSXConfig.cmake"
    "/home/kamilg/vsc_cpp/sorting/build/third_party/OpenXLSX/OpenXLSX/OpenXLSX/OpenXLSXConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX/OpenXLSXTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX/OpenXLSXTargets.cmake"
         "/home/kamilg/vsc_cpp/sorting/build/third_party/OpenXLSX/OpenXLSX/CMakeFiles/Export/c72cc94553a1a0c9b05f75dae42fb1d7/OpenXLSXTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX/OpenXLSXTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX/OpenXLSXTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX" TYPE FILE FILES "/home/kamilg/vsc_cpp/sorting/build/third_party/OpenXLSX/OpenXLSX/CMakeFiles/Export/c72cc94553a1a0c9b05f75dae42fb1d7/OpenXLSXTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX" TYPE FILE FILES "/home/kamilg/vsc_cpp/sorting/build/third_party/OpenXLSX/OpenXLSX/CMakeFiles/Export/c72cc94553a1a0c9b05f75dae42fb1d7/OpenXLSXTargets-debug.cmake")
  endif()
endif()

