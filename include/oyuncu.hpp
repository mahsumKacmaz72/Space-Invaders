#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <filesystem>


class carpismaDenetimi;

class oyuncu {
private:
	friend class carpismaDenetimi;

	sf::Texture		gemiResmi;
	sf::Sprite		gemi;
	float			gemiBoyutu;
	bool			gemiSilindiMi = false;

	
public:

	oyuncu();

	void hareketEt();
	bool hayattaMi();
	sf::Vector2f gemiKonumu();
	void ciz(sf::RenderWindow& pencere);

};
