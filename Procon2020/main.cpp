/**
* @file main.cpp
* @brief Jyogiプロコン2020「偏差値を求めるプログラム」
* @author yukinissie
* @date 2021年1月7日
*/

#include "main.h"

int main(void) {
	DeviationCalculator *dc = new DeviationCalculator;
	
	dc->InputData(dc);
	dc->Calculation(dc);
	dc->ShowResult(dc);

	delete dc;
	return 0;
}