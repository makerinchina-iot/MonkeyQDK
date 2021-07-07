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
    fancypage.h \
    homepage.h \
    systemsettings.h \
    toolpage.h

SOURCES += \
    coreplugin.cpp \
    dialogs/ioptionspage.cpp \
    dialogs/settingsdialog.cpp \
    fancypage.cpp \
    homepage.cpp \
    systemsettings.cpp \
    toolpage.cpp

DISTFILES += \
    coreplugin.json

FORMS += \
    SystemSettings.ui \
    dialogs/settingsdialog.ui


