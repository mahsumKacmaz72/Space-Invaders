#pragma once
#include "C:\\Space Invaders\\include\\dusman.hpp"
#include "C:\\Space Invaders\\include\\mermi.hpp"
#include "C:\\Space Invaders\\include\\oyuncu.hpp"
#include "C:\\Space Invaders\\include\\engel.hpp"
#include "C:\\Space Invaders\\include\\ufo.hpp"

class carpismaDenetimi {
public:
	int oyuncuMermiDusmanCarpisma(enemy& dusman, bullet& mermi);
	int oyuncuMermiUfoCarpisma(ufo& bonusUfo, bullet& mermi);
	bool dusmanMermiOyuncuCarpisma(enemy& dusman, oyuncu& gemi);
	bool oyuncuMermiEngelCarpisma(bullet& mermi, engel& engeller);
	bool dusmanMermiEngelCarpisma(enemy& dusman, engel& engeller);
};
