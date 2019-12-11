#-------------------------------------------------
#
# Project created by QtCreator 2019-11-08T21:40:24
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet_Qt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    auteur.cpp \
    livre.cpp \
    connexion.cpp \
    personnel.cpp \
    dialog_auteur.cpp \
    dialog_home.cpp \
    dialog_livre.cpp \
    dialog_inscription.cpp \
    dialog_personnel.cpp \
    dialog_exemplaire.cpp \
    exemplaire.cpp \
    departement.cpp \
    dialog_departement.cpp

HEADERS += \
        mainwindow.h \
    auteur.h \
    livre.h \
    connexion.h \
    personnel.h \
    dialog_auteur.h \
    dialog_home.h \
    dialog_livre.h \
    dialog_inscription.h \
    dialog_personnel.h \
    dialog_exemplaire.h \
    exemplaire.h \
    departement.h \
    dialog_departement.h

FORMS += \
        mainwindow.ui \
    dialog_auteur.ui \
    dialog_home.ui \
    dialog_livre.ui \
    dialog_inscription.ui \
    dialog_personnel.ui \
    dialog_exemplaire.ui \
    dialog_departement.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
