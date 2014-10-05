#include "image.h"

Image::Image() : m_nbColonnes(0), m_nbLignes(0), m_niveauxIntensite(0) 
{}

const int Image::getNbColonnes() const
{
    return m_nbColonnes;
}

const int Image::getNbLignes() const
{
    return m_nbLignes;
}

const int Image::getNiveauxIntensite() const
{
    return m_niveauxIntensite;
}
