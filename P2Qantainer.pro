#-------------------------------------------------
#
# Project created by QtCreator 2018-12-16T11:54:32
#
#-------------------------------------------------

QT       += core gui
QT += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = P2Qantainer
TEMPLATE = app
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    Model/gioco.cpp \
    Model/ps4.cpp \
    Model/ps3.cpp \
    Model/xbox360.cpp \
    Model/xboxone.cpp \
    Model/gestionegiochi.cpp \
    Controller/controller.cpp \
    Exceptions/exceptions.cpp \
    Exceptions/pasttheend.cpp \
    Exceptions/invaliditerator.cpp \
    View/layoutvisualizzagiochi.cpp \
    View/giochilistitem.cpp \
    View/giochilistwidget.cpp \
    View/menubar.cpp \
    View/layoutvisualizzaitem.cpp \
    View/layoutinserisci.cpp \
    View/comboboxgenere.cpp \
    View/comboboxanno.cpp \
    View/comboboxpegi.cpp \
    View/comboboxtipo.cpp \
    Exceptions/openfileexception.cpp \
    View/layoutricerca.cpp

HEADERS += \
     Model/gioco.h \
    Model/ps4.h \
    Model/ps3.h \
    Model/xbox360.h \
    Model/xboxone.h \
    Model/dlinkedlist.h \
    Model/gestionegiochi.h \
    Controller/controller.h \
    Exceptions/exceptions.h \
    Exceptions/pasttheend.h \
    Exceptions/invaliditerator.h \
    View/layoutvisualizzagiochi.h \
    View/giochilistitem.h \
    View/giochilistwidget.h \
    View/menubar.h \
    View/layoutvisualizzaitem.h \
    View/layoutinserisci.h \
    View/comboboxgenere.h \
    View/comboboxanno.h \
    View/comboboxpegi.h \
    View/comboboxtipo.h \
    Exceptions/openfileexception.h \
    View/layoutricerca.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    P2Qantainer.pro \

RESOURCES += \
    resources.qrc
