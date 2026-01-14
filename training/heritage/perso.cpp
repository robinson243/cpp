#include "perso.hpp"

Personnage::Personnage(std::string name, unsigned int pdv, unsigned int vitesse, unsigned int lvl, unsigned int x, unsigned int y) : m_name(name), m_pdv(pdv), m_vitesse(vitesse), m_level(lvl), m_x(x), m_y(y)
{
	// std::cout << "constructeur personnalisée appelé" << std::endl;
}

void Personnage::seDeplacer(unsigned int X, unsigned int Y)
{
	m_x += X;
	m_y += Y;
}
void Personnage::IncrementLvl()
{
	m_level++;
}
unsigned int Personnage::getPdv()
{
	return m_pdv;
}

unsigned int Personnage::getVitesse()
{
	return m_vitesse;
}

unsigned int Personnage::getLvl()
{
	return m_level;
}

unsigned int Personnage::getPosX()
{
	return m_x;
}

unsigned int Personnage::getPosY()
{
	return m_y;
}

std::string Personnage::getName()
{
	return m_name;
}

void Personnage::setName(std::string name)
{
	m_name = name;
}
