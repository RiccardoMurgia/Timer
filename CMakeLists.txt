cmake_minimum_required(VERSION 3.17)
project(Project)


set(CMAKE_AUTOMOC ON)                   #crea i file _moc ogni volta che incontra la macro Q_OBJECT

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)                   #aggiunge il file ui per la creazione della finestra interattivaset(SOURCE_FILES main.cpp)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project main.cpp Time.cpp Time.h Date.cpp Date.h Counter.cpp Counter.h Observer.h mainwindow.cpp mainwindow.h mainwindow.ui mytimer.cpp mytimer.h mytimer.ui Subject.h)

target_link_libraries(Project Qt5::Widgets)