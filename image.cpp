#include "image.h"

Image::Image() : m_nbColonnes(0), m_nbLignes(0), m_niveauxIntensite(0) 
{}

Image::Image(const int nbColonnes, const int nbLignes, const int niveauIntensite, const std::string & modeEncodage):
 m_mode_encodage(modeEncodage), m_nbColonnes(nbColonnes), m_nbLignes(nbLignes), m_niveauxIntensite(niveauIntensite)
{}

Image::~Image() 
{}

const unsigned int Image::getNbColonnes() const
{
    return m_nbColonnes;
}

const unsigned int Image::getNbLignes() const
{
    return m_nbLignes;
}

const unsigned int Image::getNiveauxIntensite() const
{
    return m_niveauxIntensite;
}

const std::string Image::getModeEncodage() const
{
    return m_mode_encodage;
}
