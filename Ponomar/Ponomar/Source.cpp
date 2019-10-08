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
void DeletePlayer(Player *&arr, int &counter, int index);
int Find(Player *&arr, string name, int &counter);
//void LoadFromFileBinary(const Player &P);
//void SaveInFileBinary(const Player &P);
//void QuantityOfStructure();
int CounterOfPlayers();

int main()
{
	bool exit = false;
	int choise = 0;
	int counter = 0;
	int index = 0;
	string name;
	Player P;

	//Player P;
	//FillPlayer(P);
	//ShowPlayerInfo(P);
	//SaveInFile(P);
	//LoadFromFile(P);
	//ShowPlayerInfo(P);

	Player *arr = nullptr;

	for (int i = 0; exit == false; i++)
	{
		system("cls");
		cout << "Add player - 1\nDelete player - 2\nFind player - 3\nSort players - 4\nShow info about players - 5\nSave All Players - 6\nLoad All Players - 7\nClear the screen - 9\nExit - 0" << endl;
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

			if (counter < 1)
			{
				system("cls");
				cout << "You haven't a players!" << endl;
				system("pause");
				system("cls");
				break;
			}

			cout << "Write index of a player, what you want to delete" << endl;
			cin >> index;
			if (index >= counter)
			{
				cout << "Incorrect index!" << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				DeletePlayer(arr, counter, index);
				cout << ">>>>>>>>>>==========RESULT==========<<<<<<<<<<" << endl;
				ShowPlayers(arr, counter);
				system("pause");
				system("cls");
				break;
			}
		case 3:
			system("cls");

			cout << "Write a name of player what you want to find" << endl;
			cin >> name;
			index = Find(arr, name, counter);
			if (index == -1)
			{
				cout << "Can not find a name!" << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				cout << "Info about player: " << endl;
				ShowPlayerInfo(arr[index]);
				system("pause");
				system("cls");
				break;
			}
		case 4:
			system("cls");
			cout << "Not working option" << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			ShowPlayers(arr, counter);
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			SaveInFile(arr, counter);
			system("cls");
			break;
		case 7:
			counter = CounterOfPlayers();
			LoadFromFile(arr, counter);
			cout << ">>>>>>>>>>==========RESULT==========<<<<<<<<<<" << endl;
			ShowPlayers(arr, counter);
			system("pause");
			system("cls");
			break;
		case 9:
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

void DeletePlayer(Player *&arr, int &counter, int index)
{
	counter--;
	Player *new_arr = new Player[counter];


	for (int i = 0; i < counter; i++)
	{
		if (i < index)
		{
			new_arr[i] = arr[i];
		}
		else if (i >= index)
		{
			cout << "Test" << endl;
			new_arr[i] = arr[i + 1];
		}
	}

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
	ofstream out("Players.txt", ios_base::out);

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

void LoadFromFileBinary(const Player &P)
{
	cout << "Loading....." << endl;
	ifstream in("playerBin.txt", ios_base::in | ios_base::binary);
	in.read((char*)&P, sizeof(P));
	in.close();
}

void SaveInFileBinary(const Player &P)
{
	ofstream out("playerBin.txt", ios_base::out | ios_base::binary);
	out.write((char*)&P, sizeof(P));
	out.close();
}

int Find(Player *&arr, string name, int &counter)
{

	for (int i = 0; i < counter; i++)
	{
		if (arr[i].name.find(name) != string::npos)
			return i;
	}
	return -1;
}

int CounterOfPlayers()
{
	ifstream readFile;
	int counter = 0;
	readFile.open("Players.txt");
	string data;
	while (!readFile.eof())
	{
		getline(readFile, data);
		counter++;
	}
	return counter / 6;
}