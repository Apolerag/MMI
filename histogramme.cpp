#include "histogramme.h"

#include <fstream>
#include <iostream>

Histogramme::Histogramme(const ImageNiveauxGris & img)
{
    m_tableauDonnees.resize(img.getNiveauxIntensite()+1,0);
    m_cumule.resize(img.getNiveauxIntensite()+1,0);

    for(int i = 0; i < img.getNbColonnes(); i++) {
        for(int j = 0; j < img.getNbLignes(); j++) {
            m_tableauDonnees[img.elementTableauPixels(j,i)]++;
		}
    }

    m_cumule[0] = m_tableauDonnees[0];
    for (int i = 1; i < m_cumule.size(); i++) {
        m_cumule[i] = m_cumule[i-1] + m_tableauDonnees[i];
    }
}

Histogramme::Histogramme()
{
    m_tableauDonnees.resize(5);
    for (int i = 0; i < m_tableauDonnees.size(); ++i)
    {
        m_tableauDonnees[i] = (5+i)*(5-i);
    }
}

Histogramme::~Histogramme()
{
	std::vector<int>().swap(m_tableauDonnees);
}

int Histogramme::getHistogramme(const int i)
{
    if(i < 0 || i >= m_tableauDonnees.size())
        return -1;
    else return m_tableauDonnees[i];
}

int Histogramme::getCumule(const int i)
{
    if(i < 0 || i >= m_cumule.size())
        return -1;
    else return m_cumule[i];
}

void Histogramme::sauverDansFichierTXT()
{
	sauverDansFichierTXT("histogramme.txt");
}

void Histogramme::sauverDansFichierTXT(const std::string & nomFichierTXT)
{
	std::ofstream fichier;

	if(nomFichierTXT.compare(nomFichierTXT.length() - 3, 3, "txt") != 0)
		fichier.open((nomFichierTXT + ".txt").c_str());
	else
    	fichier.open(nomFichierTXT.c_str());

    if(fichier) {

        fichier << "# Histogramme sur " << m_tableauDonnees.size()-1 << " niveaux d'intensité" << std::endl;
    	fichier << "# Intensite / Compte" << std::endl;

    	for(unsigned int i = 0; i < m_tableauDonnees.size(); i++)
    		fichier << i << " " << m_tableauDonnees[i] << std::endl;

    	fichier.close();
    }
    else
    	std::cerr << "Impossible d'ouvrir le fichier "<< nomFichierTXT  <<"pour écrire dedans." << std::endl;
}

void Histogramme::lireDansFichierTXT(const std::string & nomFichierTXT)
{
	std::ifstream fichier;
    fichier.open(nomFichierTXT.c_str());

    if(fichier)
    {
        int taille = 0;
        std::string s;
        fichier >> s >> s >> s >> taille;
        m_tableauDonnees.resize(taille+1);
    	for (unsigned int i = 0; i < m_tableauDonnees.size(); ++i)
    	{
    		fichier >> i  >> m_tableauDonnees[i] ;
    	}
        
        fichier.close();
    }
    else 
        std::cerr << "Impossible d'ouvrir le fichier"<<nomFichierTXT <<"pour le lire." << std::endl;
}
