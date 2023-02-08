cmake_minimum_required(VERSION 3.5)

project(FirstWidgetGUI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.h mainwindow.cpp
    mainwindow.ui

    nodestyles.h nodestyles.cpp
    nodescene.h nodescene.cpp
    nodeitem.h nodeitem.cpp

    elements/connection.h elements/connection.cpp
    elements/ioelement.h elements/ioelement.cpp
    elements/nodeoutlinerectitem.h elements/nodeoutlinerectitem.cpp
    elements/editormenu.h elements/editormenu.cpp
    elements/editormenuitem.h elements/editormenuitem.cpp

    nodes/colornode.h nodes/colornode.cpp
    nodes/editornode.h nodes/editornode.cpp
#    nodes/getshapesnode.h nodes/getshapesnode.cpp
#    nodes/layernode.h nodes/layernode.cpp
    nodes/mathnode.h nodes/mathnode.cpp
    nodes/noisenode.h nodes/noisenode.cpp
    nodes/outputnode.h nodes/outputnode.cpp
    nodes/previewnode.h nodes/previewnode.cpp
    nodes/shapenode.h nodes/shapenode.cpp
    nodes/valuenode.h nodes/valuenode.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(FirstWidgetGUI
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET FirstWidgetGUI APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(FirstWidgetGUI SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(FirstWidgetGUI
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(FirstWidgetGUI PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(FirstWidgetGUI PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS FirstWidgetGUI
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(FirstWidgetGUI)
endif()
