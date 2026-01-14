#ifndef PERSO_HPP
#define PERSO_HPP

#include <iostream>

#include <iostream>
// Un setter est une 'fonction' qui permet de modifier à l'utilisateur de modifier la valeur d'un champ comme il le souhaite
// Un getter est une 'fonction' qui permet de recuperer la valeur du champs pour l'afficher en autre
// Encapsulation, rends les données non manipulable aux users avec l'attribut private, utile pour les champs qu'on ne veut pas permettre aux users de modifier les champs
class Personnage
{
public: // Mauvaise pratique, rends les attributs manipulable et accesssible a tout le monde
	// C'est un construteur pour pouvoir init nos variables en dehors de la classe a la maniere d'une fonction
	Personnage(std::string name, unsigned int pdv, unsigned int vitesse, unsigned int lvl, unsigned int x, unsigned int y);

public:
	void seDeplacer(unsigned int X, unsigned int Y);
	void IncrementLvl();
	unsigned int getPdv();
	unsigned int getVitesse();
	unsigned int getLvl();
	unsigned int getPosX();
	unsigned int getPosY();
	std::string getName();
	void setName(std::string name);

private: // Encapsulation, rends les données non manipulable aux users
	std::string m_name;
	unsigned int m_pdv;
	unsigned int m_vitesse;
	unsigned int m_level;
	unsigned int m_x, m_y;
};

class Guerrier : public Personnage
{
private:
	unsigned int m_force;
public:
	Guerrier(unsigned int force, unsigned int pdv, unsigned int vitesse, unsigned int lvl);
};

#endif