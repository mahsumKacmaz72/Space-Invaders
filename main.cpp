#include <SFML/Graphics.hpp>
#include "C:\\Space Invaders\\include\\oyuncu.hpp"
#include "C:\\Space Invaders\\include\\mermi.hpp"
#include "C:\\Space Invaders\\include\\dusman.hpp"



int main(){
	oyuncu gemi;
	bullet mermi;
	enemy dusman;

	
	
	sf::RenderWindow pencere(sf::VideoMode::getDesktopMode(), "Space Invaders");
	//pencere.setFramerateLimit(60);
	pencere.setVerticalSyncEnabled(true);




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

		dusman.ciz(pencere);
		mermi.ciz(pencere);
		gemi.ciz(pencere);

		pencere.display();
	}
	return 0;
}




