#include "C:\\Space Invaders\\include\\oyuncu.hpp"



oyuncu::oyuncu():gemiResmi("C:\\Space Invaders\\assets\\images\\uzayGemisi2.png"),gemi(gemiResmi){
	gemi.setPosition({ 550,1160});
	gemi.setScale({ 1.19f,1 });
	gemiBoyutu = 140.f;	
}




void oyuncu::hareketEt() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)){ 
		if(gemi.getPosition().x >= 10)
			gemi.move({ -10.f, 0 });
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)){ 
		if(gemi.getPosition().x + gemiBoyutu <= 1200)
			gemi.move({ 10.f, 0 });
	}
}



sf::Vector2f oyuncu::gemiKonumu(){
	return gemi.getPosition() + sf::Vector2f({gemiBoyutu/2 , 0.f});
}




void oyuncu::ciz(sf::RenderWindow& pencere) {
	pencere.draw(gemi);
}
