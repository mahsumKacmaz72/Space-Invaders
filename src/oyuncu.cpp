#include "C:\\Space Invaders\\include\\oyuncu.hpp"


oyuncu::oyuncu()
	:gemiResmi("C:\\Space Invaders\\assets\\images\\Uzay Gemileri\\uzayGemisi1.png"),
	 gemi(gemiResmi){

	gemi.setPosition({ 500,500 });
}

void oyuncu::ciz(sf::RenderWindow& pencere) {
	pencere.draw(gemi);
}