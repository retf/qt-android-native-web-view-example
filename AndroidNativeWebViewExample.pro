#-------------------------------------------------
#
# Project created by QtCreator 2014-06-03T10:17:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

android: QT += androidextras

android: ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

TARGET = AndroidNativeWebViewExample
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    QtCustomAndroidWebView.cpp \
    AndroidNativeCallsSender.cpp

HEADERS  += mainwindow.h \
    QtCustomAndroidWebView.h \
    AndroidNativeCallsSender.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

OTHER_FILES += \
    android/AndroidManifest.xml

