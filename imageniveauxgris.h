#ifndef IMAGENIVEAUXGRIS_H
#define IMAGENIVEAUXGRIS_H

#include "image.h"
#include <vector>

class ImageNiveauxGris : public Image
{
private:
    

public:
	std::vector<int> m_tableauPixels;
    ImageNiveauxGris(const int nbColonnes, const int nbLignes, const int niveauIntensite, const std::string & modeEncodage);
    ImageNiveauxGris(const std::string & nomFichierPGM);
    ImageNiveauxGris(const ImageNiveauxGris & image);
    ~ImageNiveauxGris();

    int & elementTableauPixels(int ligne, int colonne);
    const int & elementTableauPixels(int ligne, int colonne) const;
    const int & elementTableauPixels(int i) const;
    void sauverDansFichierPGM(std::string & nomFichierPGM) const;
};

#endif // IMAGENIVEAUXGRIS_H
