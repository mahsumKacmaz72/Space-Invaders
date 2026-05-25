#include "C:\\Space Invaders\\include\\engel.hpp"

engel::engel() {
	engelOlustur(230.f, 1240.f);
	engelOlustur(635.f, 1240.f);
	engelOlustur(1040.f, 1240.f);
	engelOlustur(1445.f, 1240.f);
}

void engel::engelOlustur(float baslangicX, float baslangicY) {
	int sekil[13][22] = {
		{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
		{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
		{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
		{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
		{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1},
		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1}
	};

	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 22; j++) {
			if (sekil[i][j] == 1) {
				sf::RectangleShape parca({ parcaBoyutu, parcaBoyutu });
				parca.setPosition({
					baslangicX + j * parcaBoyutu,
					baslangicY + i * parcaBoyutu
				});
				parca.setFillColor(sf::Color(60, 220, 95));
				engelParcalari.push_back(parca);
			}
		}
	}
}

bool engel::mermiCarpincaHasarAl(sf::FloatRect mermiSinirlari, bool oyuncuMermisiMi) {
	bool carptiMi = false;

	for (const auto& parca : engelParcalari) {
		if (parca.getGlobalBounds().findIntersection(mermiSinirlari)) {
			carptiMi = true;
			break;
		}
	}

	if (!carptiMi)
		return false;

	sf::Vector2f hasarMerkezi = {
		mermiSinirlari.position.x + mermiSinirlari.size.x / 2.f,
		oyuncuMermisiMi ? mermiSinirlari.position.y : mermiSinirlari.position.y + mermiSinirlari.size.y
	};

	for (int i = 0; i < static_cast<int>(engelParcalari.size()); i++) {
		sf::FloatRect parcaSinirlari = engelParcalari[i].getGlobalBounds();
		sf::Vector2f parcaMerkezi = {
			parcaSinirlari.position.x + parcaSinirlari.size.x / 2.f,
			parcaSinirlari.position.y + parcaSinirlari.size.y / 2.f
		};

		float xFarki = parcaMerkezi.x - hasarMerkezi.x;
		float yFarki = parcaMerkezi.y - hasarMerkezi.y;

		if (xFarki * xFarki + yFarki * yFarki <= hasarYaricapi * hasarYaricapi) {
			engelParcalari.erase(engelParcalari.begin() + i);
			i--;
		}
	}

	return true;
}

bool engel::dusmanAsagiInerseCarpisir(sf::FloatRect dusmanSinirlari, float asagiMiktari) {
	if (engelParcalari.empty())
		return false;

	float enUstEngelY = engelParcalari[0].getGlobalBounds().position.y;
	for (const auto& parca : engelParcalari) {
		float parcaY = parca.getGlobalBounds().position.y;
		if (parcaY < enUstEngelY)
			enUstEngelY = parcaY;
	}

	float dusmanAltY = dusmanSinirlari.position.y + dusmanSinirlari.size.y;
	return dusmanAltY + asagiMiktari >= enUstEngelY;
}

void engel::ciz(sf::RenderWindow& pencere) {
	for (const auto& parca : engelParcalari) {
		pencere.draw(parca);
	}
}
