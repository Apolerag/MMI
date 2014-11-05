#ifndef IMAGE_H
#define IMAGE_H

#include <string>

class Image
{
protected:
	std::string m_mode_encodage ; /** P2 ou P5 */
    int m_nbColonnes ;
    int m_nbLignes ;
    int m_niveauxIntensite ;

public:
    Image();
    ~Image() = default;

    const int getNbColonnes() const;
    const int getNbLignes() const;
    const int getNiveauxIntensite() const;
};

#endif // IMAGE_H
