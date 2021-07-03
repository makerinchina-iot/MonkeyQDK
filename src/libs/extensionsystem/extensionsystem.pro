include(../../libs.pri)

TARGET = extensionsystem

DEFINES += EXTENSIONSYSTEM_LIBRARY

LIBS += \
    -lutils \

HEADERS += \
    extensionsystem_global.h \
    iplugin.h \
    iplugin_p.h \
    optionsparser.h \
    pluginmanager.h \
    pluginmanager_p.h \
    pluginspec.h \
    pluginspec_p.h

SOURCES += \
    iplugin.cpp \
    optionsparser.cpp \
    pluginmanager.cpp \
    pluginspec.cpp
