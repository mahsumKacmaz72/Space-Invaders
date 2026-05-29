#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <filesystem>


class carpismaDenetimi;

class oyuncu {
private:
	friend class	carpismaDenetimi;

	sf::Texture		gemiResmi;
	sf::Sprite		gemi;
	float			gemiBoyutu;
	bool			gemiSilindiMi = false;
	bool			gemiGeciciGizliMi = false;
	int				can = 3;
	sf::Clock		gizlenmeZamanlayici;
	sf::Time		gizlenmeSuresi = sf::milliseconds(2500);

	
public:

	oyuncu();

	void sifirla();
	void hareketEt();
	void hasarAl();
	void guncelle();
	bool hayattaMi();
	int canSayisi();
	sf::Vector2f gemiKonumu();
	void ciz(sf::RenderWindow& pencere);

};
