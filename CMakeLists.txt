cmake_minimum_required(VERSION 3.16)

project(universal-focus-remote VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# QOsc
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Network)
add_subdirectory(include/QOsc EXCLUDE_FROM_ALL)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/widgets)

set(
  PROJECT_SOURCES
    src/style/style.qrc
    
    src/widgets/qdualeventbutton.h
    src/widgets/qdualeventbutton.cpp

    src/widgets/qsquarepushbutton.h
    src/widgets/qsquarepushbutton.cpp

    src/actions/qbooleanaction.h
    src/actions/qbooleanaction.cpp

    src/main.cpp

    src/mainwindow.h
    src/mainwindow.cpp
    src/mainwindow.ui

    src/widgets/tabs/qboardtabarea.h
    src/widgets/tabs/qboardtabarea.cpp

    src/widgets/tabs/qnewtabdialog.h
    src/widgets/tabs/qnewtabdialog.cpp
    src/widgets/tabs/qnewtabdialog.ui

    src/boards/etc/eos/etceos.h
    src/boards/etc/eos/etceos.cpp

    src/boards/etc/eos/ui/eosform.h
    src/boards/etc/eos/ui/eosform.cpp
    src/boards/etc/eos/ui/eosform.ui

    src/boards/etc/eos/ui/eossyntaxhighlighter.h
    src/boards/etc/eos/ui/eossyntaxhighlighter.cpp

    src/boardselector.h
    src/boardselector.cpp
    src/boardselector.ui

    src/boards/etc/eos/eossettings.h
    src/boards/etc/eos/eossettings.cpp

    src/boards/etc/eos/ui/patch/eospatchform.h
    src/boards/etc/eos/ui/patch/eospatchform.cpp
    src/boards/etc/eos/ui/patch/eospatchform.ui

    src/boards/etc/eos/ui/keypad/eoskeypadform.h
    src/boards/etc/eos/ui/keypad/eoskeypadform.cpp
    src/boards/etc/eos/ui/keypad/eoskeypadform.ui

    src/addboarddialog.h
    src/addboarddialog.cpp
    src/addboarddialog.ui

    src/boards/etc/eos/datatypes/eoschannel.h
    src/boards/etc/eos/datatypes/eoschannel.cpp

    src/boards/etc/eos/ui/patch/qpatchdatamodel.h
    src/boards/etc/eos/ui/patch/qpatchdatamodel.cpp

    src/boards/etc/eos/eosdiscovery.h
    src/boards/etc/eos/eosdiscovery.cpp

    src/types/board/boarddiscovery.h
    src/types/board/boarddiscovery.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(universal-focus-remote
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET universal-focus-remote APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(universal-focus-remote SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(universal-focus-remote
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(universal-focus-remote
  PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
  PUBLIC
    QOsc
)

set_target_properties(universal-focus-remote PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER net.apollofops.UniversalFocusRemote
    MACOSX_BUNDLE_BUNDLE_NAME "Universal Focus Remote"
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)

if (WIN32)
	install(TARGETS QOsc
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	)
endif()

install(TARGETS universal-focus-remote
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(universal-focus-remote)
endif()
