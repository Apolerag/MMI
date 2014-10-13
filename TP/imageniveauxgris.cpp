#include "imageniveauxgris.h"
#include <fstream>
#include <iostream>

ImageNiveauxGris::ImageNiveauxGris(const std::string & nomFichierPGM)
{
    /** On considère pour le moment que le fichier ne contient pas de commentaires */

    std::ifstream fichier;
    // vérifier extension PGM
    fichier.open(nomFichierPGM.c_str());

    if(fichier)
    {
        std::string mode_encodage ;
        fichier >> mode_encodage ;

        if(mode_encodage.compare("P2") != 0) {
            std::cerr << "Le fichier est encodé en binaire, impossible de le lire !" << std::endl;
            return ;
        }

        int temp ;

        fichier >> m_nbColonnes >> m_nbLignes >> m_niveauxIntensite;
        m_tableauPixels.resize(m_nbColonnes * m_nbLignes);

        for(int i = 0; i < m_nbColonnes; i++) {
            for(int j = 0; j < m_nbLignes; j++) {
                fichier >> temp ;
                m_tableauPixels.push_back(temp);
            }
        }
        
        fichier.close();
    }
    else 
        std::cerr << "Impossible d'ouvrir le fichier pour le lire." << std::endl;
}

ImageNiveauxGris::~ImageNiveauxGris()
{
    std::vector<int>().swap(m_tableauPixels);
}


int & ImageNiveauxGris::elementTableauPixels(int ligne, int colonne)
{
    return m_tableauPixels[ligne * m_nbColonnes + colonne];
}

const int & ImageNiveauxGris::elementTableauPixels(int ligne, int colonne) const
{
    return m_tableauPixels[ligne * m_nbColonnes + colonne];
}

void ImageNiveauxGris::sauverDansFichierPGM(const std::string & nomFichierPGM) const 
{

    std::ofstream fichier;
    fichier.open((nomFichierPGM + ".pgm").c_str());

    if(fichier) {

        fichier << "P2" << m_nbColonnes << m_nbLignes << m_niveauxIntensite;
        for(int i = 0; i < m_nbColonnes; i++) {
            for(int j = 0; j < m_nbLignes; j++) {
                // voir comment revenir à la ligne
            }
        }

        fichier.close();
    }
    else
        std::cerr << "Impossible d'ouvrir le fichier pour écrire dedans." << std::endl;

}
