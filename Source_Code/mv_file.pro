QT       += core gui
QT += sql
QT += core gui
QT += widgets
QT += core



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    filedata.cpp \
    main.cpp \
    mainmv.cpp

HEADERS += \
    filedata.h \
    mainmv.h

FORMS += \
    mainmv.ui

TRANSLATIONS += \
    mv_file_pt_BR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
