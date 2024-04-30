cmake_minimum_required(VERSION 3.20...3.26)

# Project name and a few useful settings. Other commands can pick up the results
project(
        Crypto
        VERSION 0.1
        DESCRIPTION "Crypto testing"
        LANGUAGES CXX)


set(${PROJECT_NAME}_OUTPUT              "${CMAKE_BINARY_DIR}/output/${PROJECT_NAME}")

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${${PROJECT_NAME}_OUTPUT})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_OUTPUT})
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    set(CMAKE_CXX_STANDARD 23)
    set(CMAKE_CXX_EXTENSIONS OFF)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    include(CTest)

    find_package(Doxygen)
    if(Doxygen_FOUND)
        add_subdirectory(docs)
    else()
        message(STATUS "Doxygen not found, not building docs")
    endif()
endif()

include(FetchContent)

add_subdirectory(src)

if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING)
        AND BUILD_TESTING)
    FetchContent_Declare(
            catch
            GIT_REPOSITORY https://github.com/catchorg/Catch2.git
            GIT_TAG v3.4.0)
    FetchContent_MakeAvailable(catch)
    add_subdirectory(tests)
endif()