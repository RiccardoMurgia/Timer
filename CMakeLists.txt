cmake_minimum_required(VERSION 3.17)
project(Project)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(unitTesting)

set(CMAKE_AUTOMOC ON)                   #crea i file _moc ogni volta che incontra la macro Q_OBJECT
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)                   #aggiunge il file ui per la creazione della finestra interattiva

set(SOURCE_FILES Time.h Time.cpp Date.h Date.cpp Counter.h Counter.cpp )

add_executable(Project main.cpp Time.cpp Time.h Date.cpp Date.h Counter.cpp Counter.h Observer.h
        mainwindow.cpp mainwindow.h mainwindow.ui mytimer.cpp mytimer.h mytimer.ui Subject.h)

add_library(core ${SOURCE_FILES})



find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)

include_directories(${Qt5Core_INCLUDE_DIRS})
target_link_libraries(core ${Qt5Core_LIBRARIES})

include_directories(${Qt5Widgets_INCLUDE_DIRS})
target_link_libraries(core ${Qt5Widgets_LIBRARIES})

target_link_libraries(Project core)