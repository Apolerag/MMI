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
    ImageNiveauxGris res(m_image.getNbColonnes(),m_image.getNbLignes(), m_image.getNiveauxIntensite(), m_image.getModeEncodage());

    for(int i = 0; i < res.getNbColonnes(); i++) {
        for(int j = 0; j < res.getNbLignes(); j++) {
            res.elementTableauPixels(j,i) = m_image.getNiveauxIntensite() - m_image.elementTableauPixels(j,i);
        }
    }

    return res;
}

ImageNiveauxGris fonctionsCorrespondance::seuillage(const unsigned int seuil)
{
    ImageNiveauxGris res(m_image.getNbColonnes(),m_image.getNbLignes(), m_image.getNiveauxIntensite(), m_image.getModeEncodage());

    for(int i = 0; i < res.getNbColonnes(); i++) {
        for(int j = 0; j < res.getNbLignes(); j++) {
            if(m_image.elementTableauPixels(j,i) > seuil)
                res.elementTableauPixels(j,i) = m_image.getNiveauxIntensite();
            else res.elementTableauPixels(j,i) = 0;
        }
    }

    return res;
}

ImageNiveauxGris fonctionsCorrespondance::translationPositive(const unsigned int pas)
{
    ImageNiveauxGris res(m_image.getNbColonnes(),m_image.getNbLignes(), m_image.getNiveauxIntensite(), m_image.getModeEncodage());

    for(int i = 0; i < res.getNbColonnes(); i++) {
        for(int j = 0; j < res.getNbLignes(); j++) {
                if(m_image.elementTableauPixels(j,i) + pas > m_image.getNiveauxIntensite())
                    res.elementTableauPixels(j,i) = m_image.getNiveauxIntensite();
                else res.elementTableauPixels(j,i) = m_image.elementTableauPixels(j,i) + pas;
        }
    }

    return res;
}

ImageNiveauxGris fonctionsCorrespondance::translationNegative(const unsigned int pas)
{
    ImageNiveauxGris res(m_image.getNbColonnes(),m_image.getNbLignes(), m_image.getNiveauxIntensite(), m_image.getModeEncodage());

    for(int i = 0; i < res.getNbColonnes(); i++) {
        for(int j = 0; j < res.getNbLignes(); j++) {
                if(m_image.elementTableauPixels(j,i) < pas){
                    res.elementTableauPixels(j,i) = 0;
                }
                else res.elementTableauPixels(j,i) = m_image.elementTableauPixels(j,i) - pas;
        }
    }

    return res;
}

ImageNiveauxGris fonctionsCorrespondance::recadrage(const unsigned int min, const unsigned int max)
{
    ImageNiveauxGris res(m_image.getNbColonnes(),m_image.getNbLignes(), m_image.getNiveauxIntensite(), m_image.getModeEncodage());

    for(int i = 0; i < res.getNbColonnes(); i++) {
        for(int j = 0; j < res.getNbLignes(); j++) {
                if(m_image.elementTableauPixels(j,i) < min){
                    res.elementTableauPixels(j,i) = 0;
                }
                else if(m_image.elementTableauPixels(j,i) > max){
                    res.elementTableauPixels(j,i) = m_image.getNiveauxIntensite()
                            ;
                }
                else res.elementTableauPixels(j,i) = m_image.elementTableauPixels(j,i);
        }
    }

    return res;
}
