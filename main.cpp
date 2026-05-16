#include <SFML/Graphics.hpp>
#include "C:\\Space Invaders\\include\\oyuncu.hpp"


int main(){
	oyuncu gemi;
		

	sf::RenderWindow pencere(sf::VideoMode({ 1635, 1200 }), "Space Invaders");
	while (pencere.isOpen()){

		while (auto olay = pencere.pollEvent()) {
			if (olay->is<sf::Event::Closed>()) {
				pencere.close();
			}
		}

		pencere.clear(sf::Color::Black);
		gemi.ciz(pencere);

		pencere.display();
	}
	return 0;
}




