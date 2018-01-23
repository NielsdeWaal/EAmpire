cmake_minimum_required(VERSION 2.6)

project(EAmpire)
set(EXE "main")

#find_package(PkgConfig)
#pkg_check_modules(GTEST REQUIRED gtest>=1.7.0)
#pkg_check_modules(GMOCK REQUIRED gtest>=1.7.0)

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
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/test)

#add_subdirectory(test)

include(cmake_modules/clang-cxx-dev-tools.cmake)
include(cmake_modules/FindSFML.cmake)

set(sources
    # Main source.
    source/main.cpp
    source/game.cpp
    source/board.cpp
    source/grid.cpp
    source/gameState.cpp
    source/tile.cpp
    source/button.cpp
    source/action.cpp
    source/enemy.cpp
	  source/enemy_a.cpp
	source/factory.cpp
    include/game.hpp
    include/board.hpp
    include/grid.hpp
    include/gameState.hpp
    include/tile.hpp
    include/button.hpp
	include/action.hpp
	include/factory.hpp)
    include/action.hpp
	  include/enemy.hpp
	  include/enemy_a.hpp
	  include/enemy_container.hpp)


set(gridLibSRC
    source/grid.cpp
    include/grid.hpp)

add_library(gridlib STATIC
        ${gridLibSRC})

target_include_directories(gridlib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

enable_testing()

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(Boost REQUIRED )
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
endif()

if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
endif()


add_executable(${EXE} ${sources})
target_link_libraries(${EXE} ${Boost_LIBRARIES} ${SFML_LIBRARIES})
