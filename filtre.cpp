/**
 * @file filtre.cpp
 * @authors Aurélien CHEMIER, Romane LHOMME
 * @date janvier 2015
 */

#include "filtre.h"

Filtre::Filtre(const std::vector< std::complex<double> > &pointsComplexes)
{
	m_pointsComplexes = pointsComplexes;
	m_filtre.resize(m_pointsComplexes.size(),0.f);
}

Filtre::~Filtre()
{
	std::vector< std::complex<double> >().swap(m_pointsComplexes);
	std::vector< double>().swap(m_filtre);
}

void Filtre::passeBasIdeal(const double rayon)
{
	m_filtre.resize(m_pointsComplexes.size(),0.f);

	int centre = m_pointsComplexes.size() / 2;
	std::complex<double> origine = m_pointsComplexes[centre];

	for (int i = 0; i < m_filtre.size(); ++i)
	{
		if(abs(origine - m_pointsComplexes[i]) > rayon)
			m_filtre[i] = 0.f;
		else m_filtre[i] = 1.f;
	}

}

void Filtre::passeHautIdeal(const double rayon)
{
	m_filtre.resize(m_pointsComplexes.size(),0.f);

	int centre = m_pointsComplexes.size() / 2;
	std::complex<double> origine = m_pointsComplexes[centre];

	for (int i = 0; i < m_filtre.size(); ++i)
	{
		if(abs(origine - m_pointsComplexes[i]) < rayon)
			m_filtre[i] = 0.f;
		else m_filtre[i] = 1.f;
	}

}

std::vector< std::complex<double> > Filtre::appliqueFiltre()
{
	std::vector< std::complex<double> > imageFiltre;

	for (int i = 0; i < m_filtre.size(); ++i)
	{
		imageFiltre.push_back(m_filtre[i]*m_pointsComplexes[i]);
	}

	return imageFiltre;
}
