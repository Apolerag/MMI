/**
 * @file filtre.h
 * @authors Aurélien CHEMIER, Romane LHOMME
 * @date janvier 2015
 */

#ifndef FILTRE_H
#define FILTRE_H

 #include "fourier.h"

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
	Fourier &m_fourier;
	/**
	 * @brief le filtre appliqué
	 */
	std::vector< double> m_filtre;

	/**
	 * @brief applique le filtre calculé sur Fourier
	 */
	void appliqueFiltre();

public:

	/**
	 * @brief Constructeur du filtre
	 * 
	 * @param fourier l'image à filtrer
	 */
	Filtre(Fourier &fourier);
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
	 * @brief Calcule le filtre de passe Bande Idéal de taille \f$ [rayonMin; rayonMax] \f$
	 * 
	 * @param rayon le rayon du filtre
	 */
	void passeBandeIdeal(const double rayonMin, const double rayonMax);

	/**
	 * @brief Calcule le filtre de passe Bas Gaussien de taille \f$  rayon \f$
	 * 
	 * @param rayon le rayon du filtre
	 */
	void passeBasGaussien(const double rayon);

	/**
	 * @brief renvoie le Fourier stocké
	 */
	Fourier returnFourier();
};

#endif
