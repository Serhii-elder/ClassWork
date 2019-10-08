#include <iostream>
using namespace std;

class MyClass
{
	int * pointer;

public:
	MyClass() { pointer = nullptr; }
	MyClass(int val)
	{
		cout << "MyClass!\n";
		pointer = new int(val);
	}
	MyClass(const MyClass& other)
	{
		if (other.pointer == nullptr)
			pointer = nullptr;
		else
		{
			cout << "MyClassOther!\n";
			pointer = new int(*other.pointer);
		}
	}

	MyClass(MyClass&& other)
	{
		this->pointer = other.pointer;
		other.pointer = nullptr;
	}

	~MyClass()
	{
		if (pointer != nullptr)
		{
			cout << "Delete resources!\n";
			delete pointer;
		}
	}

	void SetValue(int val)
	{
		if (pointer == nullptr)
		{
			cout << "Set Value!\n";
			pointer = new int;
		}

		*pointer = val;
	}

	MyClass& operator=(const MyClass& other)
	{
		if (this == &other)
			return *this;

		if (other.pointer == nullptr)
			this->pointer = nullptr;
		else
			SetValue(*other.pointer);

		return *this;
	}

	MyClass& operator=(MyClass&& other)
	{
		if (this == &other)
			return *this;

		if (other.pointer == nullptr)
			this->pointer = nullptr;
		else
		{
			this->pointer = other.pointer;
			other.pointer = nullptr;
		}

		return *this;
	}

	int GetValue() const { return *pointer; }
};

MyClass CreateMyClass()
{
	MyClass value(45);
	return value;
}

void main()
{
	MyClass myClass;
	myClass = CreateMyClass();

	cout << myClass.GetValue() << endl;

	/*int x;
	x = 7;
	x = (1 + 1);
	int && refToRValue = (1 + 1);*/

	system("pause");
}