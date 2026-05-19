#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

class enemy {
private:
	sf::Texture dusmanResmi;
	sf::Sprite dusman;
	std::vector<sf::Sprite> dusmanSatiri;
	
public:
	enemy();
	
	void dusmanSatirlari();
	void ciz(sf::RenderWindow& pencere);
};