#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "contour.h"
#include "imageniveauxgris.h"
#include "histogramme.h"
#include "fonctionsCorrespondance.h"

int main(int argc, char* argv[])
{

	std::string in, out;
    if (argc < 2)
        in = "Image/lena.ascii.pgm";
    else in = argv[1];

    if (argc > 2)
        out = argv[2];
    else out = "Image/res.pgm";

   ImageNiveauxGris im(in);

    /*ImageNiveauxGris im2(im);

    im2.sauverDansFichierPGM(out);*/

  FonctionsCorrespondance f(im);

   // ImageNiveauxGris res = f.recadrage(20,230);
   //ImageNiveauxGris res(im);
 	Histogramme h = Histogramme(im);
	h.sauverDansFichierTXT("res.txt");

   im.sauverDansFichierPGM(out);

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
