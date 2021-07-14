include(../../plugins.pri)

QT += core widgets serialport

DEFINES += SERIALPLUGIN_LIBRARY

TARGET = serialplugin

LIBS += \
    -lutils \
    -lextensionsystem \
    -lcoreplugin \


HEADERS += \
    serial_global.h \
    serialcombobox.h \
    serialcontrol.h \
    inputlineedit.h \
    serialpage.h \
    serialpagewidget.h \
    serialplugin.h \
    serialsettings.h

SOURCES += \
    serialcombobox.cpp \
    serialcontrol.cpp \
    inputlineedit.cpp \
    serialpage.cpp \
    serialpagewidget.cpp \
    serialplugin.cpp \
    serialsettings.cpp

DISTFILES += \
    serialplugin.json

FORMS += \
    SerialSettingsWidget.ui \
    serialpagewidget.ui

RESOURCES += \
    res.qrc

