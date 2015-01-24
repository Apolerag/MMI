#include "fourier.h"

#include <iostream>

Fourier::Fourier() : m_dataSize(0) {

}

Fourier::~Fourier() {

	std::vector< std::complex<double> >().swap(m_fourierDiscrete);
	std::vector< std::complex<double> >().swap(m_fourierRapide);
}

int Fourier::indiceDecale(int i) const {

	int indice = (i >= 0) ?  i : m_dataSize + i;
	return indice;
}

void Fourier::calculeFourierDiscrete(const Contour & contour) {
	
	m_dataSize = contour.getDataSize();
	m_fourierDiscrete.resize(m_dataSize);

	std::complex<double> s_m, i(0, 1);
	int m, n, borneMin = -m_dataSize/2 - ((m_dataSize%2 == 0)? 0 : 1);

	std::cout << "m_dataSize = " << m_dataSize << std::endl;
	for(m = borneMin; m < m_dataSize/2; m++) {
		s_m = 0;
		for(n = 0; n < m_dataSize; n++) {
			s_m += contour(n) * exp(-i * (2.f * M_PI * m * n / m_dataSize));
		}
		s_m *= 1.f/m_dataSize;
		std::cout << " m = " << m << " / " << indiceDecale(m) << std::endl;
		m_fourierDiscrete[indiceDecale(m)] = s_m;
	}
}

std::vector< std::complex<double> > Fourier::calculeFourierDiscreteInverseContour() const {

	std::vector< std::complex<double> > inverse;
	inverse.resize(m_dataSize);


	std::complex<double> s_n, i(0, 1);
	int m, n, borneMin = -m_dataSize/2 - ((m_dataSize%2 == 0)? 0 : 1);

	for(n = 0; n < m_dataSize; n++) {
		s_n = 0;
		for(m = borneMin; m < m_dataSize/2; m++) {
			s_n += m_fourierDiscrete[indiceDecale(m)] 
				* exp(i * (2.f * M_PI * m * n / m_dataSize));
		}
		inverse[n] = s_n;
	}

	return inverse;
}

/*

// Extension des contours aux images 2D 
void Contour::calculeFFT()
{
	//copie du tableau complexes en paramettre 
}

std::vector< std::complex<double> > Contour::calculeFFTrec(const 
	std::vector< std::complex<double> > & points)
{
	if(points.size() == 1) {
		return points;
	}
	else {
		// Division en deux tableaux
		std::vector< std::complex<double> > premierePartie;
		std::vector< std::complex<double> > deuxiemePartie;
		for(int i = 0; i < points.size(); i++) {
			if((i % 2) == 0)
				premierePartie.push_back(points[i]);
			else
				deuxiemePartie.push_back(points[i]);
		}

		// Récursion sur la première partie
		calculeFFTrec(premierePartie);
		// récursion sur la deuxième partie
		calculeFFTrec(deuxiemePartie);

		// Fusion
		std::vector< std::complex<double> > retour;
		retour.resize(points.size());

		return retour;
	}
}

*/
