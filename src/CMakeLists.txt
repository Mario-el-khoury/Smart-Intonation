cmake_minimum_required(VERSION 3.7.0)

project(analogclock VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

SET(QT_USE_QTMULTIMEDIA TRUE)
SET(QT_USE_QTMULTIMEDIAWIDGETS TRUE)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Multimedia REQUIRED) 
find_package(Qt5 COMPONENTS MultimediaWidgets REQUIRED) 

FIND_PACKAGE( Qt5Multimedia REQUIRED )
FIND_PACKAGE( Qt5MultimediaWidgets REQUIRED )

add_executable(Smarto
  window.cpp
  main.cpp
)

target_link_libraries(Smarto Qt5::Widgets)
target_link_libraries(Smarto qwt-qt5)
target_link_libraries(Smarto Qt5::Multimedia)
target_link_libraries(Smarto Qt5::MultimediaWidgets)
target_link_libraries(Smarto fftw3)


install(TARGETS Smarto
RUNTIME DESTINATION bin)
