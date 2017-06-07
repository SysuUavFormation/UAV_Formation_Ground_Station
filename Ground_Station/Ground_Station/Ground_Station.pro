#-------------------------------------------------
#
# Project created by QtCreator 2017-06-07T15:55:34
#
#-------------------------------------------------


QT       += core gui
QT       += webkitwidgets
QT       += widgets serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ground_Station
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    mappage.cpp \
    protocol.cpp \
    qextserialbase.cpp \
    qextserialport.cpp \
    returnvlc.cpp \
    serialportpage.cpp \
    statuspage.cpp \
    uav_link.cpp \
    win_qextserialport.cpp \
    CVT/CVT.cpp \
    CVT/CVT_method.cpp \
    CVT/CVT_shape.cpp \
    CVT/voro++/c_loops.cc \
    CVT/voro++/cell.cc \
    CVT/voro++/common.cc \
    CVT/voro++/container.cc \
    CVT/voro++/container_prd.cc \
    CVT/voro++/pre_container.cc \
    CVT/voro++/unitcell.cc \
    CVT/voro++/v_base.cc \
    CVT/voro++/v_base_wl.cc \
    CVT/voro++/v_compute.cc \
    CVT/voro++/voro++.cc \
    CVT/voro++/wall.cc \
    parameter.cpp

HEADERS  += mainwidget.h \
    commons.h \
    mappage.h \
    protocol.h \
    qextserialbase.h \
    qextserialport.h \
    returnvlc.h \
    serialportpage.h \
    statuspage.h \
    uav_link.h \
    win_qextserialport.h \
    CVT/CVT.hpp \
    CVT/CVT_method.hpp \
    CVT/CVT_shape.hpp \
    CVT/voro++/c_loops.hh \
    CVT/voro++/cell.hh \
    CVT/voro++/common.hh \
    CVT/voro++/config.hh \
    CVT/voro++/container.hh \
    CVT/voro++/container_prd.hh \
    CVT/voro++/pre_container.hh \
    CVT/voro++/rad_option.hh \
    CVT/voro++/unitcell.hh \
    CVT/voro++/v_base.hh \
    CVT/voro++/v_compute.hh \
    CVT/voro++/voro++.hh \
    CVT/voro++/wall.hh \
    CVT/voro++/worklist.hh \
    parameter.h

DISTFILES += \
    CVT/libCVT.a \
    CVT/Makefile \
    CVT/README \
    README.txt \
    log/heloo.txt

RESOURCES += \
    Ground_Station.qrc

RC_FILE = Ground_Station.rc
