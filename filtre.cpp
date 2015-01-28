/**
 * @file filtre.cpp
 * @authors Aurélien CHEMIER, Romane LHOMME
 * @date janvier 2015
 */

#include "filtre.h"

 #include <utility>
 #include <iostream>

Filtre::Filtre(Fourier &fourier):m_fourier(fourier)
{
	//m_fourier = fourier;
	m_filtre.resize(m_fourier.getTailleTableau(),0.f);
}

Filtre::~Filtre()
{
	std::vector<double>().swap(m_filtre);
}

void Filtre::passeBasIdeal(const double rayon)
{
	m_filtre.resize(m_fourier.getTailleTableau());

	int centreLigne = m_fourier.getWitdh() / 2;
	int centreColonne = m_fourier.getHeight() / 2;

	for (int ligne = 0; ligne < m_fourier.getWitdh(); ++ligne)
	{
		for (int colonne = 0; colonne < m_fourier.getHeight(); ++colonne)
		{
			if(sqrt(pow(ligne - centreLigne,2) + pow(colonne - centreColonne, 2) ) > rayon)
				m_filtre[ligne * m_fourier.getHeight() + colonne] = 0.f;
			else
				m_filtre[ligne * m_fourier.getHeight() + colonne] = 1.f;
		}
	}
	appliqueFiltre();
}

void Filtre::passeHautIdeal(const double rayon)
{
	m_filtre.resize(m_fourier.getTailleTableau());

	int centreLigne = m_fourier.getWitdh() / 2;
	int centreColonne = m_fourier.getHeight() / 2;

	for (int ligne = 0; ligne < m_fourier.getWitdh(); ++ligne)
	{
		for (int colonne = 0; colonne < m_fourier.getHeight(); ++colonne)
		{
			if(sqrt(pow(ligne - centreLigne,2) + pow(colonne - centreColonne, 2) ) > rayon)
				m_filtre[ligne * m_fourier.getHeight() + colonne] = 1.f;
		}
	}
	appliqueFiltre();
}

void Filtre::appliqueFiltre()
{
	m_fourier.fourierRapideShift();
	for (int i = 0; i < m_filtre.size(); ++i)
		m_fourier.elementFourier(i) = m_filtre[i]*m_fourier.elementFourier(i);

	m_fourier.fourierRapideShift();
}

Fourier Filtre::returnFourier()
{
	return m_fourier;
}
