#include<iostream>
#include<string>
#include<Windows.h>
#include <conio.h>
#include<ctime>
#include<stack>

using namespace std;



class Figur
{
private:
	

	int X;
	int Y;
	int length;
	int width;
	int collor;
	
public:
	void SetCollor() {
		cout << "Enter Collor" << endl;
		cin >> collor;
	}
	void SetCursor(int x, int y) {
		COORD pos = { x, y };
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(output, pos);
	}
	void Print()
	{
		static const HANDLE consoleWndHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(consoleWndHandle, collor);
		SetCursor(X, Y);
		for (int i = 0; i < length; i++)
		{

			SetCursor(X, Y + i);
			for (int j = 0; j < width; j++)
			{
				cout << char(176);
			}
		}
	}
	void RandomChangeSize()
	{
		int a = 0;
		a = rand() % 5 + 0;
		X = a;
		a = rand() % 5 + 0;
		Y = a;
		a = rand() % 5 + 0;
		length = a;
		a = rand() % 5 + 0;
		width = a;
	
	}
	void RandomMove() {
	
		int a = 0;

		

		int Move;
	
		
			Print();
			Move = _getch();
			if (Move == 56)
			{
				Print();
				MoveUp();
				system("cls");
			}
			if (Move == 50)
			{
				Print();
				MoveDown();
				system("cls");
			}
			if (Move == 52)
			{
				Print();
				MoveLeft();
				system("cls");
			}
			if (Move == 54)
			{
				Print();
				MoveRight();
				system("cls");
			}
			if (Move == 53) {
			Print();
			a = rand() % 5 + 0;
			if (X == 0 || Y == 0 || Y == 10 || X == 10) {
				X = 5;
				Y = 5;
			}
			if (a == 1) {
				X++;
			}
			else if (a == 2) {
				X--;
			}
			else if (a == 3) {
				Y--;
			}
			else if (a == 4) {
				Y++;
			}
			system("cls");
			
		}
	}
	void MoveRight()
	{
		X++;
	}
	void MoveLeft()
	{
		X--;
	}
	void MoveUp()
	{
		Y--;
	}
	void MoveDown()
	{
		Y++;
	}
	
};

//class GameMemento
//{
//private:
//	State _state;
//
//public:
//	GameMemento(State state)
//	{
//		_state = state;
//	}
//
//	State GetState()
//	{
//		return _state;
//	}
//
//};

class State {
private:
	int X;
	int Y;
	int length;
	int width;
	int collor;
public:
	State(int X,int Y,int length,int width,int collor){
		this->X = X;
		this->Y = Y;
		this->length = length;
		this->width = width;
		this->collor = collor;
	}
};

int main()
{
	srand(unsigned(time(NULL)));
	Figur One;
	One.RandomChangeSize();

	One.SetCollor();
	while (true) {
		One.RandomMove();
	}

	return 0;
}