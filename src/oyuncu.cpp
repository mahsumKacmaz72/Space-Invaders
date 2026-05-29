#include "C:\\Space Invaders\\include\\oyuncu.hpp"



oyuncu::oyuncu():gemiResmi("C:\\Space Invaders\\assets\\images\\uzayGemisi2.png"),gemi(gemiResmi){
	gemi.setPosition({ 850,1475});
	gemi.setScale({ 0.15, 0.15f });
	gemiBoyutu = 130.f;	
}

void oyuncu::sifirla() {
	gemi.setPosition({ 850,1475 });
	gemiSilindiMi = false;
	gemiGeciciGizliMi = false;
	can = 3;
	gizlenmeZamanlayici.restart();
}




void oyuncu::hareketEt() {
	if (gemiSilindiMi || gemiGeciciGizliMi)
		return;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)){ 
		if(gemi.getPosition().x >= 10)
			gemi.move({ -10.f, 0 });
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)){ 
		if(gemi.getPosition().x + gemiBoyutu <= 1810)
			gemi.move({ 10.f, 0 });
	}
}

void oyuncu::hasarAl() {
	if (gemiSilindiMi || gemiGeciciGizliMi)
		return;

	can--;

	if (can <= 0) {
		can = 0;
		gemiSilindiMi = true;
		gemiGeciciGizliMi = false;
	}
	else {
		gemiGeciciGizliMi = true;
		gizlenmeZamanlayici.restart();
	}
}

void oyuncu::guncelle() {
	if (gemiGeciciGizliMi && gizlenmeZamanlayici.getElapsedTime() >= gizlenmeSuresi)
		gemiGeciciGizliMi = false;
}

bool oyuncu::hayattaMi() {
	return !gemiSilindiMi && !gemiGeciciGizliMi;
}

int oyuncu::canSayisi() {
	return can;
}

sf::Vector2f oyuncu::gemiKonumu(){
	return gemi.getPosition() + sf::Vector2f({gemiBoyutu/2 , 0.f});
}

void oyuncu::ciz(sf::RenderWindow& pencere) {
	if (!gemiSilindiMi && !gemiGeciciGizliMi)
		pencere.draw(gemi);
}
