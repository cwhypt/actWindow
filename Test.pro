#-------------------------------------------------
#
# Project created by QtCreator 2019-05-08T18:22:36
#
#-------------------------------------------------

QT       += core gui
QT       += sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    sqltableeditor.cpp \
    defaultvalue.cpp \
    mainpage.cpp \
    autopage.cpp

HEADERS  += mainwindow.h \
    connection.h \
    sqltableeditor.h \
    defaultvalue.h \
    mainpage.h \
    autopage.h

FORMS    += mainwindow.ui

target.path = $$[QT_INSTALL_EXAMPLES]/sql/cachedtable
INSTALLS += target


