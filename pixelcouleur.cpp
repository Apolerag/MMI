#include "pixelcouleur.h"

PixelCouleur::PixelCouleur()
{
}

PixelCouleur::~PixelCouleur()
{
}

int PixelCouleur::getR()
{
	return m_R;
}

int PixelCouleur::getV()
{
	return m_V;
}

int PixelCouleur::getB()
{
	return m_B;
}

std::vector<int> PixelCouleur::getRVB()
{
	return std::vector<int>() ;
}
