#include "C:\\Space Invaders\\include\\carpismaDenetimi.hpp"

int carpismaDenetimi::oyuncuMermiDusmanCarpisma(enemy& dusman, bullet& mermi){
	int kazanilanPuan = 0;

	if (dusman.dalgaIniyorMu)
		return kazanilanPuan;

	for (int i = 0; i < static_cast<int>(dusman.dusmanlar.size()); i++) {
		for (int j = 0; j < static_cast<int>(mermi.sarjor.size()); j++) {
			if (mermi.sarjor[j].getGlobalBounds().findIntersection(dusman.dusmanlar[i].getGlobalBounds())) {
				mermi.sarjor.erase(mermi.sarjor.begin() + j);
				kazanilanPuan += dusman.dusmanPuanlari[i];
				dusman.dusmanPuanlari.erase(dusman.dusmanPuanlari.begin() + i);
				dusman.dusmanlar.erase(dusman.dusmanlar.begin() + i);
				i--;
				break;
			}
		}
	}

	return kazanilanPuan;
}

int carpismaDenetimi::oyuncuMermiUfoCarpisma(ufo& bonusUfo, bullet& mermi) {
	if (!bonusUfo.aktifMi)
		return 0;

	for (int i = 0; i < static_cast<int>(mermi.sarjor.size()); i++) {
		if (mermi.sarjor[i].getGlobalBounds().findIntersection(bonusUfo.ufoGemisi.getGlobalBounds())) {
			mermi.sarjor.erase(mermi.sarjor.begin() + i);
			bonusUfo.aktifMi = false;
			bonusUfo.sonrakiCikisSuresiniAyarla();
			return 300;
		}
	}

	return 0;
}

bool carpismaDenetimi::dusmanMermiOyuncuCarpisma(enemy& dusman, oyuncu& gemi) {
	if (gemi.gemiSilindiMi || gemi.gemiGeciciGizliMi)
		return false;

	for (int i = 0; i < static_cast<int>(dusman.dusmanMermileri.size()); i++) {
		if (dusman.dusmanMermileri[i].getGlobalBounds().findIntersection(gemi.gemi.getGlobalBounds())) {
			dusman.dusmanMermileri.erase(dusman.dusmanMermileri.begin() + i);
			gemi.hasarAl();
			return true;
		}
	}

	return false;
}

bool carpismaDenetimi::oyuncuMermiEngelCarpisma(bullet& mermi, engel& engeller) {
	bool carpismaOldu = false;

	for (int i = 0; i < static_cast<int>(mermi.sarjor.size()); i++) {
		if (engeller.mermiCarpincaHasarAl(mermi.sarjor[i].getGlobalBounds(), true)) {
			mermi.sarjor.erase(mermi.sarjor.begin() + i);
			i--;
			carpismaOldu = true;
		}
	}

	return carpismaOldu;
}

bool carpismaDenetimi::dusmanMermiEngelCarpisma(enemy& dusman, engel& engeller) {
	bool carpismaOldu = false;

	for (int i = 0; i < static_cast<int>(dusman.dusmanMermileri.size()); i++) {
		if (engeller.mermiCarpincaHasarAl(dusman.dusmanMermileri[i].getGlobalBounds(), false)) {
			dusman.dusmanMermileri.erase(dusman.dusmanMermileri.begin() + i);
			i--;
			carpismaOldu = true;
		}
	}

	return carpismaOldu;
}
