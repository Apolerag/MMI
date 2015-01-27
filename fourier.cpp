/**
 * @file fourier.cpp
 * @authors Aurélien CHEMIER, Romane LHOMME
 * @date janvier 2015
 */

 #include "fourier.h"

#include <iostream>

Fourier::Fourier() : m_dataWidth(0), m_dataHeight(0) {

}

Fourier::~Fourier() {
	std::vector< std::complex<double> >().swap(m_fourier);
}

const int Fourier::getTailleTableau()
{
	return m_fourier.size();
}

const int Fourier::getWitdh()
{
	return m_dataWidth;
}

const int Fourier::getHeight()
{
	return m_dataHeight;
}

std::complex<double> & Fourier::elementFourier(const int i)
{
	return m_fourier[i];
}

int Fourier::indiceDecale(int i, int size) const {

	int indice = (i >= 0) ?  i : size + i;
	return indice;
}

void Fourier::calculeFourierDiscrete(const Contour & contour) {
	
	m_dataWidth = contour.getDataSize();
	m_fourier.resize(m_dataWidth);

	std::complex<double> s_m, i(0, 1);
	int m, n, borneMin = -m_dataWidth/2 - ((m_dataWidth%2 == 0)? 0 : 1);

	for(m = borneMin; m < m_dataWidth/2; m++) {
		s_m = 0;
		for(n = 0; n < m_dataWidth; n++) {
			s_m += contour(n) * exp(-i * (2.f * M_PI * m * n / m_dataWidth));
		}
		s_m *= 1.f/m_dataWidth;
		m_fourier[indiceDecale(m, m_dataWidth)] = s_m;
	}
}

std::vector< std::complex<double> > Fourier::calculeFourierInverse() const {

	std::vector< std::complex<double> > inverse;
	inverse.resize(m_dataWidth);


	std::complex<double> s_n, i(0, 1);
	int m, n, borneMin = -m_dataWidth/2 - ((m_dataWidth%2 == 0)? 0 : 1);

	for(n = 0; n < m_dataWidth; n++) {
		s_n = 0;
		for(m = borneMin; m < m_dataWidth/2; m++) {
			s_n += m_fourier[indiceDecale(m, m_dataWidth)] 
				* exp(i * (2.f * M_PI * m * n / m_dataWidth));
		}
		inverse[n] = s_n;
	}

	return inverse;
}

void Fourier::calculeFourierRapide(const Contour & contour) {

	m_dataWidth = contour.getDataSize();
	m_dataHeight = 1;

	std::vector<std::complex<double> > data = contour.getData();
	m_fourier = calculeFourierRapideLigne(data, false);

	for(int i = 0; i < m_fourier.size(); i++) {
		m_fourier[i].real() /= m_fourier.size();
		m_fourier[i].imag() /= m_fourier.size();
	}
}

void Fourier::calculeFourierRapide(const Image & image) {

	m_dataWidth = image.getNbColonnes();
	m_dataHeight = image.getNbLignes();

	m_fourier.resize(m_dataWidth * m_dataHeight);

	std::vector<std::complex<double> > data;
	data.reserve(m_dataWidth * m_dataHeight);
	for(int i = 0; i < (m_dataWidth * m_dataHeight); i++)
		data[i] = std::complex<double>(image.elementTableauPixels(i), 0);

	// FFT sur les lignes
	if(m_dataWidth > 1) {
		for(int ligne = 0; ligne < m_dataHeight; ligne++) {

			std::vector<std::complex<double> > temp, ligneRes;
			temp.resize(m_dataWidth);
			for(int i = 0; i < m_dataWidth; i++) 
				temp[i] = data[(ligne * m_dataWidth) + i];

			ligneRes = calculeFourierRapideLigne(temp, false);

			for(int i = 0; i < ligneRes.size(); i++) {
				ligneRes[i].real() /= (double)ligneRes.size();
				ligneRes[i].imag() /= (double)ligneRes.size();
				m_fourier[(ligne * m_dataWidth) + i] = ligneRes[i];
			}
		}
	}
	// FFT sur les colonnes
	if(m_dataHeight > 1) {
		for(int colonne = 0; colonne < m_dataWidth; colonne++) {

			std::vector<std::complex<double> > temp, ligneRes;
			temp.resize(m_dataHeight);
			for(int i = 0; i < m_dataHeight; i++)
				temp[i] = m_fourier[colonne + (i * m_dataWidth)];

			ligneRes = calculeFourierRapideLigne(temp, false);

			for(int i = 0; i < ligneRes.size(); i++) {
				ligneRes[i].real() /= (double)ligneRes.size();
				ligneRes[i].imag() /= (double)ligneRes.size();
				m_fourier[colonne + (i * m_dataWidth)] = ligneRes[i];
			}
		}
	}
}

std::vector<std::complex<double> > Fourier::calculeFourierRapideLigne(
	const std::vector<std::complex<double> > & data, bool inverse) {

	if(data.size() == 1)
		return data;

	int i;
	std::complex<double> j(0,1), k;
	std::vector< std::complex<double> > premierePartie, res1;
	premierePartie.resize(data.size() / 2);
	std::vector< std::complex<double> > deuxiemePartie, res2;
	deuxiemePartie.resize(data.size() / 2);
	std::vector< std::complex<double> > retour;
	retour.resize(data.size());

	for(i = 0; i < data.size(); i++) {
		if(i%2 == 0)
			premierePartie[i/2] = data[i];
		else
			deuxiemePartie[i/2] = data[i];
	}

	res1 = calculeFourierRapideLigne(premierePartie, inverse);
	res2 = calculeFourierRapideLigne(deuxiemePartie, inverse);

	for(i = 0; i < data.size() / 2; i++) {

		if(inverse)
			k = exp(j * (2.f * M_PI * i / data.size()));
		else
			k = exp(-j * (2.f * M_PI * i / data.size()));

		retour[i] = res1[i] + k * res2[i];
		retour[i + (data.size()/2)] = res1[i] - k * res2[i];
	}
	return retour;
}

std::vector<std::complex<double> > Fourier::fftinverse() {

	return calculeFourierRapideLigne(m_fourier, true);
}

Image Fourier::fftinverseImg() {

	Image retour(m_dataWidth, m_dataHeight, 255, "P2");
	retour.m_tableauPixels.resize(m_dataWidth * m_dataHeight);
	std::vector<std::complex<double> > tempRes;

	tempRes.resize(m_dataWidth * m_dataHeight);

	if(m_dataHeight > 1) {
		for(int colonne = 0; colonne < m_dataWidth; colonne++) {

			std::vector<std::complex<double> > temp, ligneRes;
			temp.resize(m_dataHeight);
			for(int i = 0; i < m_dataHeight; i++)
				temp[i] = m_fourier[colonne + (i * m_dataWidth)];

			ligneRes = calculeFourierRapideLigne(temp, true);

			for(int i = 0; i < ligneRes.size(); i++)
				tempRes[colonne + (i * m_dataWidth)] = ligneRes[i];
		}
	}
	if(m_dataWidth > 1) {
		for(int ligne = 0; ligne < m_dataHeight; ligne++) {

			std::vector<std::complex<double> > temp, ligneRes;
			temp.resize(m_dataWidth);
			for(int i = 0; i < m_dataWidth; i++) 
				temp[i] = tempRes[(ligne * m_dataWidth) + i];

			ligneRes = calculeFourierRapideLigne(temp, true);

			for(int i = 0; i < ligneRes.size(); i++)
				tempRes[(ligne * m_dataWidth) + i] = ligneRes[i];
		}
	}

	for(int i = 0; i < m_dataWidth * m_dataHeight; i++)
		retour.m_tableauPixels[i] = tempRes[i].real();

	return retour;

}
