cmake_minimum_required(VERSION 3.5)

project(test2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 COMPONENTS Core Gui Widgets Sql REQUIRED)
set(PROJECT_SOURCES
        main.cpp
        View/mainwindow.cpp
        View/mainwindow.h
        View/mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(test2
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        classes/Account.class.cpp classes/Account.class.h classes/Db.class.cpp classes/Db.class.h classes/Sql.class.cpp classes/Sql.class.h classes/Stock.class.cpp classes/Stock.class.h classes/User.class.cpp classes/User.class.h classes/Api.class.h classes/Api.class.cpp
        View/accountview.cpp View/accountview.h View/accountview.ui  View/mainwindow.cpp View/mainwindow.h View/mainwindow.ui View/stockview.cpp View/stockview.h View/stockview.ui View/userview.cpp View/userview.h View/userview.ui
        ViewModel/userviewmodel.h ViewModel/userviewmodel.cpp
        ViewModel/accountviewmodel.h ViewModel/accountviewmodel.cpp
        ViewModel/stockviewmodel.h ViewModel/stockviewmodel.cpp


    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET test2 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(test2 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(test2
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(test2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.test2)
endif()
set_target_properties(test2 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS test2
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(test2)
endif()
# Unit Testing with Google Test
