#include <SFML/Graphics.hpp>

int main(){

	sf::RenderWindow pencere(sf::VideoMode({ 1635, 1200 }), "Space Invaders");
	while (pencere.isOpen()){

		while (auto olay = pencere.pollEvent()) {
			if (olay->is<sf::Event::Closed>()) {
				pencere.close();
			}
		}

	
		
		pencere.clear(sf::Color::Black);
	
		pencere.display();
	}
	return 0;
}