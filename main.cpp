#include <SFML/Graphics.hpp>
#include "C:\\Space Invaders\\include\\oyuncu.hpp"
#include "C:\\Space Invaders\\include\\mermi.hpp"


int main(){
	oyuncu gemi;
	bullet mermi;
	
	sf::RenderWindow pencere(sf::VideoMode({ 1600, 1200 }), "Space Invaders");
	pencere.setFramerateLimit(60);


	while (pencere.isOpen()){

		while (auto olay = pencere.pollEvent()) {
			if (olay->is<sf::Event::Closed>()) {
				pencere.close();
			}
		}

	
		gemi.hareketEt();
		mermi.mermiAtesleme(gemi.gemiKonumu());
		mermi.sarjorYenileme(gemi.gemiKonumu());

		


		pencere.clear(sf::Color::Black);

		mermi.ciz(pencere);
		gemi.ciz(pencere);

		pencere.display();
	}
	return 0;
}




