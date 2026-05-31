#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>

class carpismaDenetimi;

class ufo {
private:
	friend class carpismaDenetimi;

	sf::Texture ufoResmi;
	sf::Sprite ufoGemisi;
	sf::Clock zamanlayici;
	sf::Time sonrakiCikisSuresi = sf::seconds(14.f);
	bool aktifMi = false;
	bool sagaGidiyorMu = false;
	float hiz = 8.f;

	void sonrakiCikisSuresiniAyarla();
	void baslat();

public:
	ufo();

	void sifirla();
	void guncelle();
	void ciz(sf::RenderWindow& pencere);
};
