#ifndef IMAGENIVEAUXGRIS_H
#define IMAGENIVEAUXGRIS_H

#include "image.h"
#include <vector>

class ImageNiveauxGris : public Image
{
private:
    std::vector<int> m_tableauPixels;

public:
    ImageNiveauxGris(const int nbColonnes, const int nbLignes, const int niveauIntensite, const std::string & modeEncodage);
    ImageNiveauxGris(const std::string & nomFichierPGM);
    ImageNiveauxGris(const ImageNiveauxGris & image);
    ~ImageNiveauxGris();


    int & elementTableauPixels(int ligne, int colonne);
    const int & elementTableauPixels(int ligne, int colonne) const;
    void sauverDansFichierPGM(std::string & nomFichierPGM) const;
};

#endif // IMAGENIVEAUXGRIS_H
