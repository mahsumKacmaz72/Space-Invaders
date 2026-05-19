#include <SFML/Graphics.hpp>
#include "C:\\Space Invaders\\include\\oyuncu.hpp"
#include "C:\\Space Invaders\\include\\mermi.hpp"
#include "C:\\Space Invaders\\include\\dusman.hpp"



int main(){
	oyuncu gemi;
	bullet mermi;
	enemy dusman;

	
	
	sf::RenderWindow pencere(sf::VideoMode({1200,1300}), "Space Invaders", sf::Style::Default);
	pencere.setVerticalSyncEnabled(true);

	// dusmanlar için ızgara
	sf::RectangleShape sutun({ 10,1300 });
	sf::RectangleShape satir({ 1200,10 });
	satir.setFillColor(sf::Color::Red);
	sutun.setFillColor(sf::Color::Red);
	std::vector<sf::RectangleShape> satirlar;
	std::vector<sf::RectangleShape> sutunlar;
	float y = 100, x = 100;
	for (int i= 0; i<=13; i++){
		satirlar.push_back(satir);
		sutunlar.push_back(sutun);

		satir.setPosition({ 0,y });
		sutun.setPosition({ x,0 });

		x += 100;
		y += 100;
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




