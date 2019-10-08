#pragma once
#include <iostream>
#include <string>


using namespace std;

class Student{
private:
	string name;
	int age;
	int yearbirthday;
	string adress;
	double mark;
	
	void CalcAge();
public:

	Student();
	Student(string newName, int newYear, string newAdress,double mark);
	
	void Fill();

	void Show();
	
};



