#include <string>
#include <iostream>
using namespace std;
class Toy
{
protected:
	string name;
public:
	Toy(string _name)
	{
		name = _name;
	}
	virtual void ShowInfo() const
	{
		cout << "I`m a toy, name: " << name << endl;
	}
};

class Kat : public Toy
{
public:
	Kat(string name) : Toy(name)
	{}
	virtual void ShowInfo() const
	{
		cout << "I`m a kat, name: " << name << endl;
	}
};
class Bear : public Toy
{
public:
	Bear(string name) : Toy(name)
	{}
	virtual void ShowInfo() const
	{
		cout << "I`m a bear, name: " << name << endl;
	}
};

class TeddyBear : public Bear
{
public:
	TeddyBear() : Bear("TED")
	{}
	virtual void ShowInfo() const
	{
		cout << "I`m a teddy bear, name: " << name << endl;
	}
};

class TeddyKat : public Kat
{
public:

	TeddyKat() : Kat("TOM")
	{}
	virtual void ShowInfo() const
	{
		cout << "I`m a teddy kat, name: " << name << endl;
	}
};

class WoodenBear : public Bear
{
public:

	WoodenBear() : Bear("GRIZLI")
	{}
	virtual void ShowInfo() const
	{
		cout << "I`m a wooden bear, name: " << name << endl;
	}
};

class WoodenKat : public Kat
{
public:

	WoodenKat() : Kat("MURKAS")
	{}
	virtual void ShowInfo() const
	{
		cout << "I`m a wooden kat, name: " << name << endl;
	}
};

class IToyFactory
{
public:
	virtual Bear* GetBear() = 0;
	virtual Kat* GetKat() = 0;
};

class TeddyToyFactory : public IToyFactory
{
public:

	Bear* GetBear()
	{
		return new TeddyBear();
	}
	Kat* GetKat()
	{
		return new TeddyKat();
	}
};

class WoodenToyFactory : public IToyFactory
{
public:

	Bear* GetBear()
	{
		return new WoodenBear();
	}
	Kat* GetKat()
	{
		return new WoodenKat();
	}
};

void main()
{
	IToyFactory* factory = new WoodenToyFactory();

	Bear *bear = factory->GetBear();
	Kat* kat = factory->GetKat();

	bear->ShowInfo();
	kat->ShowInfo();

	system("pause");
}