TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle

QT += widgets

SOURCES += \
        finddialog.cpp \
        gotocelldialog.cpp \
        main.cpp \
        mainwindow.cpp \
        sortdialog.cpp

HEADERS += \
    finddialog.h \
    gotocelldialog.h \
    mainwindow.h \
    sortdialog.h

FORMS += \
    gotocelldialog.ui \
    sortdialog.ui
