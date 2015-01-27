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
	bool m_contour ;

	int indiceDecale(int i, int size) const;
	int indiceDecale2D(int x, int y) const;
	std::vector<std::complex<double> > calculeFourierRapideLigne(bool inverse,
		const std::vector<std::complex<double> > & data) const;
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
	void calculeFourierRapide(const Contour & contour);
	void calculeFourierRapide(const Image & image);

	std::vector< std::complex<double> > calculeFourierDiscreteInverse() const;
	std::vector< std::complex<double> > calculeFourierRapideInverse() const;

	Image getImageFourier();

};

#endif
