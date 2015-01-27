#ifndef FILTRE_H
#define FILTRE_H

#include "contour.h"

class Filtre
{
private:
	std::vector< std::complex<double> > m_pointsComplexes;
public:
	Filtre(const std::vector< std::complex<double> > &pointsComplexes);
	~Filtre();

	std::vector< std::complex<double> > passeBasIdeal(const double rayon);
	std::vector< std::complex<double> > passeHautIdeal(const double rayon);

};

#endif
