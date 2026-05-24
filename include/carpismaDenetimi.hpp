#pragma once
#include "C:\\Space Invaders\\include\\dusman.hpp"
#include "C:\\Space Invaders\\include\\mermi.hpp"
#include "C:\\Space Invaders\\include\\oyuncu.hpp"
#include "C:\\Space Invaders\\include\\engel.hpp"

class carpismaDenetimi {
public:
	void oyuncuMermiDusmanCarpisma(enemy& dusman, bullet& mermi);
	void dusmanMermiOyuncuCarpisma(enemy& dusman, oyuncu& gemi);
	void oyuncuMermiEngelCarpisma(bullet& mermi, engel& engeller);
	void dusmanMermiEngelCarpisma(enemy& dusman, engel& engeller);
};
