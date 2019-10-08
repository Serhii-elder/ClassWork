#pragma once
#include<iostream>
#include<string>
using namespace std;


class Animal {
private:
	string type;
	string place;
	int speed;
public:

	Animal()
		: type("No type"),place("No place"), speed(0){}

	Animal(string type,string place,int speed)
		: type(type),place(place), speed(speed){}

	
	void Say() {


	}

	void Move() {

		
	}

	void Show() {



	}
};

class Bird {

	int flyHeigth;






};