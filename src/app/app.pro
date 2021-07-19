include(../../MonkeyQDK.pri)

QT += core gui widgets

TEMPLATE = app

TARGET = MonkayQDK

LIBS += -L$$APP_LIBS_PATH

LIBS += \
    -lextensionsystem \

SOURCES += \
    main.cpp

DESTDIR = $$APP_OUT_PATH

#icon
RC_FILE += app_icon.rc
