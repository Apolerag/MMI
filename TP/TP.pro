TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    contour.cpp \
    filtre.cpp \
    fonctionCorrespondance.cpp \
    histogramme.cpp \
    image.cpp \
    imagecouleur.cpp \
    imageniveauxgris.cpp \
    pixelcouleur.cpp

HEADERS += \
    contour.h \
    filtre.h \
    fonctionCorrespondance.h \
    histogramme.h \
    image.h \
    imagecouleur.h \
    imageniveauxgris.h \
    pixelcouleur.h

OTHER_FILES += \
    test.pgm \
    lena.pgm \
    res.pgm \
    barbara.ascii.pgm

