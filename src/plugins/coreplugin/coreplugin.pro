include(../../plugins.pri)

QT += widgets

DEFINES += COREPLUGIN_LIBRARY

TARGET = coreplugin

LIBS += \
    -lutils \
    -lextensionsystem \


HEADERS += \
    core_global.h \
    coreplugin.h \
    dialogs/ioptionspage.h \
    dialogs/settingsdialog.h \
    systemsettings.h

SOURCES += \
    coreplugin.cpp \
    dialogs/ioptionspage.cpp \
    dialogs/settingsdialog.cpp \
    systemsettings.cpp

DISTFILES += \
    coreplugin.json

FORMS += \
    SystemSettings.ui \
    dialogs/settingsdialog.ui


