#ifndef IMAGE_H
#define IMAGE_H

class Image
{
    int m_nbColonnes ;
    int m_nbLignes ;

public:
    Image();
    ~Image();

    int getNbColonnes();
    int getNbLignes();
};

#endif // IMAGE_H
