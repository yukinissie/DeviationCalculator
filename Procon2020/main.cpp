/**
* @file main.cpp
* @brief Jyogi�v���R��2020�u�΍��l�����߂�v���O�����v
* @author yukinissie
* @date 2021�N1��7��
*/

#include "main.h"

int main(void) {
	// �΍��l�v�Z�@���C���X�^���X�Ƃ��ėp�ӁB
	DeviationCalculator *dc = new DeviationCalculator;
	
	// �f�[�^�̓��́B
	dc->InputData(dc);
	// �΍��l�̕\���B
	dc->ShowDeviation(dc);

	delete dc;
	return 0;
}