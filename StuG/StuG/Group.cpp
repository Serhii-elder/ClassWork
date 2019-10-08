#include "Group.h"
#include"Student.h"
void Group::CalcAvgMark()
{
	double sum = 0;

	for (int i = 0; i < count; i++)
	{
		sum = sum + arr[i].GetRating();
	}
	avgMark = sum / count;

}

void Group::ShowGroup()
{
	for (int i = 0; i < count; i++)
	{
		arr[i].Show();
	}
}

void Group::AddStudent(Student A)
{
	Student *newArr = new Student[count + 1];

	for (int i = 0; i < count; i++)
	{
		newArr[i] = arr[i];
	}

	newArr[count] = A;
	delete[]arr;
	arr = newArr;
	++count;
	CalcAvgMark();
}

const Group Group::GetBestGroup(const Group & group) const
{
	if (this->avgMark > group.avgMark)
	{
		return *this;
	}
	else
	{
		return group;
	}
}