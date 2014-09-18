#include <iostream>
#include <fstream>
#include "Image.h"

Image::Image(std::string nomFichier) {
    std::ifstream fichier(nomFichier, ios::in);  // on ouvre le fichier en lecture

         if(fichier)  // si l'ouverture a réussi
         {
             // instructions
                 fichier.close();  // on ferme le fichier
         }
         else  // sinon
                 std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;

}

Image::~Image() {
    m_tableauPixels.~vector();
}

int Image::getNbColonnes() {
    return m_nbColonnes;
}

int Image::getNbLignes() {
    return m_nbLignes;
}

std::vector<int> Image::getTableauPixels() {
    return m_tableauPixels;
}

int Image::getElementDansTableauPixels(int ligne, int colonne) {
    return m_tableauPixels[(ligne * m_nbColonnes) + colonne];
}
