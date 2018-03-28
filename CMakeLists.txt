cmake_minimum_required(VERSION 3.9)
project(BelyashDB)

include(CheckCXXCompilerFlag)

enable_language(C)
enable_language(CXX)

CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

if(COMPILER_SUPPORTS_CXX11)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

SET(CMAKE_CONFIGURATION_TYPES Debug;Release
    CACHE STRING "Semicolon separated list of supported configuration types"
    FORCE)

# include(GoogleTest)
# set(TestArgs --test1 1)

include_directories(core)

# add_subdirectory(log4cpp)
set(
    SOURCE
    core/server/session_manager.h
    core/server/session_manager.cpp
    core/server/uuid4.h
    core/server/uuid4.cpp
)
add_executable(${PROJECT_NAME} main.cpp ${SOURCE})

# target_link_libraries(BelyashDB log4cpp)