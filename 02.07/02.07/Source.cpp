#include <iostream>
using namespace std;

class PasswordInvalid
{
public:
	PasswordInvalid() {}
	void message()
	{
		cout << "Password invalid!\n";
		cout << "8 > characters, a-b, A-B\n";
	}
};

class ArgZero
{
	int numOfArg;
public:
	ArgZero(int num) : numOfArg(num) {}
	void message()
	{
		cout << "Argument: " << numOfArg
			<< " - equals zero!\n";
	}
};

double divide(double v1, double v2)
{
	if (v1 == 0)
		throw ArgZero(1);

	if (v2 == 0)
		throw ArgZero(2);

	return v1 / v2;
}

void Login(const char* login, const char* password)
{
	if (strlen(password) < 8)
		throw PasswordInvalid();

	cout << "Logining...\n";
}

void main()
{
	// Divide
	int a = 10, b = 5;

	try
	{
		cout << divide(a, b) << endl;
	}
	catch (ArgZero ex)
	{
		ex.message();
	}
	catch (...)
	{
		cout << "Error!\n";
	}

	// Login
	char buff[100];

	for (int i = 0; i < 5; ++i)
	{
		cout << "Enter password: ";
		cin >> buff;

		try
		{
			Login("hire", buff);
			break;
		}
		catch (PasswordInvalid e)
		{
			e.message();
		}
	}

	system("pause");
}