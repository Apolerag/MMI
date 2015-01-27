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
	

	int indiceDecale(int i, int size) const;
	std::vector<std::complex<double> > calculeFourierRapideRec(
		const std::vector<std::complex<double> > & data);

public:
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
	std::vector<std::complex<double> > fftinverse();
	Image fftinverseImg();
	void calculeFourierRapide(const Image & image);

	Image & getImageAmplitude();
	Image & getImagePhase();

	std::vector< std::complex<double> > calculeFourierInverse() const;

	std::vector<std::complex<double> > calculeFourierRapideLigne(
	const std::vector<std::complex<double> > & data, bool inverse);
};

#endif
