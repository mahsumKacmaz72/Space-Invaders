#include <SFML/Graphics.hpp>
#include "C:\\Space Invaders\\include\\oyuncu.hpp"


int main(){
	oyuncu gemi;
	
	sf::RenderWindow pencere(sf::VideoMode({ 1600, 1200 }), "Space Invaders");
	pencere.setFramerateLimit(60);


	while (pencere.isOpen()){

		while (auto olay = pencere.pollEvent()) {
			if (olay->is<sf::Event::Closed>()) {
				pencere.close();
			}
		}




		gemi.hareketEt();

		pencere.clear(sf::Color::Black);
		gemi.ciz(pencere);

		pencere.display();
	}
	return 0;
}




