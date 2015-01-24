#ifndef CONTOUR_H
#define CONTOUR_H

#include <complex>
#include <string>
#include <vector>

class Contour 
{
private:
	std::vector< std::complex<double> > m_pointsComplexes;
	std::vector< std::complex<double> > m_pointsTFD;
	std::vector< std::complex<double> > m_pointsRecomposes;
	std::vector< std::complex<double> > m_pointsFFT;

public:
	Contour();
	Contour(const std::vector< std::complex<double> > & tabComplexe);
	~Contour();

	std::complex<double> & elementTableau(int i);
	const std::complex<double> & elementTableau(int i) const;

	std::complex<double> & elementTableauTFD(int i);
	const std::complex<double> & elementTableauTFD(int i) const;

	std::complex<double> & elementTableauRecompose(int i);
	const std::complex<double> & elementTableauRecompose(int i) const;
	
	int indiceNegatif(int i) const;
	void calculeTransformeeFourierDiscrete();
	void calculeTFDInverse();
	void calculeFFT();
	std::vector< std::complex<double> > calculeFFTrec(int M);

};

#endif

