/**
 * @file contour.h
 * @authors Aurélien CHEMIER, Romane LHOMME
 * @date janvier 2015
 */
#ifndef CONTOUR_H
#define CONTOUR_H

#include <complex>
#include <vector>

/**
 * @class Contour
 * @brief permet de calculer la Transfomée de Fourier en 1D
 */
class Contour 
{
private:
	/**
	 * @brief un tableau de Complexes
	 */
	std::vector< std::complex<double> > m_data;

public:
	/**
	 * @brief Constructeur
	 */
	Contour();
	/**
	 * @brief Constructeur
	 * 
	 * @param tabComplexe un tableau de Complexes
	 */
	Contour(const std::vector< std::complex<double> > & tabComplexe);
	/**
	 * @brief Destructeur
	 */
	~Contour();

	/**
	 * @return la taille du tableau
	 */
	int getDataSize() const;

	/**
	 * @return le tableau de Complexe
	 */
	std::vector<std::complex<double> > getData() const;

	/**
	 * @param i l'indice d'une case du tableau
	 * @return le i ème complexe du tableau de Complexe 
	 */
	std::complex<double> operator()(const int i) const;
};

#endif

