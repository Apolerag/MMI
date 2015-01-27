#ifndef FOURIER_H
#define FOURIER_H

#include <complex>
#include <vector>

#include "contour.h"
#include "imageniveauxgris.h"

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

	void calculeFourierDiscrete(const Contour & contour);
	void calculeFourierDiscrete(const ImageNiveauxGris & image);
	void calculeFourierRapide(const Contour & contour);
	std::vector<std::complex<double> > fftinverse();
	ImageNiveauxGris fftinverseImg();
	void calculeFourierRapide(const ImageNiveauxGris & image);

	ImageNiveauxGris & getImageAmplitude();
	ImageNiveauxGris & getImagePhase();

	std::vector< std::complex<double> > calculeFourierInverse() const;

	std::vector<std::complex<double> > calculeFourierRapideLigne(
	const std::vector<std::complex<double> > & data, bool inverse);
};

#endif
