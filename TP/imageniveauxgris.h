#ifndef IMAGENIVEAUXGRIS_H
#define IMAGENIVEAUXGRIS_H

#include "image.h"
#include <string>
#include <vector>

class ImageNiveauxGris : public Image
{
private:
    std::vector<int> m_tableauPixels;

public:
    ImageNiveauxGris(const std::string & nomFichierPGM);
    ~ImageNiveauxGris();


    int & elementTableauPixels(int ligne, int colonne);
    const int & elementTableauPixels(int ligne, int colonne) const;
};

#endif // IMAGENIVEAUXGRIS_H
