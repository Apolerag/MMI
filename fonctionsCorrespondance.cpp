/**
 * @file fonctionsCorrespondance.cpp
 * @authors Aurélien CHEMIER, Romane LHOMME
 * @date janvier 2015
 */
#include "fonctionsCorrespondance.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h> 

FonctionsCorrespondance::FonctionsCorrespondance(const Image &im): m_image(im)
{
}

FonctionsCorrespondance::~FonctionsCorrespondance()
{   
}

Image FonctionsCorrespondance::negatif()
{
    Image res(m_image.getNbColonnes(),m_image.getNbLignes(), m_image.getNiveauxIntensite(), m_image.getModeEncodage());

    for(int i = 0; i < res.getNbColonnes(); i++) {
        for(int j = 0; j < res.getNbLignes(); j++) {
            res.elementTableauPixels(j,i) = m_image.getNiveauxIntensite() - m_image.elementTableauPixels(j,i);
        }
    }

    return res;
}

Image FonctionsCorrespondance::seuillage(const int seuil)
{
    Image res(m_image.getNbColonnes(),m_image.getNbLignes(), m_image.getNiveauxIntensite(), m_image.getModeEncodage());

    for(int i = 0; i < res.getNbColonnes(); i++) {
        for(int j = 0; j < res.getNbLignes(); j++) {
            if(m_image.elementTableauPixels(j,i) > seuil)
                res.elementTableauPixels(j,i) = m_image.getNiveauxIntensite();
            else res.elementTableauPixels(j,i) = 0;
        }
    }

    return res;
}

Image FonctionsCorrespondance::translation(const int pas)
{
    Image res(m_image.getNbColonnes(),m_image.getNbLignes(), m_image.getNiveauxIntensite(), m_image.getModeEncodage());
    for(int i = 0; i < res.getNbColonnes(); i++) {
        for(int j = 0; j < res.getNbLignes(); j++) {
            if((m_image.elementTableauPixels(j,i) < abs(pas) ) && (pas < 0)) //cas où la pas est négatif
                res.elementTableauPixels(j,i) = 0;
            else  if(m_image.elementTableauPixels(j,i) + pas > m_image.getNiveauxIntensite())
                res.elementTableauPixels(j,i) = m_image.getNiveauxIntensite();
            else res.elementTableauPixels(j,i) = m_image.elementTableauPixels(j,i) + pas;
        }
    }

    return res;
}

Image FonctionsCorrespondance::recadrage(const int min, const int max)
{
    Image res(m_image.getNbColonnes(),m_image.getNbLignes(), m_image.getNiveauxIntensite(), m_image.getModeEncodage());
     std::vector<int> fonction;
     fonction.resize(m_image.getNiveauxIntensite(),0);

    for(int i = 0; i < fonction.size(); i++){
        if(i <= min ){
            fonction[i] = 0;
        }
        else if(i >= max) {
            fonction[i] = m_image.getNiveauxIntensite();
        }
        else {
            fonction[i] = m_image.getNiveauxIntensite()*i/(max-min) - min*m_image.getNiveauxIntensite()/(max-min);
        }
    }

    for(int i = 0; i < res.getNbColonnes(); i++) {
        for(int j = 0; j < res.getNbLignes(); j++) {
                res.elementTableauPixels(j,i) = fonction[m_image.elementTableauPixels(j,i)];
        }
    }

    return res;
}


Image FonctionsCorrespondance::egalisationHistogramme()
 {
    Image res(m_image.getNbColonnes(),m_image.getNbLignes(), m_image.getNiveauxIntensite(), m_image.getModeEncodage());
    Histogramme histo(m_image);
    std::vector<int> fonction;
    fonction.resize(m_image.getNiveauxIntensite(),0);

    for(int i = 0; i < fonction.size(); i++){
        fonction[i] = m_image.getNiveauxIntensite()*histo.getCumule(i)/(m_image.getNbColonnes()*m_image.getNbLignes());
    }

    for(int i = 0; i < res.getNbColonnes(); i++) {
        for(int j = 0; j < res.getNbLignes(); j++) {
                res.elementTableauPixels(j,i) = fonction[m_image.elementTableauPixels(j,i)];
        }
    }

    return res;
 }
