cmake_minimum_required (VERSION 2.6)
project (VocAccelerator)
FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
include_directories(${QT_QTCORE_INCLUDE_DIR})
include_directories(${QT_QTGUI_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(tinyxml2)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/tinyxml2)

set(sourcefiles 
    main.cpp 
    GuessWindowController.cpp
    VocEntry.cpp
    Word.cpp
    Database.cpp
    VocView.cpp
    Conjugation.cpp
)
set(headerfiles 
    GuessWindowController.hpp
    VocView.hpp
)
set(uifiles 
    conjugation.ui
    default.ui
    GuessWindow.ui
)

QT4_WRAP_CPP(hppwrapfiles ${headerfiles})
QT4_WRAP_UI(uiwarpfiles ${uifiles})
add_executable(main ${sourcefiles} ${hppwrapfiles} ${uiwarpfiles} )
target_link_libraries(main ${QT_QTCORE_LIBRARY})
target_link_libraries(main ${QT_QTGUI_LIBRARY})
target_link_libraries(main tinyxml2)
add_dependencies(main tinyxml2)

