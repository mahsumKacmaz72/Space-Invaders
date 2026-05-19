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

	
public:
	enemy();
	
	void ciz(sf::RenderWindow& pencere);
};