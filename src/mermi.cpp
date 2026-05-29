#include "C:\Space Invaders\include\mermi.hpp"

bullet::bullet() :mermiResmi("C:\\Space Invaders\\assets\\images\\mermi1.png"), mermi(mermiResmi) {
	mermi.setScale({ 0.8f, 1.f });
	//mermi.setColor(sf::Color::Green);
}

void bullet::sifirla() {
	sarjor.clear();
	sonAtesZamani = sf::Time::Zero;
	zamanlayici.restart();
}

bool bullet::mermiAtesleme(sf::Vector2f gemiKonumu){

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space)) {
		sf::Time simdikiZaman = zamanlayici.getElapsedTime();

		if (simdikiZaman - sonAtesZamani >= atesEtmeAraligi) {
			mermi.setPosition({gemiKonumu.x-17.f , gemiKonumu.y});
			sarjor.push_back(mermi);
			sonAtesZamani = simdikiZaman;
			return true;
		}
	}

	return false;
}

void bullet::sarjorYenileme(sf::Vector2f gemiKonumu){

	for (int i = 0; i < sarjor.size(); i++) {
		sarjor[i].move({ 0.f, -mermiHizi });
		
		if (sarjor[i].getPosition().y <= -16.f) {
			sarjor.erase(sarjor.begin() + i);
			i--;
		}
	}
}

void bullet::ciz(sf::RenderWindow& pencere){
	for (const auto& mermi : sarjor) {
		pencere.draw(mermi);
	}
}

