cmake_minimum_required(VERSION 3.2)

project(qtCanvas)


FIND_PACKAGE(Qt4 REQUIRED)


INCLUDE(${QT_USE_FILE})



QT4_WRAP_CPP(MOCSrcs message.h menu.h mainwindow.h canvasview.h intermediate.h object.h canvas.h line.h circle.h)


include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
 


ADD_EXECUTABLE(qtCanvas mainwindow.cpp main.cpp message.cpp menu.cpp canvasview.cpp intermediate.cpp object.cpp canvas.cpp line.cpp circle.cpp ${MOCSrcs})



TARGET_LINK_LIBRARIES(qtCanvas Qt4::QtGui Qt4::QtWebKit)
