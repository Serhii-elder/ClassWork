#include <iostream>
using namespace std;

class AmericanSocket
{
public:
	virtual void MatchAmericanSocket()
	{
		cout << "210 V\n";
	}
};

class EuroSocket
{
public:
	virtual void MatchEuroSocket()
	{
		cout << "220 V\n";
	}
};

class ElectricityConsumer
{
public:
	void Charge(EuroSocket socket)
	{
		socket.MatchEuroSocket();
	}
};

class Adapter : public EuroSocket
{
private:
	AmericanSocket &usaS;
public:

	Adapter(AmericanSocket & usaSocket) : usaS(usaSocket)
	{}

	void MatchEuroSocket()
	{
		usaS.MatchAmericanSocket();
		// additional functionality
	}
};

void main()
{
	// EuroSocket euroS;
	AmericanSocket usaS;

	ElectricityConsumer consumer;
	consumer.Charge(Adapter(usaS));

	system("pause");
}