/**
 * @file fonctionsCorrespondance.h
 * @authors Aurélien CHEMIER, Romane LHOMME
 * @date janvier 2015
 */
#ifndef FONCTION_CORRESPONDANCE_H
#define FONCTION_CORRESPONDANCE_H 

#include "image.h"
#include "histogramme.h"


/**
 * @class FonctionsCorrespondance
 * @brief Permet l'application de fonctions de correspondance sur une image
 * 
 * @param im une ImageNiveauxGris
 * @return Une image sur laquelle une fonction de correspondance a été appliquée
 */
class FonctionsCorrespondance
{


protected:
    /**
     * @brief Une image en niveau de gris
     */
    ImageNiveauxGris m_image;
    /**
     * @brief La fonction de correspondance appliquée
     */
    std::vector<int> m_fonction;
    /**
     * @brief l'Histogramme de l'image
     */
    Histogramme m_histogramme;
public:

    /**
     * @brief Constructeur de  FonctionsCorrespondance
     * 
     * @param im l'image à modifiée
     */
    FonctionsCorrespondance(const ImageNiveauxGris & im);
    /**
     * @brief Destructeur de FonctionsCorrespondance
     */
    ~FonctionsCorrespondance();

    /**
     * @brief Calcule le négatif de l'image
     * @details Pour chaque pixel p de l'image, les pixels p' de l'image résultante prenne la valeur: m_niveauxIntensite - p
     * @return l'image négative de m_image
     */
    ImageNiveauxGris negatif();

    /**
     * @brief Seuille l'image en fonction de l'entier seuil
     * @details Pour chaque pixel \f$ p \f$ de l'image, Si \f$ p > seuil \Rightarrow p' = m\_niveauxIntensite \f$. Sinon \f$  p' = 0 \f$.
     * 
     * @param seuil la valeur du seuil
     * @return l'image seuillée de m_image
     */
    ImageNiveauxGris seuillage(const unsigned int seuil);

    /**
     * @brief Modifie les pixels de l'image en fonctions d'un pas
     * @details Pour chaque pixel de l'image, on ajoute la valeur de pas en controlant la valeur en sortie
     * 
     * @param pas le pas de la translation (peut être négatif)
     * @return l'image translatée
     */
    ImageNiveauxGris translation(const int pas);

    /**
     * @brief Améliore la dynamique des images de niveau de gris
     * @details 
     * Etend les valeurs des pixels de [min,max] à [0,m_niveauxIntensite] en conservant la dynamique de l'Histogramme.
     * 
     * Préconisé sur les images dont l’histogramme d’origine est nul en dehors de l’intervalle [min,max].
     * 
     * @param min l'extrémité basse du recadrage
     * @param max l'extrémité haute du recadrage
     * 
     * @return l'image recadrée
     */
    ImageNiveauxGris recadrage(const unsigned int min, const unsigned int max);

    /**
     * @brief Equilibre les valeurs de l'Histogramme
     * @details 
     * Redistribue les valeurs entre [0,m_niveauxIntensite].
     * Une dynamique plus grande est réservée aux niveaux les plus fréquents.
     * 
     * Utilise l'Histogramme cumulé \f$C\f$ de l'image pour calculer la fonction de correspondance.
     * 
     * 
     * \f$ f(k)= \frac{m\_niveauxIntensite * C(k)}{nb\_pixels} \f$
     * 
     * @return l'image égalisée
     */
    ImageNiveauxGris egalisationHistogramme();
};

#endif
