#include "C:\\Space Invaders\\include\\dusman.hpp"

enemy::enemy():dusmanResmi("C:\\Space Invaders\\assets\\images\\uzayli1b.png"),dusman(dusmanResmi){
	srand(time(0));
	int a = rand()%3+1;

	switch (a) {
	case 1:
		if (!dusmanResmi.loadFromFile("C:\\Space Invaders\\assets\\images\\uzayli1b.png"))
			std::cout << "resim yuklenemedi";
		dusman.setTexture(dusmanResmi,true);
		break;
	case 2:
		if (!dusmanResmi.loadFromFile("C:\\Space Invaders\\assets\\images\\uzayli2b.png"))
			std::cout << "resim yuklenemedi";
		dusman.setTexture(dusmanResmi, true);
		break;
	case 3:
		if (!dusmanResmi.loadFromFile("C:\\Space Invaders\\assets\\images\\uzayli3b.png"))
			std::cout << "resim yuklenemedi";
		dusman.setTexture(dusmanResmi,true);
		break;
	}

	dusman.setScale({ 0.15,0.15 });
}

void enemy::ciz(sf::RenderWindow& pencere){
	pencere.draw(dusman);
	
}
