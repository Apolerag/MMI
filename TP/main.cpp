#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "contour.h"
#include "imageniveauxgris.h"
#include "histogramme.h"

int main(int argc, char* argv[])
{
	/*
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
	*/

	std::vector< std::complex<double> > pointsPourCalcul ;
	pointsPourCalcul.push_back(std::complex<double>(1, 1));
	pointsPourCalcul.push_back(std::complex<double>(3, 1));
	pointsPourCalcul.push_back(std::complex<double>(4, 2));
	pointsPourCalcul.push_back(std::complex<double>(5, 3));
	pointsPourCalcul.push_back(std::complex<double>(3, 5));
	pointsPourCalcul.push_back(std::complex<double>(2, 3));
	pointsPourCalcul.push_back(std::complex<double>(1, 3));
	
	Contour c = Contour(pointsPourCalcul);

	std::cout << "N/2 = " << pointsPourCalcul.size()/2 << std::endl ;

	for(int i = 0; i < pointsPourCalcul.size(); i++) {
		std::cout << "Old : (" << pointsPourCalcul[i].real() << ","
			<< pointsPourCalcul[i].imag() << "), TFD : (" 
			<< c.elementTableauTFD(i).real() << ","
			<< c.elementTableauTFD(i).imag() << ") et new : (" 
			<< c.elementTableauRecompose(i).real() << ","
			<< c.elementTableauRecompose(i).imag() << ")" << std::endl ;
	}
    return 0;
}

