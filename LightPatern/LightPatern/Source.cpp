#include <iostream>
#include <map>
#include <string>
#include<list>

using namespace std;

class Unit
{
public:
	int AttacPoint;
	int DefencePoint;
	int HealPoint;
	virtual void Display() = 0;
};
class Tank : public Unit
{
public:
	Tank()
	{
		AttacPoint = 40;
		DefencePoint = 15;
		HealPoint = 100;
	}
	void Display()
	{
		cout << "I am tank\n";
	}
};
class Motor : public Unit
{
public:
	Motor()
	{
		AttacPoint = 20;
		DefencePoint = 8;
		HealPoint = 40;
	}
	
	void Display()
	{
		cout << "I am motor\n";
	}
};
class Human : public Unit {
public:
	Human()
	{
		AttacPoint = 10;
		DefencePoint = 5;
		HealPoint = 20;
	}
	void Display()
	{
		cout << "I am human\n";
	}
};
enum ShapeType
{
	TANK,
	MOTOR,
	HUMAN

};



class ShapeObjectFactory
{
	map<ShapeType, Unit*> shapes;
public:
	int TotalObjectsCreated()
	{
		return shapes.size();
	}
	Unit * GetShape(ShapeType ShapeName)
	{
		Unit * shape = nullptr;
		if (shapes.find(ShapeName) != shapes.end())
		{
			shape = shapes[ShapeName];
		}
		else
		{
			switch (ShapeName)
			{
			case TANK:
				shape = new Tank();
				shapes[TANK] = shape;
				break;
			case MOTOR:
				shape = new Motor();
				shapes[MOTOR] = shape;
				break;
			case HUMAN:
				shape = new Human();
				shapes[HUMAN] = shape;
				break;
			default:
				throw new exception("Factory cannot create the object specified");
			}
		}
		return shape;
	}
	~ShapeObjectFactory() {
		cout << "sess" << endl;
		system("pause");
	 }
};






void main()
{
	// Rectangle r1;
	// r1.Print();
	ShapeObjectFactory sof = ShapeObjectFactory();
	Unit * shape = sof.GetShape(TANK);
	shape->Display();
	shape = sof.GetShape(TANK);
	shape->Display();
	shape = sof.GetShape(TANK);
	shape->Display();
	shape = sof.GetShape(MOTOR);
	shape->Display();
	shape = sof.GetShape(MOTOR);
	shape->Display();
	shape = sof.GetShape(MOTOR);
	shape->Display();
	shape = sof.GetShape(HUMAN);
	shape->Display();
	shape = sof.GetShape(HUMAN);
	shape->Display();

	int NumObjs = sof.TotalObjectsCreated();
	cout << "\nTotal Unit created = " << NumObjs << endl;
	system("pause");
};
//Collapse



