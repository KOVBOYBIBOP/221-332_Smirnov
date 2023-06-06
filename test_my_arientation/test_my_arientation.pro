QT += testlib
QT -= gui
QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_im_gay.cpp \

    ../../../../../Univercity/Proga_Egz/server/func_for_server.cpp \
    ../../../../../Univercity/Proga_Egz/server/mytcpserver.cpp

HEADERS += \

    ../../../../../Univercity/Proga_Egz/server/func_for_server.h \
    ../../../../../Univercity/Proga_Egz/server/mytcpserver.h
