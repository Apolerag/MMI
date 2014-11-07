#include "imageniveauxgris.h"
#include <fstream>
#include <iostream>

ImageNiveauxGris::ImageNiveauxGris(const std::string & nomFichierPGM)
{
    /** On considère pour le moment que le fichier ne contient pas de commentaires */

    int temp ;
    std::ifstream fichier;
    
    std::string extension = nomFichierPGM.substr(nomFichierPGM.length() - 3, 3);
    if((extension.compare("pgm") != 0) && (extension.compare("PGM") != 0)) {

        std::cerr << "Le fichier image n'est pas au format PGM." << std::endl;
        return;
    }

    fichier.open(nomFichierPGM.c_str());

    if(fichier)
    {
        std::string mode_encodage;
        fichier >> mode_encodage;

        if(mode_encodage.compare("P2") == 0) {
            
            fichier >> m_nbColonnes >> m_nbLignes >> m_niveauxIntensite;
            m_tableauPixels.resize(m_nbColonnes * m_nbLignes);

            for(int i = 0; i < m_nbLignes; i++) {
                for(int j = 0; j < m_nbColonnes; j++) {
                    
                    fichier >> temp ;
                    elementTableauPixels(i, j) = temp;
                }
            }
        } 
        else
             std::cerr << "Mauvais format de fichier." << std::endl;
        
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

void ImageNiveauxGris::sauverDansFichierPGM(std::string & nomFichierPGM) const 
{

    std::ofstream fichier;
    int compteur = 0;

    std::string extension = nomFichierPGM.substr(nomFichierPGM.length() - 3, 3);
    if((extension.compare("pgm") != 0) && (extension.compare("PGM") != 0))
        nomFichierPGM = nomFichierPGM + ".pgm";

    fichier.open(nomFichierPGM.c_str());

    if(fichier) {

        fichier << "P2" << std::endl << m_nbColonnes << " " << m_nbLignes 
            << " " << m_niveauxIntensite << std::endl;

        for(int i = 0; i < m_nbLignes; i++) {
            for(int j = 0; j < m_nbColonnes; j++) {

                if(compteur == 70) {
                    fichier << std::endl;
                    compteur = 0;
                }
                fichier << elementTableauPixels(i, j) << " ";
                compteur++;
            }
        }

        fichier.close();
    }
    else
        std::cerr << "Impossible d'ouvrir le fichier pour y écrire." << std::endl;

}
