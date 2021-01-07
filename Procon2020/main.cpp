/**
* @file main.cpp
* @brief Jyogiプロコン2020「偏差値を求めるプログラム」
* @author yukinissie
* @date 2021年1月7日
*/

#include "main.h"

int main(void) {
	// 偏差値計算機をインスタンスとして用意。
	DeviationCalculator *dc = new DeviationCalculator;
	
	// データの入力。
	dc->InputData(dc);
	// 偏差値の表示。
	dc->ShowDeviation(dc);

	delete dc;
	return 0;
}