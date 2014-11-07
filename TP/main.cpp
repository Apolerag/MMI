#include <iostream>

#include "imageniveauxgris.h"
#include "histogramme.h"

int main()
{
	std::string fichierOuv("truc.pgm");
	std::string fichierFerm("resultat.pgm");	

	ImageNiveauxGris i(fichierOuv);
	i.sauverDansFichierPGM(fichierFerm);

	
	
    return 0;
}

