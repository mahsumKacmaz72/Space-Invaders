#include <SFML/Graphics.hpp>
#include "C:\\Space Invaders\\include\\oyuncu.hpp"
#include "C:\\Space Invaders\\include\\mermi.hpp"
#include "C:\\Space Invaders\\include\\dusman.hpp"



int main(){
	srand(time(0));
	int a = rand() % 3 + 1;
	
	oyuncu gemi;
	bullet mermi;
	enemy dusman(a);

	
	sf::RenderWindow pencere(sf::VideoMode({1800,1600}), "Space Invaders", sf::Style::Default);
	pencere.setFramerateLimit(60);
	pencere.setPosition({ 600,0 });



	while (pencere.isOpen()){

		while (auto olay = pencere.pollEvent()) {
			if (olay->is<sf::Event::Closed>()) {
				pencere.close();
			}
		}

	
		gemi.hareketEt();
		mermi.mermiAtesleme(gemi.gemiKonumu());
		mermi.sarjorYenileme(gemi.gemiKonumu());
		dusman.dusmanHareketi();
		dusman.dusmanAtesi();
		



		// ÇİZİM
		pencere.clear(sf::Color::Black);

		dusman.dusmanMermiCiz(pencere);
		dusman.ciz(pencere);
		mermi.ciz(pencere);
		gemi.ciz(pencere);
		
		pencere.display();
	}
	return 0;
}




