TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp \
    contour.cpp \
    filtre.cpp \
    fonctionsCorrespondance.cpp \
    histogramme.cpp \
    image.cpp \
    imagecouleur.cpp \
    imageniveauxgris.cpp \
    pixelcouleur.cpp

HEADERS += \
    contour.h \
    filtre.h \
    fonctionsCorrespondance.h \
    histogramme.h \
    image.h \
    imagecouleur.h \
    imageniveauxgris.h \
    pixelcouleur.h

OTHER_FILES += \
    test.pgm \
    lena.pgm \
    res.pgm \
    barbara.ascii.pgm \
    res.txt \
    histogramme.txt

