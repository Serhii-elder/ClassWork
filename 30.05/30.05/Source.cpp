#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Player
{
	string name;
	string surname;
	int age;
	int games;
	int points;
	double avPoint;
};

double AveragePoint(Player &P);

void FillPlayer(Player &P);

void ShowPlayerInfo(const Player &P);

void SaveInFile(Player *&arr, int counter);

void LoadFromFile(Player *&arr, int counter);

void AddPlayer(Player *&arr, int &counter, const Player &P);

void ShowPlayers(const Player *arr, int counter);

int main()
{
	bool exit = false;
	int choise = 0;
	int counter = 0;
	int index = 0;
	string name;
	Player P;

	

	Player *arr = nullptr;

	for (int i = 0; exit == false; i++)
	{
		system("cls");
		cout << "Add player - 1\nShow players - 2\nSave In File  - 3\nLoad From File - 4\nExit - 0" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
			system("cls");
			FillPlayer(P);
			AddPlayer(arr, counter, P);
			system("cls");
			ShowPlayers(arr, counter);
			system("pause");
			system("cls");
			break;
			
		case 2:
			system("cls");
			ShowPlayers(arr, counter);
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			SaveInFile(arr, counter);
			system("cls");
			break;
		case 7:
		
			LoadFromFile(arr, counter);
			cout << ">>>>>>>>>>==========RESULT==========<<<<<<<<<<" << endl;
			ShowPlayers(arr, counter);
			system("pause");
			system("cls");
			break;
		case 0:
			system("cls");
			cout << "Good bye!" << endl << endl;
			exit = true;
			break;
		default:
			cout << "ERROR. Wrong choise, try again" << endl;
			system("cls");
			break;
		}

	}

	system("pause");
	return 0;
}

void AddPlayer(Player *&arr, int &counter, const Player &P)
{
	counter++;
	Player *new_arr = new Player[counter];

	for (int i = 0; i < (counter - 1); i++)
	{
		new_arr[i] = arr[i];
	}
	new_arr[counter - 1] = P;

	delete[] arr;
	arr = new_arr;
}

double AveragePoint(Player &P)
{
	return (double)P.games / P.points;
}

void FillPlayer(Player &P)
{
	cout << "Write name: " << endl;
	cin >> P.name;
	cout << "Write surname: " << endl;
	cin >> P.surname;
	cout << "Write age: " << endl;
	cin >> P.age;
	cout << "Write quantity of games: " << endl;
	cin >> P.games;
	cout << "Write points: " << endl;
	cin >> P.points;
	P.avPoint = AveragePoint(P);
}

void ShowPlayerInfo(const Player &P)
{
	cout << "\nName: " << P.name << endl;
	cout << "Surname: " << P.surname << endl;
	cout << "Age: " << P.age << endl;
	cout << "Games: " << P.games << endl;
	cout << "Points: " << P.points << endl;
	cout << "Average point: " << P.avPoint << endl << endl;
}

void ShowPlayers(const Player *arr, int counter)
{
	for (int i = 0; i < counter; i++)
	{
		cout << "============================" << i << "============================" << endl;
		ShowPlayerInfo(arr[i]);
	}
}

void SaveInFile(Player *&arr, int counter)
{
	ofstream out("Players.txt", ios_base::app);

	for (int i = 0; i < counter; i++)
	{
		out << arr[i].name << endl;
		out << arr[i].surname << endl;
		out << arr[i].age << endl;
		out << arr[i].games << endl;
		out << arr[i].points << endl;
		out << arr[i].avPoint << endl;
	}
	out.close();
	cout << "Done!" << endl;
}

void LoadFromFile(Player *&arr, int counter)
{
	Player *new_arr = new Player[counter];

	ifstream in("Players.txt", ios_base::in);
	for (int i = 0; i < counter; i++)
	{
		in >> new_arr[i].name;
		in >> new_arr[i].surname;
		in >> new_arr[i].age;
		in >> new_arr[i].games;
		in >> new_arr[i].points;
		in >> new_arr[i].avPoint;
	}
	in.close();
	delete[] arr;
	arr = new_arr;
	cout << "Done!" << endl;
}
