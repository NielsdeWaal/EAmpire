cmake_minimum_required(VERSION 2.6)

project(EAmpire)
set(EXE "main")

enable_testing()

if(NOT MSVC)
    set(warnings
        "-Wall"
        "-Wextra"
        "-Wall"
        "-Wextra"
        "-Wpedantic"
        "-Wcast-align"
        "-Wmissing-declarations"
        "-Wredundant-decls"
        "-Wuninitialized"
        "-Wconversion"
        "-Wno-unused-parameter")

    set(cxxflags
        "-std=c++17"
        ${warnings})

    string(REGEX REPLACE ";" " " cxxflags "${cxxflags}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${cxxflags}")
else()
    # Avoid windows.h junk
    add_definitions(/DNOMINMAX)
    # Avoid windows.h from including some usually unused libs like winsocks.h, since this might cause some redefinition errors.
    add_definitions(/DWIN32_LEAN_AND_MEAN)

    # /W3 - Level 3 warnings
    # /MP - Multi-threaded compilation
    # /Zi - Output debugging information
    # /Zo - enhanced debug info for optimized builds
    # /permissive- - enables stricter C++ standards conformance checks
    set(CMAKE_C_FLAGS   "/W3 /MP /Zi /Zo /permissive-" CACHE STRING "" FORCE)
    # /EHsc - C++-only exception handling semantics
    # /Zc:throwingNew - let codegen assume `operator new` will never return null
    # /Zc:inline - let codegen omit inline functions in object files
    set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} /EHsc /std:c++latest /Zc:throwingNew,inline" CACHE STRING "" FORCE)

    # /MDd - Multi-threaded Debug Runtime DLL
    set(CMAKE_C_FLAGS_DEBUG   "/Od /MDd" CACHE STRING "" FORCE)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}" CACHE STRING "" FORCE)

    # /O2 - Optimization level 2
    # /GS- - No stack buffer overflow checks
    # /MD - Multi-threaded runtime DLL
    set(CMAKE_C_FLAGS_RELEASE   "/O2 /GS- /MD" CACHE STRING "" FORCE)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}" CACHE STRING "" FORCE)

    set(CMAKE_EXE_LINKER_FLAGS_DEBUG   "/DEBUG /MANIFEST:NO" CACHE STRING "" FORCE)
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "/DEBUG /MANIFEST:NO /INCREMENTAL:NO /OPT:REF,ICF" CACHE STRING "" FORCE) 

    #set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/source)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(sources
    # Main source.
    source/main.cpp
    source/board.cpp
    source/game.cpp
    source/grid.cpp
    source/gameState.cpp
    include/game.hpp
    include/board.hpp
    include/grid.hpp
    include/gameState.hpp
    include/tile.hpp)

enable_testing()

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(Boost REQUIRED )
find_package(SFML 2 REQUIRED system window graphics network audio)

add_executable(${EXE} ${sources})
target_link_libraries(${EXE} ${Boost_LIBRARIES} dl ${SFML_LIBRARIES})
