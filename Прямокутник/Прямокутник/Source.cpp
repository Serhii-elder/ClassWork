#include<iostream>
#include<string>
#include<Windows.h>
#include <conio.h>

using namespace std;

class Rectangl
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
				cout << char(219);
			}
		}
	}

	void Fill()
	{
		cout << "X: "; cin >> X;
		cout << "Y: "; cin >> Y;
		cout << "Length: "; cin >> length;
		cout << "Width"; cin >> width;
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

int main()
{
	Rectangl One;

	One.Fill();

	One.SetCollor();


	int Move;
	while (true)
	{
		One.Print();

		Move = _getch();
		if (Move == 72)
		{
			One.MoveUp();
		}
		if (Move == 80)
		{
			One.MoveDown();
		}
		if (Move == 75)
		{
			One.MoveLeft();
		}
		if (Move == 77)
		{
			One.MoveRight();
		}
		system("cls");
	}


	return 0;
}