#ifndef IMAGECOULEUR_H
#define IMAGECOULEUR_H

#include "image.h"
#include "pixelcouleur.h"
#include <string>
#include <vector>

class ImageCouleur : public Image
{
private:
    std::vector<PixelCouleur> m_tableauPixels ;

public:
    ImageCouleur(std::string nomFichierPPM);
    ~ImageCouleur();

    std::vector<PixelCouleur> getTableauPixels();
    PixelCouleur getElementTableauPixels(int ligne, int colonne);
};

#endif // IMAGECOULEUR_H
