#include <iostream>
#include <map>
#include <string>
using namespace std;
class IShape
{
public:
	virtual void Print() = 0;
};
class Rectangle : public IShape
{
public:
	void Print()
	{
		cout << "Printing Rectangle\n";
	}
};
class Circle : public IShape
{
public:
	void Print()
	{
		cout << "Printing Circle\n";
	}
};
enum ShapeType
{
	RECTANGLE,
	CIRCLE
};
class ShapeObjectFactory
{
	map<ShapeType, IShape*> shapes;
public:
	int TotalObjectsCreated()
	{
		return shapes.size();
	}
	IShape * GetShape(ShapeType ShapeName)
	{
		IShape * shape = nullptr;
		if (shapes.find(ShapeName) != shapes.end())
		{
			shape = shapes[ShapeName];
		}
		else
		{
			switch (ShapeName)
			{
			case RECTANGLE:
				shape = new Rectangle();
				shapes[RECTANGLE] = shape;
				break;
			case CIRCLE:
				shape = new Circle();
				shapes[CIRCLE] = shape;
				break;
			default:
				throw new exception("Factory cannot create the object specified");
			}
		}
		return shape;
	}
	// ~Destructor
};
void main()
{
	// Rectangle r1;
	// r1.Print();
	ShapeObjectFactory sof = ShapeObjectFactory();
	IShape * shape = sof.GetShape(RECTANGLE);
	shape->Print();
	shape = sof.GetShape(RECTANGLE);
	shape->Print();
	shape = sof.GetShape(RECTANGLE);
	shape->Print();
	shape = sof.GetShape(CIRCLE);
	shape->Print();
	shape = sof.GetShape(CIRCLE);
	shape->Print();
	shape = sof.GetShape(CIRCLE);
	shape->Print();

	int NumObjs = sof.TotalObjectsCreated();
	cout << "\nTotal No of Objects created = " << NumObjs << endl;
	system("pause");
};
//Collapse



