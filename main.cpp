#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "C:\\Space Invaders\\include\\oyuncu.hpp"
#include "C:\\Space Invaders\\include\\mermi.hpp"
#include "C:\\Space Invaders\\include\\dusman.hpp"
#include "C:\\Space Invaders\\include\\ufo.hpp"
#include "C:\\Space Invaders\\include\\carpismaDenetimi.hpp"
#include "C:\\Space Invaders\\include\\engel.hpp"
#include <string>
#include <vector>

enum class OyunDurumu {
	Baslangic,
	Oynaniyor,
	Sonuc
};

int main() {
	srand(time(0));
	int a = rand() % 3 + 1;

	oyuncu gemi;
	bullet mermi;
	enemy dusman(a);
	ufo bonusUfo;
	carpismaDenetimi carpisma;
	engel engeller;
	int skor = 0;
	OyunDurumu oyunDurumu = OyunDurumu::Baslangic;
	bool oncekiSpaceBasiliMi = false;
	bool oncekiRBasiliMi = false;

	sf::Font font;
	if (!font.openFromFile("C:\\Space Invaders\\assets\\font\\RETROTECH.ttf"))
		return 1;

	sf::SoundBuffer oyuncuAtesBuffer;
	sf::SoundBuffer dusmanAtesBuffer;
	sf::SoundBuffer dusmanVurulmaBuffer;
	sf::SoundBuffer oyuncuHasarBuffer;
	sf::SoundBuffer engelVurulmaBuffer;
	sf::SoundBuffer dalgaBuffer;
	sf::Music arkaPlanMuzigi;

	if (!oyuncuAtesBuffer.loadFromFile("C:\\Space Invaders\\assets\\sounds\\oyuncu_ates.wav") ||
		!dusmanAtesBuffer.loadFromFile("C:\\Space Invaders\\assets\\sounds\\dusman_ates.wav") ||
		!dusmanVurulmaBuffer.loadFromFile("C:\\Space Invaders\\assets\\sounds\\dusman_vuruldu.wav") ||
		!oyuncuHasarBuffer.loadFromFile("C:\\Space Invaders\\assets\\sounds\\oyuncu_hasar.wav") ||
		!engelVurulmaBuffer.loadFromFile("C:\\Space Invaders\\assets\\sounds\\engel_vuruldu.wav") ||
		!dalgaBuffer.loadFromFile("C:\\Space Invaders\\assets\\sounds\\yeni_dalga.wav") ||
		!arkaPlanMuzigi.openFromFile("C:\\Space Invaders\\assets\\sounds\\arka_plan.wav"))
		return 1;

	sf::Sound oyuncuAtesSesi(oyuncuAtesBuffer);
	sf::Sound dusmanAtesSesi(dusmanAtesBuffer);
	sf::Sound dusmanVurulmaSesi(dusmanVurulmaBuffer);
	sf::Sound oyuncuHasarSesi(oyuncuHasarBuffer);
	sf::Sound engelVurulmaSesi(engelVurulmaBuffer);
	sf::Sound dalgaSesi(dalgaBuffer);

	oyuncuAtesSesi.setVolume(35.f);
	dusmanAtesSesi.setVolume(32.f);
	dusmanVurulmaSesi.setVolume(42.f);
	oyuncuHasarSesi.setVolume(48.f);
	engelVurulmaSesi.setVolume(25.f);
	dalgaSesi.setVolume(35.f);
	arkaPlanMuzigi.setVolume(18.f);
	arkaPlanMuzigi.setLooping(true);
	arkaPlanMuzigi.play();

	sf::Text skorYazisi(font, "Score: 0", 42);
	skorYazisi.setPosition({ 25.f, 20.f });
	skorYazisi.setFillColor(sf::Color::White);

	sf::Text baslikYazisi(font, "SPACE INVADERS", 96);
	baslikYazisi.setFillColor(sf::Color(70, 255, 120));

	sf::Text baslaYazisi(font, "Baslamak icin SPACE tusuna bas", 44);
	baslaYazisi.setFillColor(sf::Color::White);

	sf::Text kontrolYazisi(font, "A / D veya Ok tuslari ile hareket et", 34);
	kontrolYazisi.setFillColor(sf::Color(180, 220, 255));

	sf::Text sonucBaslikYazisi(font, "OYUN BITTI", 86);
	sonucBaslikYazisi.setFillColor(sf::Color(255, 80, 80));

	sf::Text finalSkorYazisi(font, "Skor: 0", 52);
	finalSkorYazisi.setFillColor(sf::Color::White);

	sf::Text tekrarYazisi(font, "Tekrar oynamak icin R tusuna bas", 38);
	tekrarYazisi.setFillColor(sf::Color(180, 220, 255));

	auto ortala = [](sf::Text& yazi, float x, float y) {
		sf::FloatRect sinirlar = yazi.getLocalBounds();
		yazi.setOrigin({
			sinirlar.position.x + sinirlar.size.x / 2.f,
			sinirlar.position.y + sinirlar.size.y / 2.f
		});
		yazi.setPosition({ x, y });
	};

	ortala(baslikYazisi, 900.f, 570.f);
	ortala(baslaYazisi, 900.f, 730.f);
	ortala(kontrolYazisi, 900.f, 800.f);
	ortala(sonucBaslikYazisi, 900.f, 610.f);
	ortala(tekrarYazisi, 900.f, 815.f);

	auto oyunuBaslat = [&]() {
		gemi.sifirla();
		mermi.sifirla();
		dusman.sifirla(true);
		bonusUfo.sifirla();
		engeller.sifirla();
		skor = 0;
		skorYazisi.setString("Score: 0");
		oyunDurumu = OyunDurumu::Oynaniyor;
		dalgaSesi.play();
	};

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

	sf::RenderWindow pencere(sf::VideoMode({ 1800,1600 }), "Space Invaders", sf::Style::Default);
	pencere.setFramerateLimit(60);
	pencere.setPosition({ 600,0 });

	while (pencere.isOpen()) {
		while (auto olay = pencere.pollEvent()) {
			if (olay->is<sf::Event::Closed>()) {
				pencere.close();
			}
		}

		bool spaceBasiliMi = sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space);
		bool rBasiliMi = sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::R);

		if (oyunDurumu == OyunDurumu::Baslangic && spaceBasiliMi && !oncekiSpaceBasiliMi) {
			oyunuBaslat();
		}
		else if (oyunDurumu == OyunDurumu::Sonuc && rBasiliMi && !oncekiRBasiliMi) {
			oyunuBaslat();
		}

		oncekiSpaceBasiliMi = spaceBasiliMi;
		oncekiRBasiliMi = rBasiliMi;

		if (oyunDurumu == OyunDurumu::Oynaniyor) {
			gemi.guncelle();

			if (gemi.hayattaMi()) {
				gemi.hareketEt();
				if (mermi.mermiAtesleme(gemi.gemiKonumu()))
					oyuncuAtesSesi.play();
			}

			mermi.sarjorYenileme(gemi.gemiKonumu());
			bonusUfo.guncelle();

			if (dusman.dusmanHareketi(engeller))
				dalgaSesi.play();

			if (dusman.dusmanAtesi())
				dusmanAtesSesi.play();

			int kazanilanPuan = carpisma.oyuncuMermiDusmanCarpisma(dusman, mermi);
			if (kazanilanPuan > 0)
				dusmanVurulmaSesi.play();

			skor += kazanilanPuan;
			skorYazisi.setString("Score: " + std::to_string(skor));

			int ufoPuani = carpisma.oyuncuMermiUfoCarpisma(bonusUfo, mermi);
			if (ufoPuani > 0) {
				skor += ufoPuani;
				skorYazisi.setString("Score: " + std::to_string(skor));
				dusmanVurulmaSesi.play();
			}

			if (carpisma.oyuncuMermiEngelCarpisma(mermi, engeller))
				engelVurulmaSesi.play();

			if (carpisma.dusmanMermiEngelCarpisma(dusman, engeller))
				engelVurulmaSesi.play();

			if (carpisma.dusmanMermiOyuncuCarpisma(dusman, gemi))
				oyuncuHasarSesi.play();

			if (gemi.canSayisi() <= 0 || dusman.pencereAltinaDegdiMi(1600.f)) {
				finalSkorYazisi.setString("Skor: " + std::to_string(skor));
				ortala(finalSkorYazisi, 900.f, 725.f);
				oyunDurumu = OyunDurumu::Sonuc;
			}
		}

		pencere.clear(sf::Color::Black);

		if (oyunDurumu == OyunDurumu::Baslangic) {
			pencere.draw(baslikYazisi);
			pencere.draw(baslaYazisi);
			pencere.draw(kontrolYazisi);
		}
		else if (oyunDurumu == OyunDurumu::Sonuc) {
			pencere.draw(sonucBaslikYazisi);
			pencere.draw(finalSkorYazisi);
			pencere.draw(tekrarYazisi);
		}
		else {
			dusman.dusmanMermiCiz(pencere);
			bonusUfo.ciz(pencere);
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
		}

		pencere.display();
	}

	return 0;
}
