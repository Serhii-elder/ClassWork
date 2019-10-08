#pragma once
#include<iostream>
#include<string>
using namespace std;

class Wheel {

	float wheeld;
	string type;

	

	
public:
	  
	Wheel() : wheeld(0), type("General") {}

	Wheel(float wheeld, string type) {
		this->wheeld = wheeld;
		this->type = type;
	}
	void show() {
		cout << "Diameter of wheels: " << wheeld << endl;
		cout << "Type fo wheels: " << type << endl;
	}
};

class Body {

	string color;
	float length;
	float width;

	
public:

	Body() : color("General"), length(0), width(0) {}

	Body(string color, float lenght, float width) {
		this->color = color;
		this->width = width;
		this->length = lenght;
	}
	void show() {
		cout <<"Color of car: "<< color << endl;
		cout << "Length of car: " << length << endl;
		cout << "width of car: " << width << endl;
	}
};


class Engine {

	float power;
	double avrRevPerMin;

	 
public:
	 Engine() : power(0), avrRevPerMin(0) {}

	 Engine(float power,double avrRevPerMin) {
		 this->power = power;
		 this->avrRevPerMin = avrRevPerMin;

	 }
	 void show() {
		 cout <<"Power of engine : "<< power <<endl;
		 cout <<"Avarage revolutions per minute: "<< avrRevPerMin<<endl;
	 }
};

class Car : public Wheel,public Body , public Engine {
	
public:

	int wheels = 4;

	
	Car(int wheeld,string type, float power,double avrRevPerMin, string color,float length,float width)
		: Wheel(wheeld,type),Engine(power, avrRevPerMin),Body(color,length,width){}
	
	Car()
	{}

	void show() {
		Wheel::show();
		Engine::show();
		Body::show();
	}

	
};


//#include <iostream>
//#include <string>
//using namespace std;
//
//class Citizen
//{
//protected:
//	string country;
//public:
//	Citizen() : country("")
//	{
//		cout << "Ctor Citizen\n";
//	}
//
//	Citizen(string c) : country(c)
//	{
//		cout << "Ctor Citizen\n";
//	}
//
//	string GetCountry() const
//	{
//		return country;
//	}
//};
//
//class Person
//{
//private:
//	bool isMale;
//	string name;
//	short age;
//
//public:
//
//	Person()
//		: name("No name"), age(0), isMale(NULL)
//	{
//		cout << "Ctor Person\n";
//	}
//
//	Person(string name, bool isMale, short age)
//		: name(name), age(age), isMale(isMale)
//	{
//		cout << "Ctor Person\n";
//	}
//
//	void ShowPerson() const
//	{
//		cout << "Name: " << name << endl;
//		cout << "Gender: " << (isMale ? "Male" : "Female") << endl;
//		cout << "Age: " << age << endl;
//	}
//
//
//};
//
//
//class Policeman : public Citizen, public Person
//{
//	string rang;
//
//public:
//	Policeman(string rang, string name, bool isMale, short age, string c)
//		: rang(rang), Person(name, isMale, age), Citizen(c)
//	{
//		cout << "Ctor Policeman\n";
//	}
//
//	void Show() const
//	{
//		Person::ShowPerson();
//
//		cout << "Rang: " << rang << endl;
//		cout << "Country: " << GetCountry() << endl;
//	}
//
//	void Work()
//	{
//		cout << "Policeman do somthing.\n";
//
//	}
//};
//
//class Doctor : public Person
//{
//protected:
//	string specialization;
//public:
//	Doctor() : specialization(""), Person("Vitia", true, 25)
//	{
//
//	}
//
//	Doctor(string spec) : specialization(spec), Person("Vitia", true, 25)
//	{ }
//};
//
//class Spiderman : public Doctor, public Policeman
//{
//	int flyHeight;
//public:
//	Spiderman(string rang, string name, bool isMale, short age, string c, string spec)
//		: Policeman(rang, name, isMale, age, c), Doctor(spec)
//	{ }
//
//	void Show()
//	{
//		Doctor::ShowPerson();
//		Policeman::ShowPerson();
//		cout << "Specialization: " << specialization << endl;
//	}
//};
//
//void main()
//{
//	//Policeman p = Policeman("Major", "Kostia", true, 33, "Ukraine");
//	//p.Show();
//
//	Spiderman sp("Major", "Kostia", true, 33, "Ukraine", "Lor");
//	sp.Show();
//
//	system("pause");
//}