#ifndef FOURIER_H
#define FOURIER_H

#include <complex>
#include <vector>

#include "contour.h"
#include "imageniveauxgris.h"

class Fourier
{
private:
	
	std::vector< std::complex<double> > m_fourier;
	int m_dataWidth;
	int m_dataHeight;
	bool contour ;

	int indiceDecale(int i, int size) const;
	std::vector<std::complex<double> > calculeFourierRapideLigne(bool inverse,
		const std::vector<std::complex<double> > & data) const;

public:

	Fourier();
	~Fourier();

	void calculeFourierDiscrete(const Contour & contour);
	void calculeFourierRapide(const Contour & contour);
	void calculeFourierRapide(const ImageNiveauxGris & image);

	std::vector< std::complex<double> > calculeFourierDiscreteInverse() const;
	std::vector< std::complex<double> > calculeFourierRapideInverse() const;

};

#endif
