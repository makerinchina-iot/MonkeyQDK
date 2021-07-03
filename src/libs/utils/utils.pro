include(../../libs.pri)
include(mimetypes/mimetypes.pri)

QT += widgets

DEFINES += UTILS_LIBRARY

TARGET = utils

SOURCES += \
    benchmarker.cpp \
    hostosinfo.cpp \
    json.cpp \
    qtcassert.cpp \
    stringutils.cpp \
    utils.cpp

HEADERS += \
    algorithm.h \
    benchmarker.h \
    hostosinfo.h \
    json.h \
    qtcassert.h \
    stringutils.h \
    utils_global.h \
    utils.h
