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
 * @brief Permet l'application de fonctions de correspondance sur une Image
  */
class FonctionsCorrespondance
{


protected:
    /**
     * @brief Une image en niveau de gris
     */
    Image m_image;
    
public:

    /**
     * @brief Constructeur de  FonctionsCorrespondance
     * 
     * @param im l'image à modifiée
     */
    FonctionsCorrespondance(const Image & im);
    /**
     * @brief Destructeur de FonctionsCorrespondance
     */
    ~FonctionsCorrespondance();

    /**
     * @brief Calcule le négatif de l'image
     * @details Pour chaque pixel \f$ p \f$ de l'image, les pixels \f$ p'\f$  de l'image résultante prenne la valeur: \f$ m\_niveauxIntensite - p\f$ 
     * @return l'image négative de m_image
     */
    Image negatif();

    /**
     * @brief Seuille l'image en fonction de l'entier seuil
     * @details Pour chaque pixel \f$ p \f$ de l'image, Si \f$ p > seuil \Rightarrow p' = m\_niveauxIntensite \f$. Sinon \f$  p' = 0 \f$.
     * 
     * @param seuil la valeur du seuil
     * @return l'image seuillée de m_image
     */
    Image seuillage(const int seuil);

    /**
     * @brief Modifie les pixels de l'image en fonctions d'un pas
     * @details Pour chaque pixel de l'image, on ajoute la valeur de pas en controlant la valeur en sortie
     * 
     * @param pas le pas de la translation (peut être négatif)
     * @return l'image translatée
     */
    Image translation(const int pas);

    /**
     * @brief Améliore la dynamique des images de niveau de gris
     * @details 
     * Etend les valeurs des pixels de [min,max] à [0,m_niveauxIntensite] en conservant la dynamique de l'Histogramme.
     * 
     * Préconisé sur les images dont l’Histogramme d’origine est nul en dehors de l’intervalle [min,max].
     * 
     * @param min l'extrémité basse du recadrage
     * @param max l'extrémité haute du recadrage
     * 
     * @return l'image recadrée
     */
    Image recadrage(const int min, const int max);

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
    Image egalisationHistogramme();
};

#endif
