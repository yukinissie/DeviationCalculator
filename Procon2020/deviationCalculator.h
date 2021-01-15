/**
* @file deviationCalculator.h
* @brief Jyogiプロコン2020「偏差値を求めるプログラム」の計算機の定義
* @author yukinissie
* @date 2021年1月7日
*/

#ifndef _DEVIATIONCALCULATOR_H_
#define _DEVIATIONCALCULATOR_H_
#define MAX_STUDENT_NUMBER 128
#define MAX_SUBJECT_NUMBER 16

#define DEBUG false

#include <iostream>
using namespace std;

class DeviationCalculator
{
public:
	DeviationCalculator();
	~DeviationCalculator();

	void InputData();
	void Calculation();
	void ShowResult();

private:
	void InputStudentAndSubjectNumber();
	void InputSubjects();
	void InputAchievement();
	void OutputStudentAndSubjectNumber() const;
	void OutputSubjects() const;
	void OutputAchievement() const;
	void CalculateAverage();
	void CalculateStandardDeviation();
	void CalculateDeviation();
	void ShowDeviation() const;
	void ShowAverage() const;
	void ShowStandardDeviation() const;
	static void Caution();

	int studentNumber = 0;
	int subjectNumber = 0;
	string subjects[MAX_SUBJECT_NUMBER] = { "" };
	struct _statistics_table {
		long double average = 0.0;
		long double standardDeviation = 0.0;
	} statisticsTable[MAX_SUBJECT_NUMBER];
	struct _achievement_table {
		string name = "";
		long double subjects[MAX_SUBJECT_NUMBER] = { 0.0 };
		long double deviation[MAX_SUBJECT_NUMBER] = { 0.0 };
	} achievementTable[MAX_STUDENT_NUMBER];
};
#endif // _DEVIATIONCALCULATOR_H_
