#pragma once
#pragma once
#include<string>

using namespace std;

class Student
{
private:
	string name;
	string surname;
	int age;
	int birDate;
	double rating;
	string addres;

	void calcAge();

public:

	Student();
	Student(string newName, string newSurname, int newDate, double newRatind, string newAddres);

	void Show() const;

	void Fill();

	double GetRating();


};