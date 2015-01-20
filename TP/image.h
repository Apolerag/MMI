#ifndef IMAGE_H
#define IMAGE_H

#include <string>

class Image
{
protected:
	std::string m_mode_encodage ; /** P2 ou P5 */
    unsigned int m_nbColonnes ;
    unsigned int m_nbLignes ;
    unsigned int m_niveauxIntensite ;

public:
    Image();
    Image(const int nbColonnes, const int nbLignes, const int niveauIntensite, const std::string & modeEncodage);
    ~Image();

    const unsigned int getNbColonnes() const;
    const unsigned int getNbLignes() const;
    const unsigned int getNiveauxIntensite() const;
    const std::string getModeEncodage() const;
};

#endif // IMAGE_H
