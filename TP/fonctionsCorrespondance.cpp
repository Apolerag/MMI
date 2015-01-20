#include "fonctionsCorrespondance.h"
#include <iostream>

fonctionsCorrespondance::fonctionsCorrespondance(const ImageNiveauxGris &im): m_image(im), m_histogramme(im)
{
}

fonctionsCorrespondance::~fonctionsCorrespondance()
{
}

ImageNiveauxGris fonctionsCorrespondance::negatif()
{
    ImageNiveauxGris res(m_image);

    for(int i = 0; i < res.getNbColonnes(); i++) {
        for(int j = 0; j < res.getNbLignes(); j++) {
            res.elementTableauPixels(j,i) = res.getNiveauxIntensite() - res.elementTableauPixels(j,i);
        }
    }

    return res;
}

ImageNiveauxGris fonctionsCorrespondance::seuillage(const unsigned int seuil)
{
    ImageNiveauxGris res(m_image);

    for(int i = 0; i < res.getNbColonnes(); i++) {
        for(int j = 0; j < res.getNbLignes(); j++) {
            if(res.elementTableauPixels(j,i) > seuil)
                res.elementTableauPixels(j,i) = res.getNiveauxIntensite();
            else res.elementTableauPixels(j,i) = 0;
        }
    }

    return res;
}

ImageNiveauxGris fonctionsCorrespondance::translationPositive(const unsigned int pas)
{
    ImageNiveauxGris res(m_image);

    for(int i = 0; i < res.getNbColonnes(); i++) {
        for(int j = 0; j < res.getNbLignes(); j++) {
                res.elementTableauPixels(j,i) += pas;
                if(res.elementTableauPixels(j,i) > res.getNiveauxIntensite())
                    res.elementTableauPixels(j,i) = res.getNiveauxIntensite();
        }
    }

    return res;
}

ImageNiveauxGris fonctionsCorrespondance::translationNegative(const unsigned int pas)
{
    ImageNiveauxGris res(m_image);

    for(int i = 0; i < res.getNbColonnes(); i++) {
        for(int j = 0; j < res.getNbLignes(); j++) {
                if(res.elementTableauPixels(j,i) < pas){
                    res.elementTableauPixels(j,i) = 0;
                }
                else res.elementTableauPixels(j,i) -= pas;
        }
    }

    return res;
}
