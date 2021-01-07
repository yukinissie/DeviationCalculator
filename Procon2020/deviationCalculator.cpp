#include "deviationCalculator.h"

DeviationCalculator::DeviationCalculator()
{
	this->studentNumber = 0;
	this->subjectNumber = 0;
	for (int i = 0; i < MAX_SUBJECT_NUMBER; i++) this->subjects[i] = "";
	for (int j = 0; j < MAX_STUDENT_NUMBER; j++) {
		for (int i = 0; i < MAX_SUBJECT_NUMBER; i++)
			this->achievementTable[j].subjects[i] = 0;
	}
}

DeviationCalculator::~DeviationCalculator()
{
}

void DeviationCalculator::InputData(DeviationCalculator *dc)
{
	// ���k���ƉȖڐ�����́B
	dc->InputStudentAndSubjectNumber();
	// ���k���ƉȖڐ����o�́B�i�f�o�b�O�p�j
	dc->OutputStudentAndSubjectNumber(); // TODO: �폜����B
	// �Ȗڂ��Ȗڐ������́B
	dc->InputSubjects();
	// �Ȗڂ��Ȗڐ����o�́B�i�f�o�b�O�p�j
	dc->OutputSubjects(); // TODO: �폜����B
	// ���т𐶓k�������́B
	dc->InputAchievement();
	// ���т𐶓k�����o�́B�i�f�o�b�O�p�j
	dc->OutputAchievement(); // TODO: �폜����B
}

void DeviationCalculator::InputStudentAndSubjectNumber() {
	cout << "�l���ƉȖڐ��̓��́B��j3 2" << endl;
	this->Caution();
	cin >> this->studentNumber >> this->subjectNumber;
}
void DeviationCalculator::OutputStudentAndSubjectNumber() {
	cout << "�l���F" << this->studentNumber << endl
		<< "�Ȗڐ��F" << this->subjectNumber << endl;
}

void DeviationCalculator::InputSubjects()
{
	cout << "�Ȗڂ��Ȗڐ������́B��j�p�� ���w" << endl;
	this->Caution();
	for (int i = 0; i < this->subjectNumber; i++) cin >> this->subjects[i];
}

void DeviationCalculator::OutputSubjects()
{
	for (int i = 0; i < this->subjectNumber; i++) cout << this->subjects[i] << endl;
}

void DeviationCalculator::InputAchievement()
{
	cout << "���т𐶓k�������́B��j��� 34 40\\n �_�����V�� 100 55\\n ����� 24 78\\n" << endl;
	this->Caution();
	for (int i = 0; i < this->studentNumber; i++) {
		cin >> this->achievementTable[i].name;
		for (int j = 0; j < this->subjectNumber; j++) cin >> this->achievementTable[i].subjects[j];
	}
}

void DeviationCalculator::OutputAchievement()
{
	for (int i = 0; i < this->studentNumber; i++) {
		cout << "���k" << i << "�F" << this->achievementTable[i].name << endl;
		for (int j = 0; j < this->subjectNumber; j++)
			cout << "�Ȗ�" << j << "�F" << this->achievementTable[i].subjects[j] << endl;
	}
}

void DeviationCalculator::ShowDeviation(DeviationCalculator *dc)
{
	dc->CalcAvg();
	dc->ShowAvg();

	// TODO: �W���΍������߁A�΍��l���o���B
}

void DeviationCalculator::CalcAvg()
{
	double sum[MAX_SUBJECT_NUMBER];
	for (int i = 0; i < MAX_SUBJECT_NUMBER; i++) sum[i] = 0;

	for (int j = 0; j < this->subjectNumber; j++) {
		for (int i = 0; i < this->studentNumber; i++) {
			sum[j] += this->achievementTable[i].subjects[j];
		}
		this->statisticsTable[j].average = sum[j] / this->studentNumber;
	}
}

void DeviationCalculator::ShowAvg()
{
	for (int i = 0; i < this->subjectNumber; i++) {
		cout << this->statisticsTable[i].average << endl;
	}
}

void DeviationCalculator::Caution()
{
	cout << "���ӁF���p�X�y�[�X�ŋ�؂��Ă��������I" << endl;
}
