/**
 * @file histogramme.h
 * @authors Aurélien CHEMIER, Romane LHOMME
 * @date janvier 2015
 */
#ifndef HISTOGRAMME_H
#define HISTOGRAMME_H

#include "image.h"

#include <vector>

/**
 * @class Histogramme
 * @brief calcul l'histogramme et l'histogramme cumulé d'une Image
 */
class Histogramme
{
private:
	/**
	 * @brief l'histogramme
	 */
	std::vector<int> m_tableauDonnees;
	/**
	 * @brief l'histogramme cumulé
	 */
	std::vector<int> m_cumule;
public:
	/**
	 * @brief Constructeur
	 * 
	 * @param img une image
	 */
    Histogramme(const Image & img);
    Histogramme();
	~Histogramme();

	/* getter*/
	int getHistogramme(const int i);
	int getCumule(const int i);

	/**
	 * @brief enregistre l'histogramme dans un fichier TXT
	 * @details le nom du fichier par défaut est "histogramme.txt"
	 */
	void sauverDansFichierTXT();
	/**
	 * @brief enregistre l'histogramme dans un fichier TXT
	 * 
	 * @param nomFichierTXT le nom du fichier
	 */
	void sauverDansFichierTXT(const std::string & nomFichierTXT);

	/**
	 * @brief récupère les données dans un fichier TXT
	 * 
	 * @param nomFichierTXT le nom du fichier
	 */
	void lireDansFichierTXT(const std::string & nomFichierTXT);
};

#endif
