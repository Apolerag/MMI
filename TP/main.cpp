#include <iostream>

#include "imageniveauxgris.h"
#include "histogramme.h"

int main()
{
	ImageNiveauxGris i("truc.pgm");
	i.sauverDansFichierPGM("res");
	Histogramme h = Histogramme();
/*	h.lireDansFichierTXT("res.txt");
	h.sauverDansFichierTXT("res.txt");	*/ 
    std::cout << "Hello World!" << std::endl;
    return 0;
}

