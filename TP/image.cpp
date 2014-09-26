#include "image.h"

Image::Image(int ligne, int colonne,  int niveauIntensite) : m_nbLignes(ligne), m_nbColonnes(colonne), m_niveauxIntensite(niveauIntensite)
{
}

Image::~Image()
{
}

const int Image::getNbColonnes() {
    return m_nbColonnes;
}

const int Image::getNbLignes() {
    return m_nbLignes;
}

const int Image::getNiveauxIntensite(){
    return m_niveauxIntensite;
}
