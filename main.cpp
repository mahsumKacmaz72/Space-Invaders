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

	
	
	sf::RenderWindow pencere(sf::VideoMode({1410,1510}), "Space Invaders", sf::Style::Default);
	pencere.setFramerateLimit(60);
	pencere.setPosition({ 800,0 });


	// dusmanlar için ızgara
	sf::RectangleShape sutun({ 5,1500 });
	sf::RectangleShape satir({ 1400,5 });
	satir.setFillColor(sf::Color::Green);
	sutun.setFillColor(sf::Color::Green);
	std::vector<sf::RectangleShape> satirlar;
	std::vector<sf::RectangleShape> sutunlar;
	float y = 50, x = 100;
	for (int i= 0; i<=30; i++){
		satirlar.push_back(satir);
		sutunlar.push_back(sutun);
		satir.setPosition({ 0,y });
		sutun.setPosition({ x,0 });
		x += 100;
		y += 50;
	}

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
		


		pencere.clear(sf::Color::Black);

		for (const auto& satir : satirlar) {
			pencere.draw(satir);
		}
		for (const auto& sutun : sutunlar) {
			pencere.draw(sutun);
		}
		dusman.ciz(pencere);
		mermi.ciz(pencere);
		gemi.ciz(pencere);
		
		pencere.display();
	}
	return 0;
}




