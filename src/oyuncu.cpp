#include "C:\\Space Invaders\\include\\oyuncu.hpp"



oyuncu::oyuncu():gemiResmi("C:\\Space Invaders\\assets\\images\\uzayGemisi2.png"),gemi(gemiResmi){
	gemi.setPosition({ 750,1070 });
	gemi.setScale({ 1.4f,1.25f });
	gemiBoyutu = 140.f;
}

void oyuncu::ciz(sf::RenderWindow& pencere) {
	pencere.draw(gemi);
}

void oyuncu::hareketEt() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)){ 
		if(gemi.getPosition().x >= 13)
			gemi.move({ -15.f, 0 });
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)){ 
		if(gemi.getPosition().x + gemiBoyutu <= 1600)
			gemi.move({ 15.f, 0 });
	}
}
