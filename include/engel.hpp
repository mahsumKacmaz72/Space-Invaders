#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class engel {
private:
	std::vector<sf::RectangleShape> engelParcalari;
	float parcaBoyutu = 8.f;
	float hasarYaricapi = 18.f;

	void engelOlustur(float baslangicX, float baslangicY);

public:
	engel();

	bool mermiCarpincaHasarAl(sf::FloatRect mermiSinirlari, bool oyuncuMermisiMi);
	void ciz(sf::RenderWindow& pencere);
};
