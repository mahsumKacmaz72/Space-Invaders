#include "C:\\Space Invaders\\include\\dusman.hpp"

enemy::enemy(int dusmanSecici) : dusman(dusmanResmi) {

    if (!dusmanResmi1.loadFromFile("C:\\Space Invaders\\assets\\images\\uzayli1b.png"))
        std::cout << "resim yuklenemedi";

    if (!dusmanResmi2.loadFromFile("C:\\Space Invaders\\assets\\images\\uzayli2b.png"))
        std::cout << "resim yuklenemedi";

    if (!dusmanResmi3.loadFromFile("C:\\Space Invaders\\assets\\images\\uzayli3b.png"))
        std::cout << "resim yuklenemedi";

    float y = 10.f;

    for (int i = 0; i < 4; i++) {
        float x = 310.f;

        for (int j = 0; j < 8; j++) {
            dusmanlar.push_back(dusman);

            if (i == 0) {
                dusmanlar.back().setTexture(dusmanResmi1, true);
                dusmanlar.back().setScale({ 0.121f, 0.166f });
            }
            else if (i == 1) {
                dusmanlar.back().setTexture(dusmanResmi2, true);
                dusmanlar.back().setScale({ 0.19f, 0.213f });
            }
            else {
                dusmanlar.back().setTexture(dusmanResmi3, true);
                dusmanlar.back().setScale({ 0.197f, 0.227f });
            }

            dusmanlar.back().setPosition({ x, y });
            x += 100.f;
        }

        y -= 100.f;
    }
}










void enemy::dusmanHareketi(){
    float solSinir = 10.f;
    float sagSinir = 1400.f;
    bool asagiIn = false;
    
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

    for (auto& d : dusmanlar) {
        if (asagiIn)
            d.move({ 0.f,50.f });
       
        if (sagaGidiyorMu)
            d.move({ hiz, 0.f });
        else
            d.move({ -hiz, 0.f });
    }

    asagiIn = false;
}




void enemy::ciz(sf::RenderWindow& pencere) {
    for (const auto& d : dusmanlar) {
        pencere.draw(d);
    }
}

