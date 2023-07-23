cmake_minimum_required(VERSION 3.26.4)

project(
    "CppTemplate"
    VERSION 1.0.0
    LANGUAGES C CXX)

# Global CMake variables are set here
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Options

option(ENABLE_WARNINGS "Enable to add warnings to a target." ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable to treat warnings as errors." OFF)

# Project/Library Names
set(LIBRARY_NAME "lib")
set(EXECUTABLE_NAME "main")

# CMAKE MODULES
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)

if(ENABLE_WARNINGS)
    include(Warnings)
endif()


# EXTERNAL LIBRARIES
#message(STATUS "Using CPM")
#include(CPM)
#cpmaddpackage("gh:fmtlib/fmt#9.1.0")
#cpmaddpackage("gh:nlohmann/json@3.11.2")
#cpmaddpackage("gh:catchorg/Catch2@2.13.9")
#cpmaddpackage("gh:jarro2783/cxxopts@3.1.1")
#cpmaddpackage("gh:gabime/spdlog@1.11.0")

# SUB DIRECTORIES
add_subdirectory(src)
add_subdirectory(app)

# INSTALL TARGETS
install(
    TARGETS ${EXECUTABLE_NAME}
    EXPORT ${LIBRARY_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin)

install(
    TARGETS ${LIBRARY_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib)
