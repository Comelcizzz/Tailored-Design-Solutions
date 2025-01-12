QT       += core gui
RC_ICONS = myappico.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    auth.cpp \
    customerwindow.cpp \
    databasemanager.cpp \
    inspectorwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    orderdetails.cpp \
    signinwindow.cpp \
    signupwindow.cpp \
    workerwindow.cpp

HEADERS += \
    auth.h \
    customerwindow.h \
    databasemanager.h \
    inspectorwindow.h \
    mainwindow.h \
    orderdetails.h \
    signinwindow.h \
    signupwindow.h \
    workerwindow.h

FORMS += \
    customerwindow.ui \
    inspectorwindow.ui \
    mainwindow.ui \
    signinwindow.ui \
    signupwindow.ui \
    workerwindow.ui

QT += core gui sql

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES +=

MOC_DIR = moc
RCC_DIR = rcc
UI_DIR = ui
unix:OBJECTS_DIR = unix
win32:OBJECTS_DIR = win32
macx:OBJECTS_DIR = mac

CONFIG(release, debug|release) {
    win32:QMAKE_POST_LINK = $$(QTDIR)/bin/windeployqt $$OUT_PWD/release
}
