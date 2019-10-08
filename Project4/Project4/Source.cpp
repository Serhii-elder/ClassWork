#include "Car.h"
#include<iostream>
#include<fstream>
using namespace std;

ostream& operator<<(ostream& os, const Car& my)
{
	os.write((char*)&my, sizeof(my));
	return os;
}
// file.opeartor<<(obj).operator<<(obj2).operator<<(obj3);

istream& operator>>(istream& is, const Car& my)
{
	is.read((char*)&my, sizeof(my));
	return is;
}

int main() {


	Car car(1,"sdsdsd",2,3,"asd",4,9);
	Car car1;
	//car.show();
	
	

	ofstream ofile;
	ofile.open("MyClass.txt", ios_base::out | ios_base::binary);
	if (!ofile.is_open())
	{
		cerr << "File could`n open.";
		exit(1);
	}

	car.show();
	ofile << car;
	ofile.close();
	cout << "=============================" << endl;
	ifstream ifile;
	ifile.open("MyClass.txt", ios_base::in | ios_base::binary);

	if (!ifile.is_open())
	{
		cerr << "File could`n open.";
		exit(1);
	}
	ifile >> car1;
	car1.show();

	ifile.close();


	system("pause");
	return 0;
}