#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

class carpismaDenetimi;
class engel;

class enemy {
private:
	friend class				carpismaDenetimi;

	sf::Texture					dusmanResmi;
	sf::Texture					dusmanResmi1;
	sf::Texture					dusmanResmi2;
	sf::Texture					dusmanResmi3;
	sf::Texture					dusmanMermiResmi;
	sf::Sprite					dusman;
	sf::Sprite					dusmanMermisi;
	std::vector<sf::Sprite>		dusmanlar;
	std::vector<sf::Sprite>		dusmanMermileri;
	std::vector<int>			dusmanPuanlari;
	std::vector<sf::Vector2f>	dusmanHedefKonumlari;

	int							yon = 1;
	int							baslangicDusmanSayisi = 0;
	float						baslangicHizi = 1.f;
	float						hiz = 1.f;
	float						maksimumHiz = 5.f;
	float						dusmanMermiHizi = 15.f;
	float						dalgaInisHizi = 8.f;
	bool						sagaGidiyorMu = true;
	bool						dalgaIniyorMu = false;
	sf::Clock					dusmanZamanlayici;
	sf::Time					dusmanAtesEtmeAraligi = sf::milliseconds(2000);
	sf::Time					sonDusmanAtesZamani = sf::Time::Zero;

	void dusmanlariOlustur(float yBaslangicFarki);
	void yeniDalgaBaslat();
	void dalgaInisiniGuncelle();

public:
	enemy(int dusmanSecici);
	void sifirla(bool yukaridanBaslasin);
	void hizGuncelle();
	bool dusmanHareketi(engel& engeller);
	bool dusmanAtesi();
	void ciz(sf::RenderWindow& pencere);
	void dusmanMermiCiz(sf::RenderWindow& pencere);
};
