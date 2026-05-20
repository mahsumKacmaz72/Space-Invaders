#include "C:\\Space Invaders\\include\\dusman.hpp"

enemy::enemy(int dusmanSecici) : dusman(dusmanResmi) {

    switch (dusmanSecici) {
    case 1:
        if (!dusmanResmi.loadFromFile("C:\\Space Invaders\\assets\\images\\uzayli1b.png"))
            std::cout << "resim yuklenemedi";
        dusman.setScale({ 0.121f, 0.166f });
        break;
    case 2:
        if (!dusmanResmi.loadFromFile("C:\\Space Invaders\\assets\\images\\uzayli2b.png"))
            std::cout << "resim yuklenemedi";
        dusman.setScale({ 0.19f, 0.213f });
        break;
    case 3:
        if (!dusmanResmi.loadFromFile("C:\\Space Invaders\\assets\\images\\uzayli3b.png"))
            std::cout << "resim yuklenemedi";
        dusman.setScale({ 0.197f, 0.227f });
        break;
    }

    float b = 310;
    for (int i = 0; i < 8; i++) {
        dusmanlar.push_back(dusman);
        dusmanlar[i].setPosition({ b, 10.f });
        b += 100.f;
    }

    for (auto& d : dusmanlar) {
        d.setTexture(dusmanResmi, true);
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

