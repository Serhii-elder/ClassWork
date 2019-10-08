#include<iostream>
#include<fstream>
#include<ctime>
#include<Windows.h>

using namespace std;

class ICalcul {
	
public:
	virtual float Add(float a, float b) = 0;
		
	virtual float Sub(float a, float b) = 0;
		
	virtual float Div(float a, float b) = 0;
	
	virtual float Mult(float a, float b) = 0;

};

class Call : public ICalcul {
	
public:
	virtual float Add(float a, float b) {
		return a + b;
	}
	virtual float Sub(float a, float b) {
		
		return a - b;
	}
	virtual float Div(float a, float b) {
		return a * b;
	}
	virtual float Mult(float a, float b) {
		return a / b;
	}

};

class CallProxy : public ICalcul{

	Call * m;

	CallProxy() {
		m = nullptr;
	}

	~CallProxy() {
		delete m;
	}
	virtual float Div(float a, float b) {
		// log
		return m->Div(a, b);
	}
};


void main() {

	CallProxy p();
	int result = 0;
	int choice = 0;
	bool exit = true;


	while (exit) {
		cout << "1.Add 2.Sub 3.Div 4.Mult 0.Exit" << endl;
		cin >> choice;
		if (choice == 1) {
			result = p.Add(10, 20);
			cout << result << endl;
		}if (choice == 2) {
			result = p.Sub(10, 20);
			cout << result << endl;
		}if (choice == 3) {
			result = p.Div(10, 20);
			cout << result << endl;
		}if (choice == 4) {
			result = p.Mult(10, 20);
			cout << result << endl;
		}if (choice == 0) {
			exit = false;
		}
	}
}