/**
 * @file fonctionsCorrespondance.cpp
 * @authors Aurélien CHEMIER, Romane LHOMME
 * @date janvier 2015
 */
#include "fonctionsCorrespondance.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h> 

FonctionsCorrespondance::FonctionsCorrespondance(const Image &im): m_image(im), m_histogramme(im)
{
    m_fonction.resize(m_image.getNiveauxIntensite(),0);
}

FonctionsCorrespondance::~FonctionsCorrespondance()
{
    std::vector<int>().swap(m_fonction);
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

Image FonctionsCorrespondance::seuillage(const unsigned int seuil)
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

Image FonctionsCorrespondance::recadrage(const unsigned int min, const unsigned int max)
{
    Image res(m_image.getNbColonnes(),m_image.getNbLignes(), m_image.getNiveauxIntensite(), m_image.getModeEncodage());

    for(unsigned int i = 0; i < m_fonction.size(); i++){
        if(i <= min ){
            m_fonction[i] = 0;
        }
        else if(i >= max) {
            m_fonction[i] = m_image.getNiveauxIntensite();
        }
        else {
            m_fonction[i] = m_image.getNiveauxIntensite()*i/(max-min) - min*m_image.getNiveauxIntensite()/(max-min);
        }
    }

    for(unsigned int i = 0; i < res.getNbColonnes(); i++) {
        for(unsigned int j = 0; j < res.getNbLignes(); j++) {
                res.elementTableauPixels(j,i) = m_fonction[m_image.elementTableauPixels(j,i)];
        }
    }

    return res;
}


Image FonctionsCorrespondance::egalisationHistogramme()
 {
    Image res(m_image.getNbColonnes(),m_image.getNbLignes(), m_image.getNiveauxIntensite(), m_image.getModeEncodage());

    for(unsigned int i = 0; i < m_fonction.size(); i++){
        m_fonction[i] = m_image.getNiveauxIntensite()*m_histogramme.getCumule(i)/(m_image.getNbColonnes()*m_image.getNbLignes());
    }

    for(unsigned int i = 0; i < m_fonction.size(); i++){
        std::cout << m_fonction[i] <<" ";
    }
    std::cout<<std::endl;

    for(unsigned int i = 0; i < res.getNbColonnes(); i++) {
        for(unsigned int j = 0; j < res.getNbLignes(); j++) {
                res.elementTableauPixels(j,i) = m_fonction[m_image.elementTableauPixels(j,i)];
        }
    }

    return res;
 }
