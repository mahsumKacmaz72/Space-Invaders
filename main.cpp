#include <SFML/Graphics.hpp>
#include "C:\\Space Invaders\\include\\oyuncu.hpp"
#include "C:\\Space Invaders\\include\\mermi.hpp"
#include "C:\\Space Invaders\\include\\dusman.hpp"
#include "C:\\Space Invaders\\include\\carpismaDenetimi.hpp"
#include "C:\\Space Invaders\\include\\engel.hpp"
#include <string>
#include <vector>



int main(){
	srand(time(0));
	int a = rand() % 3 + 1;
	
	oyuncu gemi;
	bullet mermi;
	enemy dusman(a);
	carpismaDenetimi carpisma;
	engel engeller;
	int skor = 0;

	sf::Font font;
	if (!font.openFromFile("C:\\Space Invaders\\assets\\font\\RETROTECH.ttf"))
		return 1;

	sf::Text skorYazisi(font, "Score: 0", 42);
	skorYazisi.setPosition({ 25.f, 20.f });
	skorYazisi.setFillColor(sf::Color::White);

	std::vector<sf::CircleShape> kalpDaireleri;
	std::vector<sf::ConvexShape> kalpUcgenleri;

	for (int i = 0; i < 3; i++) {
		float x = 1605.f + i * 55.f;
		float y = 28.f;

		sf::CircleShape solDaire(13.f);
		solDaire.setPosition({ x, y });
		solDaire.setFillColor(sf::Color::Red);
		solDaire.setOutlineColor(sf::Color::Red);
		solDaire.setOutlineThickness(3.f);
		kalpDaireleri.push_back(solDaire);

		sf::CircleShape sagDaire(13.f);
		sagDaire.setPosition({ x + 17.f, y });
		sagDaire.setFillColor(sf::Color::Red);
		sagDaire.setOutlineColor(sf::Color::Red);
		sagDaire.setOutlineThickness(3.f);
		kalpDaireleri.push_back(sagDaire);

		sf::ConvexShape altParca;
		altParca.setPointCount(3);
		altParca.setPoint(0, { x - 1.f, y + 16.f });
		altParca.setPoint(1, { x + 43.f, y + 16.f });
		altParca.setPoint(2, { x + 21.f, y + 48.f });
		altParca.setFillColor(sf::Color::Red);
		altParca.setOutlineColor(sf::Color::Red);
		altParca.setOutlineThickness(3.f);
		kalpUcgenleri.push_back(altParca);
	}

	
	sf::RenderWindow pencere(sf::VideoMode({1800,1600}), "Space Invaders", sf::Style::Default);
	pencere.setFramerateLimit(60);
	pencere.setPosition({ 600,0 });



	while (pencere.isOpen()){

		while (auto olay = pencere.pollEvent()) {
			if (olay->is<sf::Event::Closed>()) {
				pencere.close();
			}
		}

	
		gemi.guncelle();

		if (gemi.hayattaMi()) {
			gemi.hareketEt();
			mermi.mermiAtesleme(gemi.gemiKonumu());
		}

		mermi.sarjorYenileme(gemi.gemiKonumu());
		dusman.dusmanHareketi(engeller);
		dusman.dusmanAtesi();
		skor += carpisma.oyuncuMermiDusmanCarpisma(dusman, mermi);
		skorYazisi.setString("Score: " + std::to_string(skor));
		carpisma.oyuncuMermiEngelCarpisma(mermi, engeller);
		carpisma.dusmanMermiEngelCarpisma(dusman, engeller);
		carpisma.dusmanMermiOyuncuCarpisma(dusman, gemi);
		



		// ÇİZİM
		pencere.clear(sf::Color::Black);

		dusman.dusmanMermiCiz(pencere);
		dusman.ciz(pencere);
		engeller.ciz(pencere);
		mermi.ciz(pencere);
		gemi.ciz(pencere);
		pencere.draw(skorYazisi);

		for (int i = 0; i < gemi.canSayisi(); i++) {
			pencere.draw(kalpDaireleri[i * 2]);
			pencere.draw(kalpDaireleri[i * 2 + 1]);
			pencere.draw(kalpUcgenleri[i]);
		}
		
		pencere.display();
	}
	return 0;
}




