/**
* @file deviationCalculator.cpp
* @brief Jyogiプロコン2020「偏差値を求めるプログラム」の計算機の中身
* @author yukinissie
* @date 2021年1月7日
*/

#include "deviationCalculator.h"

DeviationCalculator::DeviationCalculator()
{
}

DeviationCalculator::~DeviationCalculator()
{
}

void DeviationCalculator::InputData()
{
	this->InputStudentAndSubjectNumber();
	this->InputSubjects();
	this->InputAchievement();

	if (DEBUG) {
		this->OutputStudentAndSubjectNumber();
		this->OutputSubjects();
		this->OutputAchievement();
	}
}

void DeviationCalculator::InputStudentAndSubjectNumber() {
	cout << "人数と科目数の入力。例）3 2" << endl;
	DeviationCalculator::Caution();
	cin >> this->studentNumber >> this->subjectNumber;
}
void DeviationCalculator::InputSubjects()
{
	cout << "科目を科目数分入力。例）英語 数学" << endl;
	DeviationCalculator::Caution();
	for (int i = 0; i < this->subjectNumber; i++) cin >> this->subjects[i];
}
void DeviationCalculator::InputAchievement()
{
	cout << "成績を生徒数分入力。例）板崎幾次 34 40\\n 神惠愛之助 100 55\\n 美穂繁 24 78\\n" << endl;
	DeviationCalculator::Caution();
	for (int i = 0; i < this->studentNumber; i++) {
		cin >> this->achievementTable[i].name;
		for (int j = 0; j < this->subjectNumber; j++) cin >> this->achievementTable[i].subjects[j];
	}
}
void DeviationCalculator::Caution()
{
	cout << "注意：半角スペースで区切ってください！" << endl;
}

void DeviationCalculator::OutputStudentAndSubjectNumber() const
{
	cout << "人数：" << this->studentNumber << endl
		<< "科目数：" << this->subjectNumber << endl;
}
void DeviationCalculator::OutputSubjects() const
{
	for (int i = 0; i < this->subjectNumber; i++) cout << this->subjects[i] << endl;
}
void DeviationCalculator::OutputAchievement() const
{
	for (int i = 0; i < this->studentNumber; i++) {
		cout << "生徒" << i << "：" << this->achievementTable[i].name << endl;
		for (int j = 0; j < this->subjectNumber; j++)
			cout << "科目" << j << "：" << this->achievementTable[i].subjects[j] << endl;
	}
}

void DeviationCalculator::Calculation()
{
	this->CalculateAverage();
	this->CalculateStandardDeviation();
	this->CalculateDeviation();
}

void DeviationCalculator::CalculateAverage()
{
	long double sum[MAX_SUBJECT_NUMBER] = { 0 };

	for (int j = 0; j < this->subjectNumber; j++) {
		for (int i = 0; i < this->studentNumber; i++) {
			sum[j] += this->achievementTable[i].subjects[j];
		}
		this->statisticsTable[j].average = sum[j] / this->studentNumber;
	}
}
void DeviationCalculator::CalculateStandardDeviation()
{
	long double sum[MAX_SUBJECT_NUMBER] = { 0 };

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

void DeviationCalculator::ShowResult()
{
	this->ShowAverage();
	this->ShowStandardDeviation();
	this->ShowDeviation();
}

void DeviationCalculator::ShowAverage() const
{
	cout << "------平均値------" << endl;
	for (int i = 0; i < this->subjectNumber; i++) {
		cout << this->subjects[i] << "：" << this->statisticsTable[i].average << endl;
	}
}
void DeviationCalculator::ShowStandardDeviation() const
{
	cout << "------標準偏差------" << endl;
	for (int i = 0; i < this->subjectNumber; i++) {
		cout << this->subjects[i] << "：" << this->statisticsTable[i].standardDeviation << endl;
	}
}
void DeviationCalculator::ShowDeviation() const
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
