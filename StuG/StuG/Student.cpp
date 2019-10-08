#include "Student.h"
#include<iostream>
using namespace std;

void Student::calcAge()
{
	age = 2019 - birDate;
}

Student::Student()
{
	name = "No name";
	surname = "No surname";
	age = 0;
	birDate = 0;
	rating = 0;
	addres = "No addres";
}

Student::Student(string newName, string newSurname, int newDate, double newRatind, string newAddres)
{
	name = newName;
	surname = newSurname;
	age = 0;
	rating = newRatind;
	birDate = newDate;
	addres = newAddres;

	calcAge();
}

void Student::Show() const
{
	cout << "Name: " << name << endl
		<< "Surname: " << surname << endl
		<< "Age: " << age << endl
		<< "Rating: " << rating << endl
		<< "Addres: " << addres << endl;
}

void Student::Fill()
{
	cout << "Enter name: "; cin >> name;
	cout << "Enter surname: "; cin >> surname;
	cout << "Enter year of birth: "; cin >> birDate;
	cout << "Enter rating: "; cin >> rating;
	cout << "Enter addres: "; cin >> addres;

	calcAge();
}

double Student::GetRating()
{
	return rating;
}