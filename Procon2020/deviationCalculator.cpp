/**
* @file deviationCalculator.cpp
* @brief Jyogiプロコン2020「偏差値を求めるプログラム」の計算機の中身
* @author yukinissie
* @date 2021年1月7日
*/

#include "deviationCalculator.h"

DeviationCalculator::DeviationCalculator()
{
	this->studentNumber = 0;
	this->subjectNumber = 0;
	for (int i = 0; i < MAX_SUBJECT_NUMBER; i++) this->subjects[i] = "";
	for (int j = 0; j < MAX_STUDENT_NUMBER; j++) {
		for (int i = 0; i < MAX_SUBJECT_NUMBER; i++) {
			this->achievementTable[j].subjects[i] = 0.0;
			this->achievementTable[j].deviation[i] = 0.0;
		}
	}
}

DeviationCalculator::~DeviationCalculator()
{
}

void DeviationCalculator::InputData(DeviationCalculator *dc)
{
	dc->InputStudentAndSubjectNumber();
	dc->InputSubjects();
	dc->InputAchievement();

	if (DEBUG) {
		dc->OutputStudentAndSubjectNumber();
		dc->OutputSubjects();
		dc->OutputAchievement();
	}
}

void DeviationCalculator::InputStudentAndSubjectNumber() {
	cout << "人数と科目数の入力。例）3 2" << endl;
	this->Caution();
	cin >> this->studentNumber >> this->subjectNumber;
}
void DeviationCalculator::InputSubjects()
{
	cout << "科目を科目数分入力。例）英語 数学" << endl;
	this->Caution();
	for (int i = 0; i < this->subjectNumber; i++) cin >> this->subjects[i];
}
void DeviationCalculator::InputAchievement()
{
	cout << "成績を生徒数分入力。例）板崎幾次 34 40\\n 神惠愛之助 100 55\\n 美穂繁 24 78\\n" << endl;
	this->Caution();
	for (int i = 0; i < this->studentNumber; i++) {
		cin >> this->achievementTable[i].name;
		for (int j = 0; j < this->subjectNumber; j++) cin >> this->achievementTable[i].subjects[j];
	}
}
void DeviationCalculator::Caution()
{
	cout << "注意：半角スペースで区切ってください！" << endl;
}

void DeviationCalculator::OutputStudentAndSubjectNumber() {
	cout << "人数：" << this->studentNumber << endl
		<< "科目数：" << this->subjectNumber << endl;
}
void DeviationCalculator::OutputSubjects()
{
	for (int i = 0; i < this->subjectNumber; i++) cout << this->subjects[i] << endl;
}
void DeviationCalculator::OutputAchievement()
{
	for (int i = 0; i < this->studentNumber; i++) {
		cout << "生徒" << i << "：" << this->achievementTable[i].name << endl;
		for (int j = 0; j < this->subjectNumber; j++)
			cout << "科目" << j << "：" << this->achievementTable[i].subjects[j] << endl;
	}
}

void DeviationCalculator::Calculation(DeviationCalculator* dc)
{
	dc->CalculateAverage();
	dc->CalculateStandardDeviation();
	dc->CalculateDeviation();
}

void DeviationCalculator::CalculateAverage()
{
	long double sum[MAX_SUBJECT_NUMBER];
	for (int i = 0; i < MAX_SUBJECT_NUMBER; i++) sum[i] = 0;

	for (int j = 0; j < this->subjectNumber; j++) {
		for (int i = 0; i < this->studentNumber; i++) {
			sum[j] += this->achievementTable[i].subjects[j];
		}
		this->statisticsTable[j].average = sum[j] / this->studentNumber;
	}
}
void DeviationCalculator::CalculateStandardDeviation()
{
	long double sum[MAX_SUBJECT_NUMBER];
	for (int i = 0; i < MAX_SUBJECT_NUMBER; i++) sum[i] = 0;

	for (int j = 0; j < this->subjectNumber; j++) {
		for (int i = 0; i < this->studentNumber; i++) {
			sum[j] += powl(this->achievementTable[i].subjects[j] - this->statisticsTable[j].average, 2.0);
		}
		this->statisticsTable[j].standardDeviation = sqrtl(sum[j] / this->studentNumber);
	}
}
void DeviationCalculator::CalculateDeviation()
{
	for (int j = 0; j < this->subjectNumber; j++) {
		for (int i = 0; i < this->studentNumber; i++) {
			this->achievementTable[i].deviation[j] = ((this->achievementTable[i].subjects[j] - this->statisticsTable[j].average) / this->statisticsTable[j].standardDeviation) * 10 + 50;
		}
	}
}

void DeviationCalculator::ShowResult(DeviationCalculator* dc)
{
	dc->ShowAverage();
	dc->ShowStandardDeviation();
	dc->ShowDeviation();
}

void DeviationCalculator::ShowAverage()
{
	cout << "------平均値------" << endl;
	for (int i = 0; i < this->subjectNumber; i++) {
		cout << this->subjects[i] << "：" << this->statisticsTable[i].average << endl;
	}
}
void DeviationCalculator::ShowStandardDeviation()
{
	cout << "------標準偏差------" << endl;
	for (int i = 0; i < this->subjectNumber; i++) {
		cout << this->subjects[i] << "：" << this->statisticsTable[i].standardDeviation << endl;
	}
}
void DeviationCalculator::ShowDeviation()
{
	cout << "------偏差値------" << endl;
	for (int i = 0; i < this->studentNumber; i++) {
		cout << this->achievementTable[i].name << endl;
		for (int j = 0; j < this->subjectNumber; j++) {
			cout << this->subjects[j] << "：" <<  this->achievementTable[i].deviation[j] << endl;
		}
		cout << "------------------" << endl;
	}
}
