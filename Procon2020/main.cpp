/**
* @file main.cpp
* @brief Jyogiプロコン2020「偏差値を求めるプログラム」
* @author yukinissie
* @date 2021年1月7日
*/

#include "deviationCalculator.h"

int main(void) {
	DeviationCalculator *dc = new DeviationCalculator;
	
	dc->InputData();
	dc->Calculation();
	dc->ShowResult();

	delete dc;
	return 0;
}