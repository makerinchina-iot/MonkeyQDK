include(../../libs.pri)
include(mimetypes/mimetypes.pri)

QT += widgets

DEFINES += UTILS_LIBRARY

TARGET = utils

SOURCES += \
    benchmarker.cpp \
#    categorysortfiltermodel.cpp \
#    crcalgorithm.cpp \
#    datbasesql.cpp \
    hostosinfo.cpp \
#    itemviews.cpp \
    json.cpp \
#    logasync.cpp \
    qtcassert.cpp \
    stringutils.cpp \
#    treemodel.cpp \
    utils.cpp

HEADERS += \
    algorithm.h \
    benchmarker.h \
#    categorysortfiltermodel.h \
#    crcalgorithm.h \
#    datbasesql.h \
#    executeondestruction.h \
    hostosinfo.h \
#    itemviews.h \
    json.h \
#    logasync.h \
    qtcassert.h \
    stringutils.h \
#    taskqueue.h \
#    treemodel.h \
    utils_global.h \
    utils.h
