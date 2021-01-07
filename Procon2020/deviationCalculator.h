#ifndef _DEVIATIONCALCULATOR_H_
#define _DEVIATIONCALCULATOR_H_
#define MAX_SUBJECT_NUMBER 50
#define MAX_STUDENT_NUMBER 100

#include <iostream>
using namespace std;

class DeviationCalculator
{
public:
	DeviationCalculator();
	~DeviationCalculator();

	void InputData(DeviationCalculator *dc);
	void InputStudentAndSubjectNumber();
	void OutputStudentAndSubjectNumber();
	void InputSubjects();
	void OutputSubjects();
	void InputAchievement();
	void OutputAchievement();
	void ShowDeviation(DeviationCalculator *dc);
	void CalcAvg();
	void ShowAvg();

private:
	int studentNumber;
	int subjectNumber;
	string subjects[MAX_SUBJECT_NUMBER];
	void Caution();
	struct _statistics_table {
		int max;
		int min;
		int center;
		double average;
		double deviation;
	} statisticsTable[MAX_SUBJECT_NUMBER];
	struct _achievement_table {
		string name;
		int subjects[MAX_SUBJECT_NUMBER];
	} achievementTable[MAX_STUDENT_NUMBER];
};
#endif // _DEVIATIONCALCULATOR_H_
