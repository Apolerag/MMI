#include "imageniveauxgris.h"
#include <fstream>
#include <iostream>

ImageNiveauxGris::ImageNiveauxGris(const std::string & nomFichierPGM)
{
    /** On considère pour le moment que le fichier ne contient pas de commentaires */

    int temp ;
    std::ifstream fichier;
    // vérifier extension PGM
    fichier.open(nomFichierPGM.c_str());

    if(fichier)
    {
        std::string mode_encodage ;
        fichier >> mode_encodage ;
        std::cout << "mode_encodage "<<mode_encodage<<std::endl;
      /*  if(mode_encodage.compare("P5") == 0) {
            short int pixel = 0;
          //  std::cerr << "Le fichier est encodé en binaire, impossible de le lire !" << std::endl;
            fichier >> m_nbColonnes >> m_nbLignes >> m_niveauxIntensite;
            m_tableauPixels.resize(m_nbColonnes * m_nbLignes);
            for(int i = 0; i < m_nbColonnes; i++) {
                for(int j = 0; j < m_nbLignes; j++) {
                    fichier >> pixel ;

                   // std::cout << "p "<<pixel<<std::endl;
                    
                    
                    m_tableauPixels.push_back(pixel);
                       
                    //std::cout<<temp<<std::endl;
                }
            }
        }
        else */if(mode_encodage.compare("P2") == 0) {
           // std::cout << "comprend " <<mode_encodage<<std::endl;
            fichier >> m_nbColonnes >> m_nbLignes >> m_niveauxIntensite;
            m_tableauPixels.resize(m_nbColonnes * m_nbLignes);

            for(int i = 0; i < m_nbColonnes; i++) {
                for(int j = 0; j < m_nbLignes; j++) {
                    fichier >> temp ;
          //  std::cout << "comprend " <<temp<<std::endl;
                    //m_tableauPixels.push_back(temp);
                    elementTableauPixels(j, i) = temp;
                }
            }
        } else
        {
             std::cerr << "Mauvais format de fichier." << std::endl;
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

        fichier << "P2 \n" << m_nbColonnes <<" "
            << m_nbLignes <<" "<< m_niveauxIntensite<<" \n";
        for(int i = 0; i < m_nbColonnes; i++) {
            for(int j = 0; j < m_nbLignes; j++) {
                fichier << elementTableauPixels(j, i) <<" ";
            }
        }

        fichier.close();
    }
    else
        std::cerr << "Impossible d'ouvrir le fichier pour écrire dedans." << std::endl;

}
