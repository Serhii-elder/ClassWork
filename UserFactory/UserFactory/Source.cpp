// Factory Method Classic
#include <iostream>
#include <vector>

using namespace std;

// Иерархия классов игровых персонажей
class Warrior
{
public:
	virtual void info() = 0;
	virtual ~Warrior() {}
};

class Infantryman : public Warrior
{
public:
	void info() {
		cout << "Infantryman" << endl;
	};
};

class Archer : public Warrior
{
public:
	void info() {
		cout << "Archer" << endl;
	};
};

class Horseman : public Warrior
{
public:
	void info() {
		cout << "Horseman" << endl;
	};
};


// Фабрики объектов
class Factory
{
public:
	virtual Warrior* createWarrior() = 0;
	virtual ~Factory() {}
};

class InfantryFactory : public Factory
{
public:
	Warrior* createWarrior() {
		return new Infantryman;
	}
};

class ArchersFactory : public Factory
{
public:
	Warrior* createWarrior() {
		return new Archer;
	}
};

class CavalryFactory : public Factory
{
public:
	Warrior* createWarrior() {
		return new Horseman;
	}
};


// Создание объектов при помощи фабрик объектов
int main()
{
	Factory* factories[3] =
	{
		new InfantryFactory(),
		new ArchersFactory(),
		new CavalryFactory()
	};

	vector<Warrior*> v;
	v.push_back(factories[0]->createWarrior());
	v.push_back(factories[1]->createWarrior());
	v.push_back(factories[2]->createWarrior());

	for (int i = 0; i < v.size(); i++)
		v[i]->info();


	system("pause");
}




