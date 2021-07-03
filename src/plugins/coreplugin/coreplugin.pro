include(../../plugins.pri)

QT += widgets

DEFINES += COREPLUGIN_LIBRARY

TARGET = coreplugin

LIBS += \
    -lextensionsystem

HEADERS += \
    coreplugin.h

SOURCES += \
    coreplugin.cpp

DISTFILES += \
    coreplugin.json


