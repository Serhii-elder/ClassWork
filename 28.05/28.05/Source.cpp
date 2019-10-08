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

void LoadFromFile(Player p)
{
	ifstream in("Players.txt", ios_base::app);

	in >> p.name;
	in >> p.surname;
	in >> p.age;
	in >> p.games;
	in >> p.points;
	in >> p.avgPointPerGame;

	in.close();
}

void LoadSize(int size)
{
	ifstream in("Size.txt");

	in >> size;

}

void showPlayers(const Player * arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		showPlayer(arr[i]);
		cout << "-------------------------------------\n";
	}
}
void loadArr(const Player *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		LoadFromFile(arr[i]);
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
void SaveSize(int size)
{
	ofstream out("Size.txt");

	out << size << endl;

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
	LoadSize(size);
	Player * arr = nullptr;
	bool exit = true;
	int choice = 0;

	while (exit == true) {
		cout << "1. AddPlayer 2.ShowPlayer 0. Exit: ";
		cin >> choice;
		if (choice == 1) {
			Player p = CreatePlayer();
			Add(arr, size, p);
			SaveInFile(p);
		}
		else if (choice == 2) {

			loadArr(arr, size);
			showPlayers(arr, size);
		}

		else if (choice == 0) {

			exit = false;
		}
		else
			cout << "Error!" << endl;

	}
	SaveSize(size);
	system("pause");

	return 0;
}