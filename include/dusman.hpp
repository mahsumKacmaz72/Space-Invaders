#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

class enemy {
private:
	int yon = 1;
	sf::Texture dusmanResmi;
	sf::Texture dusmanResmi1;
	sf::Texture dusmanResmi2;
	sf::Texture dusmanResmi3;
	sf::Sprite dusman;
	std::vector<sf::Sprite> dusmanlar;
	float hiz = 4.f;
	bool sagaGidiyorMu = true;
public:
	enemy(int dusmanSecici);
	void dusmanHareketi();
	void ciz(sf::RenderWindow& pencere);
};