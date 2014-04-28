#
#
#

cmake_minimum_required(VERSION 2.6)

project(DesignProjectApp)

if(UNIX) 
    if(EXISTS "/usr/local/lib/OGRE/cmake") 
        set(CMAKE_MODULE_PATH "/usr/local/lib/OGRE/cmake/;${CMAKE_MODULE_PATH}")
    elseif(EXISTS "/usr/lib/OGRE/cmake") 
        set(CMAKE_MODULE_PATH "/usr/lib/OGRE/cmake/;${CMAKE_MODULE_PATH}")
    else()
        message(SEND_ERROR "Failed to find module path.")
    endif(EXISTS "/usr/local/lib/OGRE")
endif(UNIX)

if (CMAKE_BUILD_TYPE STREQUAL "")
  # CMake defaults to leaving CMAKE_BUILD_TYPE empty. This screws up
  # differentiation between debug and release builds.
  set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif ()

set(CMAKE_CXX_FLAGS "-g -Wall -MMD -std=c++11 -pthread")

set(CMAKE_DEBUG_POSTFIX "_d")

set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/dist")

find_package(OpenGL REQUIRED)
find_package(OGRE REQUIRED)
find_package(OIS REQUIRED)

# Find Boost
if (NOT OGRE_BUILD_PLATFORM_IPHONE)
    if (WIN32 OR APPLE)
        set(Boost_USE_STATIC_LIBS TRUE)
    else ()
        # Statically linking boost to a dynamic Ogre build doesn't work on Linux 64bit
        set(Boost_USE_STATIC_LIBS ${OGRE_STATIC})
    endif ()
    if (MINGW)
        # this is probably a bug in CMake: the boost find module tries to look for
        # boost libraries with name libboost_*, but CMake already prefixes library
        # search names with "lib". This is the workaround.
        set(CMAKE_FIND_LIBRARY_PREFIXES ${CMAKE_FIND_LIBRARY_PREFIXES} "")
    endif ()
    set(Boost_ADDITIONAL_VERSIONS "1.44" "1.44.0" "1.42" "1.42.0" "1.41.0" "1.41" "1.40.0" "1.40" "1.39.0" "1.39" "1.38.0" "1.38" "1.37.0" "1.37" )
    # Components that need linking (NB does not include header-only components like bind)
    set(OGRE_BOOST_COMPONENTS thread date_time)
    find_package(Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
    if (NOT Boost_FOUND)
        # Try again with the other type of libs
        set(Boost_USE_STATIC_LIBS NOT ${Boost_USE_STATIC_LIBS})
        find_package(Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
    endif()
    find_package(Boost QUIET)
 
    # Set up referencing of Boost
    include_directories(${Boost_INCLUDE_DIR})
    add_definitions(-DBOOST_ALL_NO_LIB)
    set(OGRE_LIBRARIES ${OGRE_LIBRARIES} ${Boost_LIOGRE_Terrain_FOUNDBRARIES})
endif()

# if we need OgreTerrain
if (OGRE_Terrain_FOUND) 
    set(OGRE_LIBRARIES ${OGRE_LIBRARIES} ${OGRE_Terrain_LIBRARIES})
    message(STATUS "Found OGRE_LIBRARIES: ${OGRE_LIBRARIES}")
else (OGRE_Terrain_FOUND) 
    message(SEND_ERROR "OgreTerrain Library not found.")
endif(OGRE_Terrain_FOUND)

set(HDRS 
    ./src/Engine.hpp
    ./src/Subject.hpp
    ./src/Observer.hpp
    ./src/Events.hpp
    ./src/RenderSystem/RenderSystem.hpp
    ./src/RenderSystem/ResourceManager.hpp
    ./src/Commands/Command.hpp
    ./src/Commands/UpdateCommand.hpp
    ./src/Commands/TranslateCommand.hpp
    ./src/Commands/CreateCommand.hpp
    ./src/Commands/DeleteCommand.hpp
)

set(SRCS
    ./src/main.cpp
    ./src/Engine.cpp
    ./src/Subject.cpp
    ./src/RenderSystem/RenderSystem.cpp
    ./src/RenderSystem/ResourceManager.cpp
    ./src/Commands/TranslateCommand.cpp
    ./src/Commands/CreateCommand.cpp
    ./src/Commands/DeleteCommand.cpp
)

include_directories( 
    ${OpenGL_INCLUDE_DIR}   
    ${OIS_INCLUDE_DIRS}
    ${OGRE_INCLUDE_DIRS}
)

add_executable(DesignProjectApp WIN32 ${HDRS} ${SRCS})

set_target_properties(DesignProjectApp PROPERTIES DEBUG_POSTFIX _d)

target_link_libraries(DesignProjectApp 
    ${OpenGL_LIBRARIES}
    ${OGRE_LIBRARIES} 
    ${OIS_LIBRARIES}
    )

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dist/bin)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dist/media)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/dist/bin)

install(TARGETS DesignProjectApp
    RUNTIME DESTINATION bin
    CONFIGURATIONS All
)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/dist/media
    DESTINATION ./
    CONFIGURATIONS Release RelWithDebInfo Debug
)

install(FILES ${CMAKE_SOURCE_DIR}/dist/bin/plugins.cfg
    ${CMAKE_SOURCE_DIR}/dist/bin/resources.cfg
    DESTINATION bin
    CONFIGURATIONS Release RelWithDebInfo Debug
)