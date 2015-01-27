#ifndef FOURIER_H
#define FOURIER_H

#include <complex>
#include <vector>

#include "contour.h"
#include "image.h"

class Fourier
{
private:
	

	int indiceDecale(int i, int size) const;
	std::vector<std::complex<double> > calculeFourierRapideRec(
		const std::vector<std::complex<double> > & data);

public:

	std::vector< std::complex<double> > m_fourier;
	int m_dataWidth;
	int m_dataHeight;

	Fourier();
	~Fourier();

	const int getTailleTableau();
	const int getWitdh();
	const int getHeight();
	std::complex<double>  & elementFourier(const int i);

	void calculeFourierDiscrete(const Contour & contour);
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
