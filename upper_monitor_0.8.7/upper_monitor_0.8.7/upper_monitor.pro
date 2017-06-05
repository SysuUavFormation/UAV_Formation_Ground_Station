#-------------------------------------------------
#
# Project created by QtCreator 2016-12-28T15:11:40
#
#-------------------------------------------------

QT       += core gui
QT       += webkitwidgets
QT       += widgets serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = upper_monitor
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    serialportpage.cpp \
    mappage.cpp \
    statuspage.cpp \
    qextserialbase.cpp \
    qextserialport.cpp \
    returnvlc.cpp \
    win_qextserialport.cpp \
    parameter.cpp \
    uav_link.cpp \
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
    protocol.cpp

HEADERS  += mainwidget.h \
    serialportpage.h \
    mappage.h \
    statuspage.h \
    qextserialbase.h \
    qextserialport.h \
    returnvlc.h \
    win_qextserialport.h \
    commons.h \
    parameter.h \
    uav_link.h \
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
    protocol.h

DISTFILES += \
    README.txt \
    FileRelationship.txt \
    log/reapear_matlab.m

RESOURCES += \
    upper_monitor.qrc

RC_FILE = upper_monitor.rc
