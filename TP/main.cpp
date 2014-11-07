#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "imageniveauxgris.h"
#include "histogramme.h"

int main(int argc, char* argv[])
{
	std::string in, out;
	if (argc < 2)
	{
		std::cerr<< "usage: "<< argv[0] << " IMAGE [SAVE_PATH]\n";
		return EXIT_FAILURE;
	}

	in = argv[1];
	if (argc > 2) out = argv[2];

	ImageNiveauxGris i(in);

	if (argc > 2) i.sauverDansFichierPGM(out);

	Histogramme h = Histogramme();
	h.lireDansFichierTXT("res.txt");
	//h.sauverDansFichierTXT("res.txt");
    std::cout << "Hello World!" << std::endl;
    return 0;
}

