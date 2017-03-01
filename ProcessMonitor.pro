TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    processmonitor.cpp \
    processmonitorprivate.cpp

HEADERS += \
    processmonitor.h \
    processmonitorprivate.h

DISTFILES += \
    readme.md
