#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class carpismaDenetimi;

class bullet {
private:
	friend class carpismaDenetimi;

	sf::Texture				mermiResmi;
	sf::Sprite				mermi;
	sf::Clock				zamanlayici;
	sf::Time				atesEtmeAraligi = sf::milliseconds(700);
	sf::Time				sonAtesZamani = sf::Time::Zero;
	std::vector<sf::Sprite> sarjor;
	float					mermiHizi = 20.0f;

public:
	bullet();

	void sifirla();
	bool mermiAtesleme(sf::Vector2f gemiKonumu);
	void sarjorYenileme(sf::Vector2f gemiKonumu);
	void ciz(sf::RenderWindow& pencere);


};
