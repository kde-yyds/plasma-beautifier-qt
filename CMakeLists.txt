cmake_minimum_required(VERSION 3.5)

project(plasma-beautifier-qt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        plasma_beautifier_qt.cpp
        plasma_beautifier_qt.h
        plasma_beautifier_qt.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(plasma-beautifier-qt
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET plasma-beautifier-qt APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(plasma-beautifier-qt SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(plasma-beautifier-qt
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(plasma-beautifier-qt PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(plasma-beautifier-qt PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)
install(PROGRAMS ./build/plasma-beautifier-qt
DESTINATION /usr/bin/)

install(PROGRAMS ./data/installklassy.sh
DESTINATION /usr/lib/plasma-beautifier-qt/data)

install(PROGRAMS ./data/installlightly.sh
DESTINATION /usr/lib/plasma-beautifier-qt/data)

install(FILES ./data/desktoptheme-DeepinV20-dark.tar.xz
DESTINATION /usr/lib/plasma-beautifier-qt/data)

install(FILES ./data/klassy.tar.xz
DESTINATION /usr/lib/plasma-beautifier-qt/data)


install(FILES ./data/klassyrc
DESTINATION /usr/lib/plasma-beautifier-qt/data)

install(FILES ./data/Lightly-transparent.colors
DESTINATION /usr/lib/plasma-beautifier-qt/data)


install(FILES ./data/Lightly.tar.xz
DESTINATION /usr/lib/plasma-beautifier-qt/data)


install(FILES ./data/lightlyrc
DESTINATION /usr/lib/plasma-beautifier-qt/data)



if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(plasma-beautifier-qt)
endif()
