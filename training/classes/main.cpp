#include <iostream>
// Un setter est une 'fonction' qui permet de modifier à l'utilisateur de modifier la valeur d'un champ comme il le souhaite 
// Un getter est une 'fonction' qui permet de recuperer la valeur du champs pour l'afficher en autre
// Encapsulation, rends les données non manipulable aux users avec l'attribut private, utile pour les champs qu'on ne veut pas permettre aux users de modifier les champs
class Personnage {
public: //Mauvaise pratique, rends les attributs manipulable et accesssible a tout le monde

	// C'est un construteur pour pouvoir init nos variables en dehors de la classe a la maniere d'une fonction
	Personnage(std::string name, unsigned int pdv,unsigned int vitesse, unsigned int lvl, unsigned int x, unsigned int y)
	{
		m_name = name;
		m_pdv = pdv;
		m_vitesse = vitesse;
		m_level = lvl;
		m_x = x;
		m_y = y;
		std::cout << "constructeur personnalisée appelé" << std::endl;
	}
public:
	void seDeplacer(unsigned int X, unsigned int Y)
	{
		m_x += X;
		m_y += Y;
	}
public :
	void IncrementLvl()
	{
		m_level++;
	}
public :
	unsigned int getPdv()
	{
		return m_pdv;
	}
public :
	unsigned int getVitesse()
	{
		return m_vitesse;
	}
public :
	unsigned int getLvl()
	{
		return m_level;
	}
public :
	unsigned int getPosX()
	{
		return m_x;
	}
public :
	unsigned int getPosY()
	{
		return m_y;
	}
public :
	std::string getName()
	{
		return m_name;
	}
public :
	void setName(std::string name)
	{
		m_name = name;
	}
private : // Encapsulation, rends les données non manipulable aux users
	unsigned int m_pdv;
	unsigned int m_vitesse;
	unsigned int m_level;
	unsigned int m_x ,m_y;
	std::string m_name;
};

int main(void)
{
	Personnage player1("John Doe",100, 15, 1, 0, 0);
	std::cout << player1.getName()<< std::endl;
}