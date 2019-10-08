
#include <iostream>
#include "Student.h"
#include <string>


using namespace std;

Student::Student(string newName ,  int newYear,string newAdress,double newMark) {
	name = newName;
	age = 0;
	yearbirthday = newYear;
	adress = newAdress;
	mark = newMark;
	CalcAge();
}

Student::Student() {
	name = "no name";
	age = 0;
	yearbirthday = 0;
	adress = "no addres";
	mark = 0;
}



void Student::CalcAge() {
	age = 2019 - yearbirthday;
}

void Student::Show() {
	system("cls");
	cout << "\n\tEnter name: "<<name<<endl;
	cout << "\n\tEnter age: "<<age<<endl;
	cout << "\n\tEnter YearBirthd: "<<yearbirthday<<endl;
	cout << "\n\tEnter adress: "<<adress<<endl;
	cout << "\n\tEnter mark: "<<mark<<endl;

}

void Student::Fill() {

	cout << "\n\tEnter name: "; cin >> name;
	//cout << "\n\tEnter age: "; cin >> age;
	cout << "\n\tEnter YearBirthd: "; cin >> yearbirthday;
	cout << "\n\tEnter adress: "; cin >> adress;
	cout << "\n\tEnter mark: "; cin >> mark;
	CalcAge();
}



