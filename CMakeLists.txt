cmake_minimum_required(VERSION 3.11)

project("WaveSabre" LANGUAGES C CXX CSharp)

# Enable C# Utilities also for the VS2013 AppVeyor stage.
cmake_policy(SET CMP0057 NEW)
include(CSharpUtilities)

# Note: The space suffix is required for the flag to work correctly.
set(CMAKE_CSharp_FLAGS "/langversion:latest ")

find_package(Git REQUIRED)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(MSVC)
	# disable exceptions globally (will be added back for VSTs)
	string(REPLACE "/EHsc" "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
endif()

set(BUILD_VST_PLUGINS ON CACHE BOOL "Opt out of building the VST plugins.")
set(BUILD_WAVESABRE_CONVERT ON CACHE BOOL "Do not build WaveSabreConvert.")
set(BUILD_WAVESABRE_CONVERT_TESTS ON CACHE BOOL "Do not build the WaveSabreConvert tests.")
set(BUILD_CONVERT_THE_FUCK ON CACHE BOOL "Do not build ConvertTheFuck.")
set(BUILD_PROJECT_MANAGER ON CACHE BOOL "Do not build the project manager.")

# This is just 10 times easier to handle.
set(CMAKE_INCLUDE_CURRENT_DIR OFF)
add_subdirectory(external/vst3sdk)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
add_subdirectory(external/FLParser)

# shared code
add_subdirectory(MSVCRT)
add_subdirectory(WaveSabreCore)
add_subdirectory(WaveSabrePlayerLib)

# binaries
add_subdirectory(Tests/PlayerTest)
add_subdirectory(WaveSabreStandAlonePlayer)

# VSTs
if(${BUILD_VST_PLUGINS} AND VSTSDK3_DIR)
	add_subdirectory(WaveSabreVstLib)
	add_subdirectory(Vsts)
endif()

# Project file conversions
if(${BUILD_WAVESABRE_CONVERT})
	add_subdirectory(WaveSabreConvert)
endif()
if(${BUILD_WAVESABRE_CONVERT_TESTS})
	add_subdirectory(Tests/WaveSabreConvertTests)
endif()
if(${BUILD_CONVERT_THE_FUCK})
	add_subdirectory(ConvertTheFuck)
endif()

# Project manager
if(${BUILD_PROJECT_MANAGER})
	add_subdirectory(ProjectManager)
endif()
