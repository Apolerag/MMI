#ifndef FOURIER_H
#define FOURIER_H

#include <complex>
#include <vector>

#include "contour.h"
#include "imageniveauxgris.h"

class Fourier
{
private:
	

	int indiceDecale(int i) const;

public:

	std::vector< std::complex<double> > m_fourierDiscrete;
	std::vector< std::complex<double> > m_fourierRapide;
	int m_dataSize;

	Fourier();
	~Fourier();

	void calculeFourierDiscrete(const Contour & contour);
	void calculeFourierDiscrete(const ImageNiveauxGris & image);
	void calculeFourierRapide(const Contour & contour);
	void calculeFourierRapide(const ImageNiveauxGris & image);

	std::vector< std::complex<double> > calculeFourierDiscreteInverseContour() const;
};

#endif
