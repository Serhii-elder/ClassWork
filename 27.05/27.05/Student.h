#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int CURRENT_YEAR = 2016;

class Student
{
private:
	string name;
	string surname;
	int age;
	bool isDayForm;
	bool isValidAge(int);
	bool isValidName(string);

public:
	Student() 
	{ 
		cout << "I`m constructor from: ";
		cout << endl;
	}
	Student(string, string, int, bool);

	~Student() { 
		cout << "I`m destructor from: "; 
		cout << name << endl;
	}

	void setAge(int);
	void setDayForm(bool);
	void setName(string);
	void setSurname(string);
	void setAll(string, string, int, bool);

	string getName() const;
	string getSurname() const;
	int getAge() const;
	bool getDayForm() const;

	void showStudent() const;

	const Student& getOlderStudent(const Student&) const;
};
