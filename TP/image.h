#ifndef IMAGE_H
#define IMAGE_H

class Image
{
private:
    int m_nbColonnes ;
    int m_nbLignes ;
    int m_niveauxIntensite ;

protected:
    Image();

public:
    Image(int ligne, int colonne, int niveauIntensite);
    ~Image();

    const int getNbColonnes();
    const int getNbLignes();
    const int getNiveauxIntensite();
};

#endif // IMAGE_H
