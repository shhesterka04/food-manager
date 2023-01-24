cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (WIN32)
    project(Course_work LANGUAGES CXX)
elseif(UNIX)
    project(Course_work)
endif()

find_package(Doxygen)
if(DOXYGEN_FOUND)
	set(doxyfile_in ${CMAKE_SOURCE_DIR})

	configure_file(Doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

	add_custom_target(docs 
	${DOXYGEN_EXECUTABLE}
	${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
	COMMENT "Generating API documentation with Doxygen"
	VERBATIM
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
endif()

set(CMAKE_CONFIGURATION_TYPES "Debug;RelWithDebInfo" CACHE STRING "" FORCE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)

set(FORMS_DIR "${CMAKE_SOURCE_DIR}/forms")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

include_directories(${FORMS_DIR})
include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})

file(GLOB_RECURSE SOURCES
    "${FORMS_DIR}/*.ui"
    "${FORMS_DIR}/*.qrc"
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
        "${SOURCE_DIR}/*.db"
)


set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS
    $<$<CONFIG:RELWITHDEBINFO>:QT_MESSAGELOGCONTEXT>
)


set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR})

if (WIN32)
    add_executable(Course_work WIN32 ${SOURCES})
elseif(UNIX)
    add_executable(Course_work ${SOURCES})
endif()

target_include_directories(Course_work PRIVATE ${FORMS_DIR})
target_include_directories(Course_work PRIVATE ${INCLUDE_DIR})
target_include_directories(Course_work PRIVATE ${SOURCE_DIR})

target_link_libraries(Course_work Qt5::Widgets)
target_link_libraries(Course_work Qt5::Sql)

install(TARGETS Course_work DESTINATION .)
install(DIRECTORY ${Course_work_SOURCE_DIR}/src/src DESTINATION .)
