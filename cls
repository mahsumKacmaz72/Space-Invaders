warning: in the working copy of 'CMakeLists.txt', LF will be replaced by CRLF the next time Git touches it
[1mdiff --git a/CMakeLists.txt b/CMakeLists.txt[m
[1mindex 80c4161..8c11ee3 100644[m
[1m--- a/CMakeLists.txt[m
[1m+++ b/CMakeLists.txt[m
[36m@@ -21,10 +21,11 @@[m [mfind_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)[m
 [m
 add_executable(SpaceInvaders[m
     main.cpp[m
[31m-   [m
[32m+[m
     "include/oyuncu.hpp" "src/oyuncu.cpp"[m
[31m-    "include/mermi.hpp" "src/mermi.cpp"[m
[31m-      )[m
[32m+[m[32m    "include/mermi.hpp"  "src/mermi.cpp"[m
[32m+[m[32m    "include/dusman.hpp"  "src/dusman.cpp"[m[41m [m
[32m+[m[32m    "include/colorManager.hpp"  "src/colorManager.cpp")[m
 [m
 target_link_libraries(SpaceInvaders PRIVATE[m
     SFML::Graphics[m
[1mdiff --git a/include/mermi.hpp b/include/mermi.hpp[m
[1mindex 1701c98..dfd1ba1 100644[m
[1m--- a/include/mermi.hpp[m
[1m+++ b/include/mermi.hpp[m
[36m@@ -7,7 +7,7 @@[m [mprivate:[m
 	sf::Texture				mermiResmi;[m
 	sf::Sprite				mermi;[m
 	sf::Clock				zamanlayici;[m
[31m-	sf::Time				atesEtmeAraligi = sf::milliseconds(200);[m
[32m+[m	[32msf::Time				atesEtmeAraligi = sf::milliseconds(150);[m
 	sf::Time				sonAtesZamani = sf::Time::Zero;[m
 	std::vector<sf::Sprite> sarjor;[m
 	float					mermiHizi = 12.0f;[m
[1mdiff --git a/main.cpp b/main.cpp[m
[1mindex ac9b7ac..6a14ae9 100644[m
[1m--- a/main.cpp[m
[1m+++ b/main.cpp[m
[36m@@ -1,14 +1,22 @@[m
 #include <SFML/Graphics.hpp>[m
 #include "C:\\Space Invaders\\include\\oyuncu.hpp"[m
 #include "C:\\Space Invaders\\include\\mermi.hpp"[m
[32m+[m[32m#include "C:\\Space Invaders\\include\\dusman.hpp"[m
[32m+[m
 [m
 [m
 int main(){[m
 	oyuncu gemi;[m
 	bullet mermi;[m
[32m+[m	[32menemy dusman;[m
[32m+[m
[32m+[m[41m	[m
 	[m
[31m-	sf::RenderWindow pencere(sf::VideoMode({ 1600, 1200 }), "Space Invaders");[m
[31m-	pencere.setFramerateLimit(60);[m
[32m+[m	[32msf::RenderWindow pencere(sf::VideoMode::getDesktopMode(), "Space Invaders");[m
[32m+[m	[32m//pencere.setFramerateLimit(60);[m
[32m+[m	[32mpencere.setVerticalSyncEnabled(true);[m
[32m+[m
[32m+[m
 [m
 [m
 	while (pencere.isOpen()){[m
[36m@@ -29,6 +37,7 @@[m [mint main(){[m
 [m
 		pencere.clear(sf::Color::Black);[m
 [m
[32m+[m		[32mdusman.ciz(pencere);[m
 		mermi.ciz(pencere);[m
 		gemi.ciz(pencere);[m
 [m
[1mdiff --git a/src/mermi.cpp b/src/mermi.cpp[m
[1mindex def93fd..334df9d 100644[m
[1m--- a/src/mermi.cpp[m
[1m+++ b/src/mermi.cpp[m
[36m@@ -1,7 +1,8 @@[m
 #include "C:\Space Invaders\include\mermi.hpp"[m
 [m
 bullet::bullet() :mermiResmi("C:\\Space Invaders\\assets\\images\\mermi1.png"), mermi(mermiResmi) {[m
[31m-	mermi.setScale({ 0.8f, 1.f });[m
[32m+[m	[32mmermi.setScale({ 0.6f, 0.8f });[m
[32m+[m	[32m//mermi.setColor(sf::Color::Green);[m
 }[m
 [m
 void bullet::mermiAtesleme(sf::Vector2f gemiKonumu){[m
[1mdiff --git a/src/oyuncu.cpp b/src/oyuncu.cpp[m
[1mindex 0bf2820..7546933 100644[m
[1m--- a/src/oyuncu.cpp[m
[1m+++ b/src/oyuncu.cpp[m
[36m@@ -3,7 +3,7 @@[m
 [m
 [m
 oyuncu::oyuncu():gemiResmi("C:\\Space Invaders\\assets\\images\\uzayGemisi2.png"),gemi(gemiResmi){[m
[31m-	gemi.setPosition({ 750,1070 });[m
[32m+[m	[32mgemi.setPosition({ 550,1650 });[m
 	gemi.setScale({ 1.4f,1.25f });[m
 	gemiBoyutu = 140.f;	[m
 }[m
[36m@@ -13,13 +13,13 @@[m [moyuncu::oyuncu():gemiResmi("C:\\Space Invaders\\assets\\images\\uzayGemisi2.png"[m
 [m
 void oyuncu::hareketEt() {[m
 	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)){ [m
[31m-		if(gemi.getPosition().x >= 13)[m
[31m-			gemi.move({ -15.f, 0 });[m
[32m+[m		[32mif(gemi.getPosition().x >= 10)[m
[32m+[m			[32mgemi.move({ -10.f, 0 });[m
 	}[m
 [m
 	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)){ [m
[31m-		if(gemi.getPosition().x + gemiBoyutu <= 1600)[m
[31m-			gemi.move({ 15.f, 0 });[m
[32m+[m		[32mif(gemi.getPosition().x + gemiBoyutu <= 1200)[m
[32m+[m			[32mgemi.move({ 10.f, 0 });[m
 	}[m
 }[m
 [m
