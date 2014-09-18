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

std::vector<int> ImageNiveauxGris::getTableauPixels()
{
}

int ImageNiveauxGris::getElementTableauPixels(int ligne, int colonne)
{
}
