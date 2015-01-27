#include "filtre.h"

Filtre::Filtre(const std::vector< std::complex<double> > &pointsComplexes)
{
	m_pointsComplexes = pointsComplexes;
}

Filtre::~Filtre()
{
	std::vector< std::complex<double> >().swap(m_pointsComplexes);
}

std::vector< std::complex<double> > Filtre::passeBasIdeal(const double rayon)
{
	std::vector< std::complex<double> > filtre;
	filtre.resize(m_pointsComplexes.size(),0);

	int centre = m_pointsComplexes.size() / 2;
	std::complex<double> origine = m_pointsComplexes[centre];

	for (int i = 0; i < filtre.size(); ++i)
	{
		if(abs(origine - m_pointsComplexes[i]) > rayon)
			filtre[i] = 0;
		else filtre[i] = 1;
	}

	return filtre;
}

std::vector< std::complex<double> > Filtre::passeHautIdeal(const double rayon)
{
	std::vector< std::complex<double> > filtre;
	filtre.resize(m_pointsComplexes.size(),0);

	int centre = m_pointsComplexes.size() / 2;
	std::complex<double> origine = m_pointsComplexes[centre];

	for (int i = 0; i < filtre.size(); ++i)
	{
		if(abs(origine - m_pointsComplexes[i]) < rayon)
			filtre[i] = 0;
		else filtre[i] = 1;
	}

	return filtre;
}
