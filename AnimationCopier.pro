TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += $$PWD\opencv_3_2_msvc2015\include
LIBS += -L$$PWD\opencv_3_2_msvc2015\lib

CONFIG (debug, debug|release) {
    LIBS += -lopencv_world320d
}
CONFIG (release, debug|release) {
    LIBS += -lopencv_world320
}

SOURCES += main.cpp \
    calc.cpp

HEADERS += \
    calc.h \
    matrix.h
