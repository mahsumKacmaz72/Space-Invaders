#include "C:\\Space Invaders\\include\\dusman.hpp"
#include "C:\\Space Invaders\\include\\engel.hpp"

enemy::enemy(int dusmanSecici) : dusman(dusmanResmi), dusmanMermisi(dusmanMermiResmi) {

    if (!dusmanResmi1.loadFromFile("C:\\Space Invaders\\assets\\images\\uzayli1b.png"))
        std::cout << "resim yuklenemedi";

    if (!dusmanResmi2.loadFromFile("C:\\Space Invaders\\assets\\images\\uzayli2b.png"))
        std::cout << "resim yuklenemedi";

    if (!dusmanResmi3.loadFromFile("C:\\Space Invaders\\assets\\images\\uzayli3b.png"))
        std::cout << "resim yuklenemedi";

    if (!dusmanMermiResmi.loadFromFile("C:\\Space Invaders\\assets\\images\\mermi1.png"))
        std::cout << "resim yuklenemedi";

    dusmanMermisi.setTexture(dusmanMermiResmi, true);
    dusmanMermisi.setScale({ 0.8f, 1.f });
	dusmanMermisi.setRotation(sf::degrees(180.f));

    std::vector<sf::Color> renkler = {
        sf::Color::Blue,
        sf::Color::Red,
        sf::Color::Green,
        sf::Color(180, 0, 255),
        sf::Color::White
    };

    int secilenRenk = rand() % static_cast<int>(renkler.size());
    sf::Color dusmanRengi1 = renkler[secilenRenk];
    renkler.erase(renkler.begin() + secilenRenk);

    secilenRenk = rand() % static_cast<int>(renkler.size());
    sf::Color dusmanRengi2 = renkler[secilenRenk];
    renkler.erase(renkler.begin() + secilenRenk);

    secilenRenk = rand() % static_cast<int>(renkler.size());
    sf::Color dusmanRengi3 = renkler[secilenRenk];

    float y = 150.f;
    for (int i = 0; i < 5; i++) {

        float x = 310.f;

        for (int j = 0; j < 11; j++) {
            dusmanlar.push_back(dusman);

            if (i == 0) {
                dusmanlar.back().setTexture(dusmanResmi1, true);
                dusmanlar.back().setScale({ 0.120f, 0.165f });
                dusmanlar.back().setColor(dusmanRengi1);
            }
            else if (i == 1 || i == 2) {
                dusmanlar.back().setTexture(dusmanResmi2, true);
                dusmanlar.back().setScale({ 0.189f, 0.212f });
                dusmanlar.back().setColor(dusmanRengi2);
            }
            else {
                dusmanlar.back().setTexture(dusmanResmi3, true);
                dusmanlar.back().setScale({ 0.196f, 0.226f });
                dusmanlar.back().setColor(dusmanRengi3);
            }

            dusmanlar.back().setPosition({ x, y });
            x += 110.f;
        }
        y += 105.f;
    }
}


//  HAREKET
void enemy::dusmanHareketi(engel& engeller){
    float solSinir = 5.f;
    float sagSinir = 1795.f;
    float asagiMiktari = 50.f;
    bool asagiIn = false;
    bool asagiInmeEngellendi = false;
    
    for (auto& d : dusmanlar) {
        float x = d.getPosition().x;

        if (x <= solSinir){
            sagaGidiyorMu = true;
            asagiIn = true;
            break;
        }

        if (x + 90 >= sagSinir){
            sagaGidiyorMu = false;
            asagiIn = true;
            break;
        }
    }

    if (asagiIn) {
        for (const auto& d : dusmanlar) {
            if (engeller.dusmanAsagiInerseCarpisir(d.getGlobalBounds(), asagiMiktari)) {
                asagiInmeEngellendi = true;
                break;
            }
        }
    }

    for (auto& d : dusmanlar) {
            if (asagiIn && !asagiInmeEngellendi)
                d.move({ 0.f, asagiMiktari });
       
            if (sagaGidiyorMu)
                d.move({ hiz, 0.f });
            else
                d.move({ -hiz, 0.f });
        
    }
    asagiIn = false;
}

// DUSMAN MERMİSİ

void enemy::dusmanAtesi() {
    sf::Time simdikiZaman = dusmanZamanlayici.getElapsedTime();

    if (!dusmanlar.empty() && simdikiZaman - sonDusmanAtesZamani >= dusmanAtesEtmeAraligi) {
        int atesEdenDusmanSayisi = rand() % 100 + 31;
        std::vector<int> secilenDusmanlar;

        if (atesEdenDusmanSayisi > static_cast<int>(dusmanlar.size()))
            atesEdenDusmanSayisi = static_cast<int>(dusmanlar.size());

        for (int i = 0; i < atesEdenDusmanSayisi; i++) {
            int rastgeleDusman;
            bool ayniDusman;

            do {
                ayniDusman = false;
                rastgeleDusman = rand() % static_cast<int>(dusmanlar.size());

                for (const auto& secilenDusman : secilenDusmanlar) {
                    if (secilenDusman == rastgeleDusman) {
                        ayniDusman = true;
                        break;
                    }
                }
            } while (ayniDusman);

            secilenDusmanlar.push_back(rastgeleDusman);

            dusmanMermisi.setPosition({
                dusmanlar[rastgeleDusman].getPosition().x + 45.f,
                dusmanlar[rastgeleDusman].getPosition().y + 45.f
            });

            dusmanMermileri.push_back(dusmanMermisi);
        }

        sonDusmanAtesZamani = simdikiZaman;
        dusmanAtesEtmeAraligi = sf::milliseconds(rand() % 1500 + 2000);
    }

    for (int i = 0; i < static_cast<int>(dusmanMermileri.size()); i++) {
        dusmanMermileri[i].move({ 0.f, dusmanMermiHizi });

        if (dusmanMermileri[i].getPosition().y >= 1600.f) {
            dusmanMermileri.erase(dusmanMermileri.begin() + i);
            i--;
        }
    }
}



// ÇİZİM
void enemy::ciz(sf::RenderWindow& pencere) {
    for (const auto& d : dusmanlar) {
        pencere.draw(d);
    }

    
}

void enemy::dusmanMermiCiz(sf::RenderWindow& pencere){
    for (const auto& mermi : dusmanMermileri) {
        pencere.draw(mermi);
    }
}



