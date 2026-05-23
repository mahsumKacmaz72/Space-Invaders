#include "C:\\Space Invaders\\include\\carpismaDenetimi.hpp"

void carpismaDenetimi::oyuncuMermiDusmanCarpisma(enemy& dusman, bullet& mermi){
	for (int i = 0; i < static_cast<int>(dusman.dusmanlar.size()); i++) {
		for (int j = 0; j < static_cast<int>(mermi.sarjor.size()); j++) {
			if (mermi.sarjor[j].getGlobalBounds().findIntersection(dusman.dusmanlar[i].getGlobalBounds())) {
				mermi.sarjor.erase(mermi.sarjor.begin() + j);
				dusman.dusmanlar.erase(dusman.dusmanlar.begin() + i);
				i--;
				break;
			}
		}
	}
}
