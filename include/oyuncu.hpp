#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <filesystem>


class oyuncu {
private:
	sf::Texture		gemiResmi;
	sf::Sprite		gemi;
	float			gemiBoyutu;

	
public:

	oyuncu();

	void hareketEt();
	sf::Vector2f gemiKonumu();
	void ciz(sf::RenderWindow& pencere);

};
