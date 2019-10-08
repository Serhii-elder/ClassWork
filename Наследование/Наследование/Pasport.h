#pragma once
#include<iostream>
#include<string>

using namespace std;

class PassportCitizenOfUkraine {

private:
	string name;
	string surname;
	string numberPasport;
	short age;
public:

	PassportCitizenOfUkraine()
		: name("No name"), surname("No surname"), numberPasport("123456789890"), age(0) {}

	PassportCitizenOfUkraine(string name, string surname, string numberPasport, short age)
		: name(name), surname(surname), age(age), numberPasport(numberPasport) {}

	void show() const {

		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
		cout << "numberPasport: " << numberPasport << endl;
		cout << "Age: " << age << endl;
	}
};

class OverseasPassport : public PassportCitizenOfUkraine {

private:

	int visa;
	string number;

public:

	OverseasPassport(string number, int visa, string name, string surname, string numberPassport, short age)
		: visa(visa), number(number), PassportCitizenOfUkraine(name, surname, numberPassport, age) {}

	void Show() const
	{
		cout << "Visa: " << visa << endl;
		cout << "NumberVisa: " << number << endl;
		PassportCitizenOfUkraine::show();
	}
};
