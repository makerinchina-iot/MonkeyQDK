include(../../plugins.pri)

QT += widgets

DEFINES += COREPLUGIN_LIBRARY

TARGET = coreplugin

LIBS += \
    -lextensionsystem

HEADERS += \
    core_global.h \
    coreplugin.h \
    icore.h

SOURCES += \
    coreplugin.cpp \
    icore.cpp

DISTFILES += \
    coreplugin.json


