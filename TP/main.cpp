#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "contour.h"
#include "imageniveauxgris.h"
#include "histogramme.h"

int main(int argc, char* argv[])
{

	std::string in, out;
    if (argc < 2)
        in = "/home/apolerag/Master2/MMI/TP/barbara.ascii.pgm";
    else in = argv[1];

    if (argc > 2)
        out = argv[2];
    else out = "/home/apolerag/Master2/MMI/TP/res.pgm";

    std::cout<< in <<std::endl;
    std::cout<< out <<std::endl;
    ImageNiveauxGris im(in);

   // ImageNiveauxGris im2(im);

    //im2.sauverDansFichierPGM(out);

    Histogramme h = Histogramme(im);
    h.sauverDansFichierTXT("res.txt");

   // h.lireDansFichierTXT("res.txt");

    h.sauverDansFichierTXT();

/*
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
    }*/
    return 0;
}
