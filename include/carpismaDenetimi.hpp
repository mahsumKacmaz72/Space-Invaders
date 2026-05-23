#pragma once
#include "C:\\Space Invaders\\include\\dusman.hpp"
#include "C:\\Space Invaders\\include\\mermi.hpp"
#include "C:\\Space Invaders\\include\\oyuncu.hpp"

class carpismaDenetimi {
public:
	void oyuncuMermiDusmanCarpisma(enemy& dusman, bullet& mermi);
	void dusmanMermiOyuncuCarpisma(enemy& dusman, oyuncu& gemi);
};
