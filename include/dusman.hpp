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
	sf::Sprite dusman;
	std::vector<sf::Sprite> dusmanlar;
	float hiz = 5.f;
	bool sagaGidiyorMu = true;
public:
	enemy(int dusmanSecici);
	void dusmanHareketi();
	void ciz(sf::RenderWindow& pencere);
};