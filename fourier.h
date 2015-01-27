/**
 * @file fourier.h
 * @authors Aurélien CHEMIER, Romane LHOMME
 * @date janvier 2015
 */
#ifndef FOURIER_H
#define FOURIER_H

#include <complex>
#include <vector>

#include "contour.h"
#include "image.h"

/**
 * @brief permet de calculer la transformée de Fourier en 2D
 */
class Fourier
{
private:
	
	/**
	 * @brief le résultat de la transformée de Fourier
	 */
	std::vector< std::complex<double> > m_fourier;
	/**
	 * @brief largeur de l'image
	 */
	int m_dataWidth;
	/**
	 * @brief hauteur de l'image (0 si 1D)
	 */
	int m_dataHeight;

	/**
	 * @brief indique si on traite un Contour ou une Image pour calculeFourierRapideInverse()
	 */
	bool m_contour ;

	/**
	 * @brief trouve la position i dans le tableau (i peut etre négatif)
	 * 
	 * @param i le i ème éléments transformée
	 * @param size la taille du tableau
	 * 
	 * @return la i ème position du tableau
	 */
	int indiceDecale(int i, int size) const;

	/**
	 * @brief trouve la position x y dans le tableau (point 2D dans tableau 1D)
	 * 
	 * @param x la ligne
	 * @param y la colonne 
	 * 
	 * @return la x*y ème position du tableau
	 */
	int indiceDecale2D(int x, int y) const;

	/**
	 * @brief calcule la transformée de Fourier rapide sur une ligne
	 * 
	 * @param inverse indique s'il s'agit de la tansformée ou de son inverse
	 * @param data [description]
	 * 
	 * @return [description]
	 */
	std::vector<std::complex<double> > calculeFourierRapideLigne(bool inverse,
		const std::vector<std::complex<double> > & data) const;

	/**
	 * @brief place les hautes fréquences dans le centres de l'image
	 * @return la transformée recentrée
	 */
	std::vector<std::complex<double> > fourierRapideShift();

public:
	

	/**
	 * @brief Constructeur
	 */
	Fourier();
	/**
	 * @brief Destructeur
	 */
	~Fourier();

	/* getter*/
	const int getTailleTableau();
	const int getWitdh();
	const int getHeight();
	std::complex<double>  & elementFourier(const int i);

	/**
	 * @brief Calcule la transformée de Fourier discrète sur un Contour
	 * 
	 * @param contour un Contour
	 */
	void calculeFourierDiscrete(const Contour & contour);

	/**
	 * @brief Calcule la transformée de Fourier discrète sur une Image
	 * 
	 * @param image une Image
	 */
	void calculeFourierDiscrete(const Image & image);

	/**
	 * @brief Calcule la transformée de Fourier rapide sur un Contour
	 * 
	 * @param contour un Contour
	 */
	void calculeFourierRapide(const Contour & contour);

	/**
	 * @brief Calcule la transformée de Fourier rapide sur une Image
	 * 
	 * @param contour un Contour
	 */
	void calculeFourierRapide(const Image & image);

	/**
	 * @brief fait l'inverse de calculeFourierDiscrete
	 */
	std::vector< std::complex<double> > calculeFourierDiscreteInverse() const;

	/**
	 * @brief fait l'inverse de calculeFourierRapide
	 */
	std::vector< std::complex<double> > calculeFourierRapideInverse() const;

	/**
	 * @brief stocke le spectre de la transformée de Fourier dans une Image 
	 * @return Une Image 
	 */
	Image getImageFourier();
	Image getImageApresFourierInverse();

};

#endif
