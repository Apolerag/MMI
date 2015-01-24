#include <iostream>

#include "contour.h"
#include "imageniveauxgris.h"

Contour::Contour()
{}

Contour::Contour(const std::vector< std::complex<double> > & tabComplexe)
{
	m_pointsComplexes = tabComplexe;
	calculeTransformeeFourierDiscrete();
	calculeTFDInverse();
}

Contour::~Contour()
{
	std::vector< std::complex<double> >().swap(m_pointsComplexes);
	std::vector< std::complex<double> >().swap(m_pointsTFD);
	std::vector< std::complex<double> >().swap(m_pointsRecomposes);
}

std::complex<double> & Contour::elementTableau(int i)
{
	return m_pointsComplexes[i];
}

const std::complex<double> & Contour::elementTableau(int i) const
{
	return m_pointsComplexes[i];
}

std::complex<double> & Contour::elementTableauTFD(int i)
{
	return m_pointsTFD[i];
}
	
const std::complex<double> & Contour::elementTableauTFD(int i) const
{
	return m_pointsTFD[i];
}

std::complex<double> & Contour::elementTableauRecompose(int i)
{
	return m_pointsRecomposes[i];
}
	
const std::complex<double> & Contour::elementTableauRecompose(int i) const
{
	return m_pointsRecomposes[i];
}

int Contour::indiceNegatif(int i) const
{
	int indice = (i >= 0) ?  i : (m_pointsComplexes.size() % i + i) % i;
	return indice;
}

void Contour::calculeTransformeeFourierDiscrete()
{
	int N = m_pointsComplexes.size();
	m_pointsTFD.resize(N);
	int m, n;
	std::complex<double> s_m;
	std::complex<double> i(0, 1);
	int borneMin = (N%2 == 0) ? -N/2 : -N/2 - 1;

	for(m = borneMin; m < N/2; m++) {
		s_m = 0;
		for(n = 0; n < N; n++) {
			s_m += m_pointsComplexes[n] * exp(-i * (2.f * M_PI * m * n / N));
		}
		s_m *= 1.f/N;
		m_pointsTFD[indiceNegatif(m)] = s_m;
	}
}

void Contour::calculeTFDInverse()
{
	int N = m_pointsComplexes.size();
	m_pointsRecomposes.resize(N);
	int m, n;
	std::complex<double> s_n;
	std::complex<double> i(0, 1);
	int borneMin = (N%2 == 0) ? -N/2 : -N/2 - 1;

	for(n = 0; n < N; n++) {
		s_n = 0;
		for(m = borneMin; m < N/2; m++) {
			s_n += m_pointsTFD[indiceNegatif(m)] * exp(i * (2.f * M_PI * m * n / N));
		}
		m_pointsRecomposes[n] = s_n;
	}
}

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
		/** Division en deux tableaux **/
		std::vector< std::complex<double> > premierePartie;
		std::vector< std::complex<double> > deuxiemePartie;
		for(int i = 0; i < points.size(); i++) {
			if((i % 2) == 0)
				premierePartie.push_back(points[i]);
			else
				deuxiemePartie.push_back(points[i]);
		}

		/** Récursion sur la première partie **/
		calculeFFTrec(premierePartie);
		/** récursion sur la deuxième partie **/
		calculeFFTrec(deuxiemePartie);

		/** Fusion **/
		std::vector< std::complex<double> > retour;
		retour.resize(points.size());

		return retour;
	}
}

