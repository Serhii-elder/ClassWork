#include<iostream>

#include<string>

using namespace std;

class Laptop
{
public:
	string screenResolution;
	string proccessor;
	string memory;
	string hdd;
	string battery;

	void Show() const
	{
		cout << "Screen Resolution: " << screenResolution << endl;
		cout << "Proccessor: " << proccessor << endl;
		cout << "Memory: " << memory << endl;
		cout << "HDD: " << hdd << endl;
		cout << "Battery: " << battery << endl;
	}
};

class LaptopBuilder
{
public:
	Laptop * laptop;
	void CreateNewLaptop()
	{
		Laptop = new Laptop();
	}
	// Метод, який повертає готовий ноутбук назовні
	Laptop * GetMyLaptop() const
	{
		return laptop;
	}
	// Кроки, необхідні щоб створити ноутбук
	virtual void SetMonitorResolution() = 0;
	virtual void SetProcessor() = 0;
	virtual void SetMemory() = 0;
	virtual void SetHDD() = 0;
	virtual void SetBattery() = 0;
};

// Таким будівельником може бути працівник, що
// спеціалізується у складанні «геймерських» ноутів
class GamingLaptopBuilder : public LaptopBuilder
{
	void SetMonitorResolution()
	{
		Laptop->MonitorResolution = "1900X1200";
	}
	void SetProcessor()
	{
		Laptop->Processor = "Core 2 Duo, 3.2 GHz";
	}
	void SetMemory()
	{
		Laptop->Memory = "6144 Mb";
	}
	void SetHDD()
	{
		Laptop->HDD = "500 Gb";
	}
	void SetBattery()
	{
		Laptop->Battery = "6 lbs";
	}
};

// А ось інший «збирач» ноутів
class TripLaptopBuilder : public LaptopBuilder
{
	void SetMonitorResolution()
	{
		Laptop->MonitorResolution = "1200X900";
	}
	void SetProcessor()
	{
		//.. і так далі...
	}
};

class LaptopDirector
{
	LaptopBuilder * builder;
public:
	void SetBuilder(LaptopBuilder * b)
	{
		builder = b;
	}
	Laptop * GetLaptop() const
	{
		return builder->GetMyLaptop();
	}
	void Configurate()
	{
		// Створення ноутбука
		builder->CreateNewLaptop();
		// Етапи його побудови
		builder->SetMonitorResolution();
		builder->SetProcessor();
		builder->SetMemory();
		builder->SetHDD();
		builder->SetBattery();
		// Повернення готового ноутбука
		return builder->GetMyLaptop;
	}
};

void main()
{
	LaptopDirector dir;
	dir.SetBuilder(new GamingLaptopBuilder());
	// dir.SetBuilder(new TripLaptopBuilder());
	dir.Configurate();
	Laptop * laptop = dir.GetLaptop();

	laptop->Show();
}