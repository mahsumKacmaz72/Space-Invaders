#include "C:\\Space Invaders\\include\\dusman.hpp"

enemy::enemy():dusmanResmi("C:\\Space Invaders\\assets\\images\\uzayli1b.png"),dusman(dusmanResmi){
	srand(time(0));
	int a = 3;//rand() % 3 + 1;

	switch (a) {
	case 1:
		if (!dusmanResmi.loadFromFile("C:\\Space Invaders\\assets\\images\\uzayli1b.png"))
			std::cout << "resim yuklenemedi";
		dusman.setTexture(dusmanResmi,true);
		dusman.setScale({ 0.121,0.166 });
		break;
	case 2:
		if (!dusmanResmi.loadFromFile("C:\\Space Invaders\\assets\\images\\uzayli2b.png"))
			std::cout << "resim yuklenemedi";
		dusman.setTexture(dusmanResmi, true);
		dusman.setScale({ 0.19,0.213 });
		break;
	case 3:
		if (!dusmanResmi.loadFromFile("C:\\Space Invaders\\assets\\images\\uzayli3b.png"))
			std::cout << "resim yuklenemedi";
		dusman.setTexture(dusmanResmi,true);
		dusman.setScale({ 0.197,0.227 });
		break;
	}

	dusman.setPosition({ 10,10 });

}

void enemy::dusmanSatirlari(){

}

void enemy::ciz(sf::RenderWindow& pencere){
	pencere.draw(dusman);
	
}
