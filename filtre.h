/**
 * @file filtre.h
 * @authors Aurélien CHEMIER, Romane LHOMME
 * @date janvier 2015
 */

#ifndef FILTRE_H
#define FILTRE_H

#include "contour.h"

/**
 * @class Filtre
 * @brief permet d'appliquer un filtre sur une Image dans le modèle fréquentiel
 * 
 */
class Filtre
{
private:
	/**
	 * @brief l'image dans le domaine frequentiel
	 */
	std::vector< std::complex<double> > m_pointsComplexes;
	/**
	 * @brief le filtre appliqué
	 */
	std::vector< double> m_filtre;
public:

	/**
	 * @brief Constructeur du filtre
	 * 
	 * @param pointsComplexes l'image à filtrer
	 */
	Filtre(const std::vector< std::complex<double> > &pointsComplexes);
	/**
	 * @brief Destructeur
	 */
	~Filtre();

	/**
	 * @brief Calcule le filtre de passe Bas Idéal de taille \f$  rayon \f$
	 * 
	 * @param rayon le rayon du filtre
	 */
	void passeBasIdeal(const double rayon);
	/**
	 * @brief Calcule le filtre de passe Haut Idéal de taille \f$ rayon \f$
	 * 
	 * @param rayon le rayon du filtre
	 */
	void passeHautIdeal(const double rayon);

	/**
	 * @brief applique le filtre calculé sur l'image
	 * @return l'image filtrée
	 */
	std::vector< std::complex<double> > appliqueFiltre();

};

#endif
