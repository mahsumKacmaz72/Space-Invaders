#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class oyuncu {
private:
	sf::Texture gemiResmi;
	sf::Sprite gemi;
	float gemiBoyutu;
	
public:

	oyuncu();
	void ciz(sf::RenderWindow& pencere);
	void hareketEt();
};