#-------------------------------------------------
#
# Project created by QtCreator 2013-03-26T13:30:47
#
#-------------------------------------------------
#QMAKE_CXXFLAGS+=-std=c++0x -Wall -Wextra -pedantic
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets qwt

TARGET = PromengTest2
TEMPLATE = app
CONFIG += console

#QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
        mainwindow.cpp \
    PromengDialog.cpp \
    bitmapworker.cpp \
    db_VisualParam.cpp \
    dbconn.cpp \
    db_signal.cpp \
    CheckpointMessages.cpp \
    CheckPointProperties.cpp \
    db_CheckPointProperties.cpp \
    vec_signal.cpp \
    db_VideoFrame.cpp \
    VideoFrame.cpp \
    VisualParam.cpp \
    LoginPassword.cpp \
    DbLoginPasswords.cpp \
    LoginDialog.cpp \
    ModelLoginPassword.cpp \
    TableEditDialog.cpp \
    ModelVisualParam.cpp \
    CheckPointEditDialog.cpp \
    CheckpointPropDialog.cpp \
    plot.cpp \
    Signal.cpp \
    ModelArchivSignal.cpp \
    DelegatArchivSignal.cpp

HEADERS  += mainwindow.h \
    PromengDialog.h \
    bitmapworker.h \
    db_VisualParam.h \
    dbconn.h \
    AllHeaders.h \
    db_signal.h \
    CheckpointMessages.h \
    db_CheckPointProperties.h \
    CheckPointProperties.h \
    vec_signal.h \
    db_VideoFrame.h \
    VideoFrame.h \
    VisualParam.h \
    LoginPassword.h \
    DbLoginPasswords.h \
    LoginDialog.h \
    ModelLoginPassword.h \
    TableEditDialog.h \
    ModelVisualParam.h \
    CheckPointEditDialog.h \
    CheckpointPropDialog.h \
    plot.h \
    Signal.h \
    ModelArchivSignal.h \
    DelegatArchivSignal.h

RESOURCES += \
    application.qrc

OTHER_FILES += \
    OldUsefulCode.txt \
    SQLQueries.txt

include ( ${QWT_ROOT}/features/qwt.prf )

QWT_ROOT = /usr/local/qwt-6.1.0
INCLUDEPATH += $${QWT_ROOT}/src
DEPENDPATH  += $${QWT_ROOT}/src

LIBS += /usr/local/qwt-6.1.0/lib/libqwt.so.6
//LIBS      += -F$${QWT_ROOT}/lib


