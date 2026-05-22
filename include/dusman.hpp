#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

class enemy {
private:
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
	float						hiz = 1.f;
	float						dusmanMermiHizi = 12.f;
	bool						sagaGidiyorMu = true;
	sf::Clock					dusmanZamanlayici;
	sf::Time					dusmanAtesEtmeAraligi = sf::milliseconds(2000);
	sf::Time					sonDusmanAtesZamani = sf::Time::Zero;


public:
	enemy(int dusmanSecici);
	void dusmanHareketi();
	void dusmanAtesi();
	void ciz(sf::RenderWindow& pencere);
	void dusmanMermiCiz(sf::RenderWindow& pencere);
};
