#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>

class Image {

    int m_nbColonnes;
    int m_nbLignes;

    std::vector<int> m_tableauPixels;

public :

    Image(std::string nomFichier);
    ~Image();

    int getNbColonnes();
    int getNbLignes();
    std::vector<int> getTableauPixels();
    int getElementDansTableauPixels(int ligne, int colonne);

};

#endif // IMAGE_H
