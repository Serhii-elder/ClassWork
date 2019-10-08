#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Player {

	string name;
	string surname;
	int age;
	int games;
	int points;
	double avgPointPerGame;
};

void showPlayer(const Player & Players) {

	cout << "Name:" << Players.name << endl
		<< "Surname:" << Players.surname << endl;
	cout << "Age:" << Players.age << endl;
	cout << "Games:" << Players.games << endl;
	cout << "Points:" << Players.points << endl;
	cout << "AvgPointPerGame:" << Players.avgPointPerGame << endl;
}
void showPlayers(const Player * arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		showPlayer(arr[i]);
		cout << "-------------------------------------\n";
	}
}
double AveragePoint(const Player& p)
{
	return (double)p.games / p.points;
}

Player CreatePlayer()
{
	Player p;
	cout << "Please enter name:" << endl;
	cin >> p.name;

	cout << "Please enter surname:" << endl;
	cin >> p.surname;

	cout << "Please enter age:" << endl;
	cin >> p.age;

	cout << "Please enter games:" << endl;
	cin >> p.games;

	cout << "Please enter points:" << endl;
	cin >> p.points;

	p.avgPointPerGame = AveragePoint(p); // обчислення середньої кількості

	return p;
}


void SaveInFile(const Player & player)
{
	ofstream out("Players.txt", ios_base::app);

	out << player.name << endl;
	out << player.surname << endl;
	out << player.age << endl;
	out << player.games << endl;
	out << player.points << endl;
	out << player.avgPointPerGame << endl;

	out.close();
}

void LoadFromFile( Player * arr , int size)
{
	ifstream in("Players.txt", ios_base::in);

	for (int i = 0; i < 1; i++)
	{
		in >> arr[i].name;
		in >> arr[i].surname;
		in >> arr[i].age;
		in >> arr[i].games;
		in >> arr[i].points;
		in >> arr[i].avgPointPerGame;

		in.close();
	}
}

void Add(Player * &arr, int &size, const Player& newPlayer)
{
	Player* newArr = new Player[size + 1];

	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	newArr[size] = newPlayer; // add new player

	//delete[] arr;
	arr = newArr;
	++size;
}



int main()
{
	int size = 0;
	Player * arr = nullptr;
	bool exit = true;
	int choice = 0;
			Player p;

	while (exit == true) {
		cout << "1. AddPlayer 2.ShowPlayer 0. Exit: ";
		cin >> choice;
		if (choice == 1) {
			Player p = CreatePlayer();
			Add(arr, size, p);
			SaveInFile(p);
		}
		else if (choice == 2) {
			LoadFromFile(arr, size);
			showPlayers(arr, size);
		}

		else if (choice == 0) {
			exit = false;
		}
		else
			cout << "Error!" << endl;

	}
	system("pause");

	return 0;
}