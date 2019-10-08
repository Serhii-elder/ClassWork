#pragma once
#pragma once
#include<string>
#include"Student.h"

using namespace std;

class Group
{
private:

	Student *arr = nullptr;
	double avgMark;
	string nameGroup;
	int count;


	void CalcAvgMark();

public:
	Group() {};
	~Group() {};

	void ShowGroup();
	void AddStudent(Student A);
	const Group GetBestGroup(const Group & group) const;
};