#include "imageniveauxgris.h"
#include <fstream>
#include <iostream>

ImageNiveauxGris::ImageNiveauxGris(std::string nomFichierPGM)
{
    std::ifstream fichier;
    fichier.open(nomFichierPGM.c_str());  // on ouvre le fichier en lecture


    if(fichier)  // si l'ouverture a réussi
    {

        // instructions
        fichier.close();  // on ferme le fichier
    }
    else  // sinon
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
}

ImageNiveauxGris::~ImageNiveauxGris()
{
}


int & ImageNiveauxGris::elementTableauPixels(int ligne, int colonne)
{
    return m_tableauPixels[ligne * m_nbColonnes + colonne];
}

const int & ImageNiveauxGris::elementTableauPixels(int ligne, int colonne) const
{
    return m_tableauPixels[ligne * m_nbColonnes + colonne];
}
