TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
        action.cpp \
        collection.cpp \
        main.cpp \
        mainwindow.cpp \
        motion.cpp \
        rotation.cpp \
        tests.cpp

HEADERS += \
    action.h \
    collection.h \
    mainwindow.h \
    motion.h \
    rotation.h \
    tests.h \
    ui_mainwindow.h

DISTFILES +=

FORMS += \
    mainwindow.ui
