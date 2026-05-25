#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

class carpismaDenetimi;
class engel;

class enemy {
private:
	friend class carpismaDenetimi;

	sf::Texture					dusmanResmi;
	sf::Texture					dusmanResmi1;
	sf::Texture					dusmanResmi2;
	sf::Texture					dusmanResmi3;
	sf::Texture					dusmanMermiResmi;
	sf::Sprite					dusman;
	sf::Sprite					dusmanMermisi;
	std::vector<sf::Sprite>		dusmanlar;
	std::vector<sf::Sprite>		dusmanMermileri;

	int							yon = 1;
	float						hiz = 15.f;
	float						dusmanMermiHizi = 15.f;
	bool						sagaGidiyorMu = true;
	sf::Clock					dusmanZamanlayici;
	sf::Time					dusmanAtesEtmeAraligi = sf::milliseconds(0.1f);
	sf::Time					sonDusmanAtesZamani = sf::Time::Zero;


public:
	enemy(int dusmanSecici);
	void dusmanHareketi(engel& engeller);
	void dusmanAtesi();
	void ciz(sf::RenderWindow& pencere);
	void dusmanMermiCiz(sf::RenderWindow& pencere);
};
