cmake_minimum_required(VERSION 3.5)

if (WIN32)
    project(Course_work LANGUAGES CXX)
elseif(UNIX)
    project(Course_work)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CONFIGURATION_TYPES "Release;RelWithDebInfo" CACHE STRING "" FORCE)


#======================= INCLUSION OF Qt =======================#
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)
find_package(Qt6Sql REQUIRED)

#=================== INCLUSION OF Project Files ====================#
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

#=================== SETUP EXECTUABLE ====================#
# Enable debug logging on RELWITHDEBINFO configuration
set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS
    $<$<CONFIG:RELWITHDEBINFO>:QT_MESSAGELOGCONTEXT>
)

# Add the forms directory to the AUTOUIC search paths
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR})

# Add the executable
if (WIN32) 
    add_executable(Course_work WIN32 ${SOURCES})
elseif(UNIX)
    add_executable(Course_work ${SOURCES})
endif()

# Add the target includes for Course_work 
target_include_directories(Course_work PRIVATE ${FORMS_DIR})
target_include_directories(Course_work PRIVATE ${INCLUDE_DIR})
target_include_directories(Course_work PRIVATE ${SOURCE_DIR})

#===================== LINKING LIBRARIES =======================#
target_link_libraries(Course_work Qt6::Widgets)
target_link_libraries(Course_work Qt6::Sql)

install(DIRECTORY ${project_BINARY_DIR}/Release/ DESTINATION project/bin)
#install(TARGETS ${project_SOURCE_DIR}/moscomsport DESTINATION project/bin/src)