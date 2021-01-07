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
	// 生徒数と科目数を入力。
	dc->InputStudentAndSubjectNumber();
	// 生徒数と科目数を出力。（デバッグ用）
	dc->OutputStudentAndSubjectNumber(); // TODO: 削除する。
	// 科目を科目数分入力。
	dc->InputSubjects();
	// 科目を科目数分出力。（デバッグ用）
	dc->OutputSubjects(); // TODO: 削除する。
	// 成績を生徒数分入力。
	dc->InputAchievement();
	// 成績を生徒数分出力。（デバッグ用）
	dc->OutputAchievement(); // TODO: 削除する。
}

void DeviationCalculator::InputStudentAndSubjectNumber() {
	cout << "人数と科目数の入力。例）3 2" << endl;
	this->Caution();
	cin >> this->studentNumber >> this->subjectNumber;
}
void DeviationCalculator::OutputStudentAndSubjectNumber() {
	cout << "人数：" << this->studentNumber << endl
		<< "科目数：" << this->subjectNumber << endl;
}

void DeviationCalculator::InputSubjects()
{
	cout << "科目を科目数分入力。例）英語 数学" << endl;
	this->Caution();
	for (int i = 0; i < this->subjectNumber; i++) cin >> this->subjects[i];
}

void DeviationCalculator::OutputSubjects()
{
	for (int i = 0; i < this->subjectNumber; i++) cout << this->subjects[i] << endl;
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

void DeviationCalculator::OutputAchievement()
{
	for (int i = 0; i < this->studentNumber; i++) {
		cout << "生徒" << i << "：" << this->achievementTable[i].name << endl;
		for (int j = 0; j < this->subjectNumber; j++)
			cout << "科目" << j << "：" << this->achievementTable[i].subjects[j] << endl;
	}
}

void DeviationCalculator::ShowDeviation(DeviationCalculator *dc)
{
	dc->CalcAvg();
	dc->ShowAvg();

	// TODO: 標準偏差を求め、偏差値を出す。
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
	cout << "注意：半角スペースで区切ってください！" << endl;
}
