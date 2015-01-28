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

  if(argc < 2) {
    std::cerr<<"usage: "<<argv[0]<<" IMAGE "<<std::endl;
    return EXIT_FAILURE;
  }
  std::string in = argv[1];

  std::string out = "fourier.pgm", out2 = "retour.pgm", out3 = "negatif.pgm";
  std::string out4 = "egalisation.pgm";




  Image img(in);
  FonctionsCorrespondance fonc(img);

  Fourier f;
  f.calculeFourierRapide(img);
  Filtre filtre(f);
  filtre.passeBasIdeal(60);
  f = filtre.returnFourier(); 


  Image negatif = fonc.negatif();
  Image egal = fonc.egalisationHistogramme();
  Image fourierCentre = f.getImageFourier(true);
  Image retour = f.getImageApresFourierInverse();

  fourierCentre.sauverDansFichierPGM(out);
  retour.sauverDansFichierPGM(out2);
  negatif.sauverDansFichierPGM(out3);
  egal.sauverDansFichierPGM(out4);



  return 0;
}
