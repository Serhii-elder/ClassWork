#pragma once
#include<iostream>
#include<string>
using namespace std;

class Test {
private:
	string password;
	string login;
	string name;
	int index;
	int asize;

	Test *arr = nullptr;



public:

	int authorization(Test *&arr, Test &P);

	void test(Test &P);

	void myavgpoints(string login, string password);

	void Registration(const Test &P);

	void Saveasize();

	int Loadasize();

	int loadpoints(int index);

	int loadindex(string login, string password);

	void loadlogandpass(Test *&arr, string login, string password);

	void fillakk(Test &P);

};
