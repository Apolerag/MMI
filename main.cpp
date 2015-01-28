#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "contour.h"
#include "image.h"
#include "histogramme.h"
#include "fonctionsCorrespondance.h"
#include "fourier.h"
#include "filtre.h"

int main(int argc, char* argv[])
{

	std::string out = "fourier.pgm", out2 = "retour.pgm";
 /*   if (argc < 2)
        in = "Image/lena.ascii.pgm";
    else in = argv[1];

    if (argc > 2)
        out = argv[2];
    else out = "Image/res.pgm";

   Image im(in);

    //Image im2(im);

    //im2.sauverDansFichierPGM(out);

  FonctionsCorrespondance f(im);

  Image res = f.translation(200);
   //Image res(im);

 	Histogramme h = Histogramme(im);
	h.sauverDansFichierTXT("im.txt");
 	h = Histogramme(res);
	h.sauverDansFichierTXT("res.txt");

   im.sauverDansFichierPGM(out);
*/
  Image img("Image/lena.ascii.pgm");
	Fourier f;
	f.calculeFourierRapide(img);
	Filtre filtre(f);
	filtre.passeBasIdeal(50);
  f = filtre.returnFourier(); 

	Image fourierCentre = f.getImageFourier(false);
	Image retour = f.getImageApresFourierInverse();
	fourierCentre.sauverDansFichierPGM(out);
	retour.sauverDansFichierPGM(out2);



    return 0;
}
