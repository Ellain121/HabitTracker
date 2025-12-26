# set(CMAKE_POLICY_VERSION_MINIMUM 3.1)
cmake_minimum_required(VERSION 3.30)

project(HabitTracker VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(app_core)

# Choose one
# Comment out irrelevant option.
# Remove comments from required option.
##################################################
# Option 1: download JKQTPlotter automatically
# https://github.com/jkriege2/JKQtPlotter Usage via CMake's FetchConten-API
# set_target_properties(JKQTPlotter6 PROPERTY
# CMAKE_POLICY_VERSION_MINIMUM 3.5
# CMAKE_PREFIX_PATH /home/archer/Qt/6.9.2/gcc_64
# JKQtPlotter_ENABLED_CXX20 ON
# )
if(DOWNLOAD_LOCAL_JKQTPlotter)
    message(STATUS "JKQTPlotter will be downloaded in build directory")

    if (NOT(CMAKE_POLICY_VERSION_MINIMUM EQUAL 3.5 AND JKQtPlotter_ENABLED_CXX20))
        message("Please set flags as in instruction.")
        message(FATAL_ERROR "Exiting: CMAKE_POLICY_VERSION_MINIMUM is not '3.5' and JKQtPlotter_ENABLED_CXX20 is not enabled")
    endif()

    include(FetchContent) # once in the project to include the module
    FetchContent_Declare(JKQTPlotter6
                        GIT_REPOSITORY https://github.com/jkriege2/JKQtPlotter.git
                        # GIT_BRANCH master
                        GIT_BRANCH Branch_v4.0.0
                        )
    # ... finally make JKQTPlotter5/6 available
    FetchContent_MakeAvailable(JKQTPlotter6)
    set(CMAKE_PREFIX_PATH /home/archer/Qt/6.9.2/gcc_64 CACHE STRING INTERNAL)
    set(JKQtPlotter_ENABLED_CXX20 ON CACHE BOOL INTERNAL)
    set(CMAKE_POLICY_VERSION_MINIMUM 3.5 CACHE STRING INTERNAL)
else()
    message(WARNING "Using installed JKQTPlotter. Note that his project(for no real reason) uses C++20,"
    " you need JKQTPlotter6 to be compiled with -DJKQtPlotter_ENABLED_CXX20=ON. See https://github.com/jkriege2/JKQtPlotter/issues/138")
    #################################################
    # Option 2: download JKQTPlotter by yourself
    find_package(JKQTPlotter6)
    if (NOT JKQTPlotter6_FOUND)
        message(FATAL_ERROR "JKQTPlotter6 not found! Consider using flag DOWNLOAD_LOCAL_JKQTPlotter"
        " with other flags described in installation. Or install it(jkqtplotter) using -DJKQtPlotter_ENABLED_CXX20=ON")
    endif()
endif()

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets Gui Multimedia)
find_package(Qt6 REQUIRED COMPONENTS Widgets Gui Multimedia)


set(PROJECT_SOURCES

    RegexInputDialog.cpp
    ListViewCustom.cpp
    RegexInputDialog.hpp
    ListViewCustom.hpp
    resource.qrc
    main.cpp
    SoundPlayer.cpp
    HabitDelegate.cpp
    MainWindow.cpp
    SoundPlayer.hpp
    HabitDelegate.hpp
    MainWindow.hpp
    StatusProxyModel.cpp
    HabitDialog.cpp
    MainWindow.ui
    StatusProxyModel.hpp
    HabitDialog.hpp
    HabTableView.cpp
    HabTableView.hpp
    ReccurenceDialog.cpp

    ReccurenceDialog.hpp
    ScoreGraph.hpp
    ScoreGraph.cpp
    ScoreGraph.ui
    CircleProgressBar.hpp
    CircleProgressBar.cpp
    StatsDialog.hpp
    StatsDialog.cpp
    StatsDialog.ui
    RelativeResultGraph.cpp
    RelativeResultGraph.hpp
    RelativeResultGraph.ui
    ResultsBarGraph.cpp
    ResultsBarGraph.hpp
    ResultsBarGraph.ui
    SettingsDialog.hpp
    SettingsDialog.cpp
    SettingsDialog.ui
    ScoreGraphSettingsDialog.hpp ScoreGraphSettingsDialog.cpp ScoreGraphSettingsDialog.ui
    JKQTPlotterCustom.hpp JKQTPlotterCustom.cpp
    FilterProxyModel.hpp FilterProxyModel.cpp
)

if(6 GREATER_EQUAL 6)
    qt_add_executable(HabitTracker
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET HabitTracker APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(HabitTracker SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(HabitTracker
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} "${PROJECT_SOURCE_DIR}/app_core")
#include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::Gui Qt6::Multimedia JKQTPlotter6::JKQTPlotter6)
target_link_libraries(${PROJECT_NAME} PUBLIC app_core)
#target_link_libraries(${PROJECT_NAME} PRIVATE JKQTPlotter6::JKQTPlotter6)
#target_link_libraries(${PROJECT_NAME} JKQTPlotter6::JKQTPlotter6)

set_target_properties(HabitTracker PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS HabitTracker
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(HabitTracker)
endif()
