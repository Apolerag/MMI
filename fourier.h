#ifndef FOURIER_H
#define FOURIER_H

#include <complex>
#include <vector>

#include "contour.h"
#include "image.h"

class Fourier
{
private:
	
	std::vector< std::complex<double> > m_fourier;
	int m_dataWidth;
	int m_dataHeight;
	bool m_contour ;

	int indiceDecale(int i, int size) const;
	std::vector<std::complex<double> > calculeFourierRapideLigne(bool inverse,
		const std::vector<std::complex<double> > & data) const;

public:

	Fourier();
	~Fourier();

	const int getTailleTableau();
	const int getWitdh();
	const int getHeight();
	std::complex<double>  & elementFourier(const int i);

	void calculeFourierDiscrete(const Contour & contour);
	void calculeFourierRapide(const Contour & contour);
	void calculeFourierRapide(const Image & image);

	std::vector< std::complex<double> > calculeFourierDiscreteInverse() const;
	std::vector< std::complex<double> > calculeFourierRapideInverse() const;

};

#endif
