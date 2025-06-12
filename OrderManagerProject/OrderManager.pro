QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OrderManager
TEMPLATE = app

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/order.cpp

HEADERS += \
    src/mainwindow.h \
    src/order.h

FORMS += \
    ui/mainwindow.ui
