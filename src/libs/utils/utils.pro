include(../../libs.pri)
include(mimetypes/mimetypes.pri)

QT += widgets

DEFINES += UTILS_LIBRARY

TARGET = utils

SOURCES += \
    benchmarker.cpp \
    categorysortfiltermodel.cpp \
    hostosinfo.cpp \
    id.cpp \
    itemviews.cpp \
    json.cpp \
    qtcassert.cpp \
    qtcsettings.cpp \
    stringutils.cpp \
    treemodel.cpp \
    stylehelper.cpp \

HEADERS += \
    algorithm.h \
    benchmarker.h \
    categorysortfiltermodel.h \
    executeondestruction.h \
    hostosinfo.h \
    id.h \
    itemviews.h \
    json.h \
    osspecificaspects.h \
    porting.h \
    predicates.h \
    qtcassert.h \
    qtcsettings.h \
    stringutils.h \
    treemodel.h \
    utils_global.h \
    stylehelper.h \
