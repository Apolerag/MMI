#ifndef IMAGENIVEAUXGRIS_H
#define IMAGENIVEAUXGRIS_H

#include "image.h"
#include <string>
#include <vector>

class ImageNiveauxGris : public Image
{
    std::vector<int> m_tableauPixels;

public:
    ImageNiveauxGris(std::string nomFichierPGM);
    ~ImageNiveauxGris();

    std::vector<int> getTableauPixels();
    int getElementTableauPixels(int ligne, int colonne);
};

#endif // IMAGENIVEAUXGRIS_H
