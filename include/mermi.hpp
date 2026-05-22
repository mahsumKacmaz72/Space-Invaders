#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class bullet {
private:
	sf::Texture				mermiResmi;
	sf::Sprite				mermi;
	sf::Clock				zamanlayici;
	sf::Time				atesEtmeAraligi = sf::milliseconds(700);
	sf::Time				sonAtesZamani = sf::Time::Zero;
	std::vector<sf::Sprite> sarjor;
	float					mermiHizi = 12.0f;

public:
	bullet();

	void mermiAtesleme(sf::Vector2f gemiKonumu);
	void sarjorYenileme(sf::Vector2f gemiKonumu);
	void ciz(sf::RenderWindow& pencere);

	void dusmanAtesi();

};
