#include "Test.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;


int Test::authorization(Test *&arr, Test &P)
{

	asize = Loadasize();

	Test *new_arr = new Test[asize];

	ifstream in("Logandpass.txt", ios_base::in);
	for (int i = 0; i < asize; i++) {
		in >> new_arr[i].index;
		in >> new_arr[i].login;
		in >> new_arr[i].password;
		in >> new_arr[i].name;

		if (P.login == new_arr[i].login && new_arr[i].password == P.password) {
			cout << "Hello " << new_arr[i].name << endl;
			P.index = new_arr[i].index;
			P.login = new_arr[i].login;
			P.password = new_arr[i].password;
			P.name = new_arr[i].name;
			delete[] arr;
			arr = new_arr;
			return 1;
		}

	}
	in.close();

	return 0;
}

void Test::test(Test &P)
{
	int number = 0;
	float points = 0;
	system("cls");
	cout << "2 + 2= ";
	cin >> number;
	if (number == 4) {
		points += 10;
	}
	system("cls");
	cout << "7 * 8= ";
	cin >> number;
	if (number == 49) {
		points += 10;
	}
	system("cls");
	cout << "122 - 80 = ";
	cin >> number;
	if (number == 42) {
		points += 10;
	}
	system("cls");
	cout << "60 / 3 = ";
	cin >> number;
	if (number == 20) {
		points += 10;
	}
	system("cls");
	cout << "49 / 7= ";
	cin >> number;
	if (number == 7) {
		points += 10;
	}
	system("cls");
	cout << "6 * 3 = ";
	cin >> number;
	if (number == 18) {
		points += 10;
	}
	system("cls");
	cout << "2x - 2 = 10\nx = ";
	cin >> number;
	if (number == 6) {
		points += 10;
	}
	system("cls");
	cout << "33 - x = 20\nx = ";
	cin >> number;
	if (number == 13) {
		points += 10;
	}
	system("cls");
	cout << "36 - (10 + x) = 14";
	cin >> number;
	if (number == 12) {
		points += 10;
	}
	system("cls");
	cout << "1 + 1= ";
	cin >> number;
	if (number == 2) {
		points += 10;
	}

	ofstream out("Point.txt", ios_base::app);
	out << P.index << " " << points;
	out.close();

}

void Test::myavgpoints(string login, string password)
{
	float points = 0;

	asize = Loadasize();

	Test *new_arr = new Test[asize];

	ifstream in("Logandpass.txt", ios_base::in);
	for (int i = 0; i < asize; i++) {
		in >> new_arr[i].index;
		in >> new_arr[i].login;
		in >> new_arr[i].password;
		in >> new_arr[i].name;

		if (login == new_arr[i].login && new_arr[i].password == password) {
			index = new_arr[i].index;

			points = loadpoints(index);
		}
	}
	cout << "Your avg points: " << points<<endl;
	in.close();
	delete[] arr;
	arr = new_arr;
}


void Test::Registration(const Test &P)
{
	asize = Loadasize();

	string pass;
	string log;

	ifstream in("Logandpass.txt", ios_base::in);
	for (int i = 0; i < asize; i++) {
		in >> index;
		in >> log;
		in >> pass;
		in >> name;
		if (P.login == log || pass == P.password) {
			cout << "Such login or password already exists\n";
			return;
		}
	}
	in.close();
	cout << "Enter your name: ";
	cin >> name;
	ofstream out("Logandpass.txt", ios_base::app);
	index = asize;
	out << index << " " << P.login << " " << P.password << " " << name << endl;

	out.close();
	asize++;

	Saveasize();
}

void Test::Saveasize() {
	ofstream out("asize.txt", ios_base::out);
	out << asize;
	out.close();
}

int Test::Loadasize()
{
	ifstream in("asize.txt", ios_base::in);
	in >> asize;
	in.close();
	return asize;
}

int Test::loadpoints(int index)
{
	float points;
	int index1;
	ifstream in("Point.txt", ios_base::in);
	in >> index1 >> points;
	if (index1 == index)
		return points;
	in.close();
}

int Test::loadindex(string login, string password)
{
	return 0;
}

void Test::loadlogandpass(Test *&arr, string login, string password)
{
	asize = Loadasize();

	Test *new_arr = new Test[asize];

	ifstream in("Logandpass.txt", ios_base::in);
	for (int i = 0; i < asize; i++) {
		in >> new_arr[i].index;
		in >> new_arr[i].login;
		in >> new_arr[i].password;
		in >> new_arr[i].name;

		if (login == new_arr[i].login && new_arr[i].password == password) {
			delete[] arr;
			arr = new_arr;
		}

	}
	in.close();
}
void Test::fillakk(Test & P)
{
	cout << "Enter login: ";
	cin >> P.login;
	cout << "Enter password: ";
	cin >> P.password;
}