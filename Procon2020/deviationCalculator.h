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

	void InputData(DeviationCalculator* dc);
	void InputStudentAndSubjectNumber();
	void InputSubjects();
	void InputAchievement();
	void OutputStudentAndSubjectNumber();
	void OutputSubjects();
	void OutputAchievement();
	void Calculation(DeviationCalculator* dc);
	void CalculateAverage();
	void CalculateStandardDeviation();
	void CalculateDeviation();
	void ShowResult(DeviationCalculator* dc);
	void ShowDeviation();
	void ShowAverage();
	void ShowStandardDeviation();

private:
	int studentNumber;
	int subjectNumber;
	string subjects[MAX_SUBJECT_NUMBER];
	void Caution();
	struct _statistics_table {
		int max;
		int min;
		int center;
		long double average;
		long double standardDeviation;
	} statisticsTable[MAX_SUBJECT_NUMBER];
	struct _achievement_table {
		string name;
		long double subjects[MAX_SUBJECT_NUMBER];
		long double deviation[MAX_SUBJECT_NUMBER];
	} achievementTable[MAX_STUDENT_NUMBER];
};
#endif // _DEVIATIONCALCULATOR_H_
