#ifndef HISTOGRAMME_H
#define HISTOGRAMME_H

#include "imageniveauxgris.h"
#include "imagecouleur.h"

#include <vector>

class Histogramme
{
private:
	std::vector<int> m_tableauDonnees;

public:
	Histogramme(const ImageNiveauxGris & img);
	Histogramme();
	// Histogramme(const ImageCouleur & img); travailler sur la luminance
	~Histogramme();

	void sauverDansFichierTXT();
	void sauverDansFichierTXT(const std::string & nomFichierTXT);

	void ecrireDansFichierTxt(const std::string & nomFichierTXT);
};

#endif
