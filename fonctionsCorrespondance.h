#ifndef FONCTION_CORRESPONDANCE_H
#define FONCTION_CORRESPONDANCE_H 

#include "image.h"
#include "histogramme.h"

class FonctionsCorrespondance
{
protected:
    ImageNiveauxGris m_image;
    std::vector<int> m_fonction;
public:
    FonctionsCorrespondance(const ImageNiveauxGris & im);
    ~FonctionsCorrespondance();

    ImageNiveauxGris negatif();
    ImageNiveauxGris seuillage(const unsigned int seuil);
    ImageNiveauxGris translationPositive(const unsigned int pas);
    ImageNiveauxGris translationNegative(const unsigned int pas);
    ImageNiveauxGris recadrage(const unsigned int min, const unsigned int max);
};

#endif
