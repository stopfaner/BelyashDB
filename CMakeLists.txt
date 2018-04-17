cmake_minimum_required(VERSION 3.9)
project(BelyashDB)

include(CheckCXXCompilerFlag)

enable_language(C)
enable_language(CXX)

include_directories(/usr/local/include ${LUA_INCLUDE_DIR})

CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

if(COMPILER_SUPPORTS_CXX14)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
elseif(COMPILER_SUPPORTS_CXX11)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

SET(CMAKE_CONFIGURATION_TYPES Debug;Release
    CACHE STRING "Semicolon separated list of supported configuration types"
    FORCE)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.66.0 COMPONENTS regex serialization) 
# include(GoogleTest)
# set(TestArgs --test1 1)

# include_directories(core)

add_subdirectory(log4cpp)

set (
    SERVER_SOURCE
    core/server/session_manager.h
    core/server/session_manager.cpp
    core/server/session.h
    core/server/session.cpp

    core/parse/input_parser.h
    core/parse/input_parser.cpp
    core/parse/statement.h
)

set (
    STORAGE_SOURCE
    core/storage/storage_manager.h
    core/storage/storage_manager.cpp

    core/storage/collection/collection_manager.h
    core/storage/collection/collection_manager.cpp
    core/storage/collection/collection_metadata.h
    core/storage/collection/collection_metadata.cpp
    core/storage/collection/collection.h
    core/storage/collection/collection.cpp

    core/storage/metric/metric_manager.h
    core/storage/metric/metric_manager.cpp
    core/storage/metric/metric_metadata.h
    core/storage/metric/metric_metadata.cpp
    core/storage/metric/metric.h
    core/storage/metric/metric.cpp
    core/storage/metric/tag.h
    core/storage/metric/tag.cpp

    core/storage/metric/datatype/datatype.h
    core/storage/metric/datatype/int_metric.h
    core/storage/metric/datatype/decimal_metric.h
    core/storage/metric/datatype/percentage_metric.h

    core/storage/response.h
)



set(
    SOURCE

    ${SERVER_SOURCE}
    ${STORAGE_SOURCE}

    core/utils/file_manager.h
    core/utils/file_manager.cpp
    core/utils/logwrapper.h
    core/utils/logwrapper.cpp
    core/utils/uuid4.h
    core/utils/uuid4.cpp
    # ${CORE_SOURCE}
)

if(Boost_FOUND) 
    include_directories(${Boost_INCLUDE_DIRS})

    add_executable(${PROJECT_NAME} main.cpp ${SOURCE})

    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} log4cpp)

endif() 
