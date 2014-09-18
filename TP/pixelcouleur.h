#ifndef PIXELCOULEUR_H
#define PIXELCOULEUR_H

#include <vector>

class PixelCouleur
{
    int m_R;
    int m_V;
    int m_B;

public:
    PixelCouleur();
    ~PixelCouleur();

    int getR();
    int getV();
    int getB();
    std::vector<int> getRVB();
};

#endif // PIXELCOULEUR_H
