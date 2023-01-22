cmake_minimum_required(VERSION 3.5)

project(Course_work VERSION 0.1 LANGUAGES CXX)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/install" CACHE PATH "..." FORCE)
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(./course_db.db ${CMAKE_BINARY_DIR}/course_db.db COPYONLY)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        register.cpp
        register.h
        register.ui
        constructor.cpp
        constructor.h
        constructor.ui
        welcome.cpp
        welcome.h
        welcome.ui
        recipe.h
        recipe.cpp
        recipe.ui
        course_db.db

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Course_work
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

else()
	add_executable(Course_work
            ${PROJECT_SOURCES}
        )
endif()

target_link_libraries(Course_work PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Course_work PRIVATE Qt6::Sql)

set_target_properties(Course_work PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)


if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Course_work)
endif()

install(TARGETS Course_work BUNDLE DESTINATION .)
install(FILES course_db.db DESTINATION .)

