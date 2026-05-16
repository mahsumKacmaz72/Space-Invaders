#pragma once
#include <SFML/Graphics.hpp>

class oyuncu {
private:
	sf::Texture gemiResmi;
	sf::Sprite gemi;
public:

	oyuncu();

	void ciz(sf::RenderWindow& pencere);

};