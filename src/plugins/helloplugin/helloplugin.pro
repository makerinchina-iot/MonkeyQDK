include(../../plugins.pri)

QT += core widgets

DEFINES += HELLOPLUGIN_LIBRARY

TARGET = helloplugin

LIBS += \
    -lutils \
    -lextensionsystem \
    -lcoreplugin \

HEADERS += \
    hello_global.h \
    hellopage.h \
    helloplugin.h \
    hellosettings.h

SOURCES += \
    hellopage.cpp \
    helloplugin.cpp \
    hellosettings.cpp

DISTFILES += \
    helloplugin.json

RESOURCES += \
    hello.qrc

FORMS += \
    HelloSettings.ui
