/**
 * @file image.h
 * @authors Aurélien CHEMIER, Romane LHOMME
 * @date janvier 2015
 */

#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>

/**
 * @class Image
 * @brief permet la lecture et l'écriture d'une image au format PGM (niveaux de gris).
 * 
 */
class Image
{
private:
	/**
	 * @brief P2 ou P5 
	 */
	std::string m_mode_encodage ;
	unsigned int m_nbColonnes ;
	unsigned int m_nbLignes ;
	/**
	 * @brief la valeur max que peut avoir un pixel
	 */
	unsigned int m_niveauxIntensite ;  

public:

	std::vector<int> m_tableauPixels ;

	/**
	 * @brief Constructeur prenant les dimensions d'une Image
	 * 
	 * @param nbColonnes
	 * @param nbLignes 
	 * @param niveauIntensite 
	 * @param modeEncodage 
	 */
    Image(const int nbColonnes, const int nbLignes, const int niveauIntensite, const std::string & modeEncodage);

    /**
     * @brief Constructeur lisant un fichier PGM
     * 
     * @param nomFichierPGM le nom de l'image à charger
     */
    Image(const std::string & nomFichierPGM);

    /**
     * @brief Constructeur par copie
     * 
     * @param image 
     */
    Image(const Image & image);

    /**
     * @brief Destructeur
     */
    ~Image();

    /* getter et setter*/
    const unsigned int getNbColonnes() const;
	const unsigned int getNbLignes() const;
	const unsigned int getNiveauxIntensite() const;
	const std::string getModeEncodage() const;
    int & elementTableauPixels(int ligne, int colonne);
    const int & elementTableauPixels(int ligne, int colonne) const;
    const int & elementTableauPixels(int i) const;

    /**
     * @brief sauvegarde l'image dans un fichier PGM
     * 
     * @param nomFichierPGM le nom du fichier
     */
    void sauverDansFichierPGM(std::string & nomFichierPGM) const;
};

#endif
