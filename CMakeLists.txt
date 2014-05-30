#
#
#

cmake_minimum_required(VERSION 2.6)

project(DesignProjectApp)

if(WIN32) 
    set(CMAKE_MODULE_PATH "$ENV{OGRE_HOME}/CMake/;${CMAKE_MODULE_PATH}")
endif(WIN32)

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

if(UNIX) 
    # Setting unix flags
    set(CMAKE_CXX_FLAGS "-g -Wall -MMD -std=c++11 -pthread")
endif(UNIX)

set(CMAKE_DEBUG_POSTFIX "_d")
set (CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)

set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/dist")

find_package(OpenGL REQUIRED)
find_package(OGRE REQUIRED)
find_package(OIS REQUIRED)

set (BOOST_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/boost")


if (NOT OGRE_BUILD_PLATFORM_APPLE_IOS)
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
    set(Boost_ADDITIONAL_VERSIONS "1.54" "1.54.0" "1.53" "1.53.0" "1.52" "1.52.0" "1.51" "1.51.0" "1.50" "1.50.0" "1.49" "1.49.0" "1.48" "1.48.0" "1.47" "1.47.0" "1.46" "1.46.0" "1.45" "1.45.0" "1.44" "1.44.0" "1.42" "1.42.0" "1.41.0" "1.41" "1.40.0" "1.40")
    # Components that need linking (NB does not include header-only components like bind)
    set(OGRE_BOOST_COMPONENTS thread date_time)
    find_package(Boost QUIET)
    if (NOT Boost_FOUND)
        if(Boost_USE_STATIC_LIBS)
            set(Boost_USE_STATIC_LIBS OFF)
        else()
            set(Boost_USE_STATIC_LIBS ON)
        endif()
        find_package(Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
    endif()    

    if(Boost_FOUND AND Boost_VERSION GREATER 104900)
        set(OGRE_BOOST_COMPONENTS thread date_time system chrono)
        find_package(Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
    endif()

    # Set up referencing of Boost
    include_directories(${Boost_INCLUDE_DIR})
    add_definitions(-DBOOST_ALL_NO_LIB)
    set(OGRE_LIBRARIES ${OGRE_LIBRARIES} ${Boost_LIBRARIES})
else()
    set(BOOST_LIBRARYDIR "${CMAKE_CURRENT_SOURCE_DIR}/boost/lib")
    set(BOOST_INCLUDEDIR "${CMAKE_CURRENT_SOURCE_DIR}/boost/include")
    set(Boost_USE_STATIC_LIBS TRUE)
    set(Boost_NO_SYSTEM_PATHS TRUE)
    set(Boost_USE_MULTITHREADED OFF)

    set(Boost_ADDITIONAL_VERSIONS "1.54" "1.54.0" "1.53" "1.53.0" "1.52" "1.52.0" "1.51" "1.51.0" "1.50" "1.50.0" "1.49" "1.49.0" "1.48" "1.48.0" "1.47" "1.47.0" "1.46" "1.46.0" "1.45" "1.45.0" "1.44" "1.44.0" "1.42" "1.42.0" "1.41.0" "1.41" "1.40.0" "1.40")
    # Components that need linking (NB does not include header-only components like bind)
    set(OGRE_BOOST_COMPONENTS thread date_time)
    find_package(Boost QUIET)
    if (NOT Boost_FOUND)
        if(Boost_USE_STATIC_LIBS)
            set(Boost_USE_STATIC_LIBS OFF)
        else()
            set(Boost_USE_STATIC_LIBS ON)
        endif()
        find_package(Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
    endif()    

    if(Boost_FOUND AND Boost_VERSION GREATER 104900)
        set(OGRE_BOOST_COMPONENTS thread date_time system chrono)
        find_package(Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
    endif()

    # Set up referencing of Boost
    include_directories(${Boost_INCLUDE_DIR})
    add_definitions(-DBOOST_ALL_NO_LIB)
    set(OGRE_LIBRARIES ${OGRE_LIBRARIES} ${Boost_LIBRARIES})
endif(NOT OGRE_BUILD_PLATFORM_APPLE_IOS)

# if we need OgreTerrain
if (OGRE_Terrain_FOUND) 
    set(OGRE_LIBRARIES ${OGRE_LIBRARIES} ${OGRE_Terrain_LIBRARIES})
    message(STATUS "Found OGRE_LIBRARIES: ${OGRE_LIBRARIES}")
else (OGRE_Terrain_FOUND) 
    message(SEND_ERROR "OgreTerrain Library not found.")
endif(OGRE_Terrain_FOUND)

set(HDRS 
    ./src/Engine.hpp
    ./src/Events.hpp
    ./src/RenderSystem/RenderSystem.hpp
    ./src/RenderSystem/ResourceManager.hpp
)

set(SRCS
    ./src/main.cpp
    ./src/Engine.cpp
    ./src/RenderSystem/RenderSystem.cpp
    ./src/RenderSystem/ResourceManager.cpp
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

# post-build copy for win32
if(WIN32 AND NOT MINGW) 
    add_custom_command( TARGET DesignProjectApp PRE_BUILD
        COMMAND if not exist .\\dist\\bin mkdir .\\dist\\bin )
    add_custom_command( TARGET DesignProjectApp POST_BUILD
        COMMAND copy \"$(TargetPath)\" .\\dist\\bin )
endif(WIN32 AND NOT MINGW)

if(MINGW OR UNIX) 
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/dist/bin)
endif(MINGW OR UNIX)

if(WIN32)
    install(TARGETS DesignProjectApp
        RUNTIME DESTINATION bin
        CONFIGURATIONS ALL
    )
    install(DIRECTORY ${CMAKE_SOURCE_DIR}/dist/media
        DESTINATION ./
        CONFIGURATIONS Release RelWithDebInfo Debug
    )
    install(FILES 
        ${CMAKE_SOURCE_DIR}/dist/bin/plugins.cfg
        ${CMAKE_SOURCE_DIR}/dist/bin/resources.cfg
        DESTINATION bin
        CONFIGURATIONS Release RelWithDebInfo
    )
    install(FILES 
        ${CMAKE_SOURCE_DIR}/dist/bin/plugins_d.cfg
        ${CMAKE_SOURCE_DIR}/dist/bin/resources_d.cfg
        DESTINATION bin
        CONFIGURATIONS Debug
    )

    message(STATUS "OGRE_PLUGIN_DIR_REL: ${OGRE_PLUGIN_DIR_REL}")
    install(FILES
        ${OGRE_PLUGIN_DIR_REL}/OgreMain.dll
        ${OGRE_PLUGIN_DIR_REL}/RenderSystem_Direct3D9.dll
        ${OGRE_PLUGIN_DIR_REL}/RenderSystem_GL.dll
        ${OGRE_PLUGIN_DIR_REL}/Plugin_ParticleFX.dll
        ${OGRE_PLUGIN_DIR_REL}/Plugin_CgProgramManager.dll
        ${OGRE_PLUGIN_DIR_REL}/Plugin_OctreeSceneManager.dll
        ${OGRE_PLUGIN_DIR_REL}/OIS.dll
        ${OGRE_PLUGIN_DIR_REL}/cg.dll
        DESTINATION bin
        CONFIGURATIONS Release RelWithDebInfo
    )

    message(STATUS "OGRE_PLUGIN_DIR_DBG: ${OGRE_PLUGIN_DIR_DBG}")
    install(FILES 
        ${OGRE_PLUGIN_DIR_DBG}/OgreMain_d.dll
        ${OGRE_PLUGIN_DIR_DBG}/RenderSystem_Direct3D9_d.dll
        ${OGRE_PLUGIN_DIR_DBG}/RenderSystem_GL_d.dll
        ${OGRE_PLUGIN_DIR_DBG}/Plugin_ParticleFX_d.dll
        ${OGRE_PLUGIN_DIR_DBG}/Plugin_CgProgramManager_d.dll
        ${OGRE_PLUGIN_DIR_DBG}/Plugin_OctreeSceneManager_d.dll
        ${OGRE_PLUGIN_DIR_DBG}/OIS_d.dll
        ${OGRE_PLUGIN_DIR_DBG}/cg.dll
        DESTINATION bin
        CONFIGURATIONS Debug
    )
    install(FILES 
        ${Boost_DATE_TIME_LIBRARY_RELEASE}
        ${Boost_THREAD_LIBRARY_RELEASE}
        DESTINATION bin
        CONFIGURATIONS Release RelWithDebInfo
    )
    install(FILES ${Boost_DATE_TIME_LIBRARY_DEBUG}
        ${Boost_THREAD_LIBRARY_DEBUG}
        DESTINATION bin
        CONFIGURATIONS Debug
    )
endif(WIN32)

if(UNIX) 
    install(TARGETS DesignProjectApp
        RUNTIME DESTINATION bin
        CONFIGURATIONS All
    )
    install(DIRECTORY 
        ${CMAKE_SOURCE_DIR}/dist/media
        DESTINATION ./
        CONFIGURATIONS Release RelWithDebInfo Debug
    )
    install(FILES 
        ${CMAKE_SOURCE_DIR}/dist/bin/plugins.cfg
        ${CMAKE_SOURCE_DIR}/dist/bin/resources.cfg
        DESTINATION bin
        CONFIGURATIONS Release RelWithDebInfo Debug
    )
endif(UNIX)