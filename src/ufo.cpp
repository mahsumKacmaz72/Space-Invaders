#include "C:\\Space Invaders\\include\\ufo.hpp"
#include <iostream>

ufo::ufo() : ufoGemisi(ufoResmi) {
	if (!ufoResmi.loadFromFile("C:\\Space Invaders\\assets\\images\\ufo.png"))
		std::cout << "ufo resmi yuklenemedi";

	ufoGemisi.setTexture(ufoResmi, true);
	ufoGemisi.setScale({ 1, 1 });// 0.22
	sifirla();
}

void ufo::sonrakiCikisSuresiniAyarla() {
	sonrakiCikisSuresi = sf::seconds(static_cast<float>(rand() % 13 + 12));
	zamanlayici.restart();
}

void ufo::baslat() {
	aktifMi = true;
	sagaGidiyorMu = rand() % 2 == 0;

	float y = static_cast<float>(rand() % 70 + 70);
	if (sagaGidiyorMu) {
		ufoGemisi.setPosition({ -160.f, y });
	}
	else {
		ufoGemisi.setPosition({ 1860.f, y });
	}
}

void ufo::sifirla() {
	aktifMi = false;
	sonrakiCikisSuresiniAyarla();
}

void ufo::guncelle() {
	if (!aktifMi) {
		if (zamanlayici.getElapsedTime() >= sonrakiCikisSuresi)
			baslat();

		return;
	}

	if (sagaGidiyorMu)
		ufoGemisi.move({ hiz, 0.f });
	else
		ufoGemisi.move({ -hiz, 0.f });

	float x = ufoGemisi.getPosition().x;
	if (x < -220.f || x > 1920.f) {
		aktifMi = false;
		sonrakiCikisSuresiniAyarla();
	}
}

void ufo::ciz(sf::RenderWindow& pencere) {
	if (aktifMi)
		pencere.draw(ufoGemisi);
}
