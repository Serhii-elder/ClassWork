#include <iostream>
using namespace std;
class MyClass
{
	int number;

public:
	MyClass() : number(0)	// �����������
	{
		// number = 0		// ���������
	}
	MyClass(int n) : number(n) { }

	void Show() const
	{
		std::cout << number << std::endl;
	}

	// ����� ��� ���������
	MyClass Plus(const MyClass& other) const
	{
		/*int res = this->number + other.number;
		MyClass c(res);
		return c;*/
		return MyClass(this->number + other.number);
	}

	// ��� �������������� ��������� ������� �������� �����, ����� ����� �
	// operator_type
	// �� _type - �������� ��� ��������������
	// �� �������� �� ������� ���������, ��� ��������� ��� ������ ����� ���������

	// ��� ������� - ��� ��������
	// ��� ������� - ���� �������
	// ���������� ��, �� ������ ������� �� � ��'���, ���� �������� �����, ����� this,
	// ���� ���� � ��������� ���������� �� �������

	// �������������� ��������� +
	// ��� �������� � �������, ���� ������� ��� ��������, � ������ ������� ���� � ����������:
	//		this	- ������ �������
	//		other	- ������
	// ����� �� ������� �������� �������� ��������, � ���� ��������� ��������� � ������ ������ ��'����
	MyClass operator+(const MyClass& other) const
	{
		return MyClass(this->number + other.number);
	}

	// �������������� ��������� +
	// ������ � ����, �� ������ ��������� ����� � ��� � int
	MyClass operator+(const int other) const
	{
		return MyClass(this->number + other);
	}

	// �������������� ��������� -
	MyClass operator-(const MyClass& other) const
	{
		return MyClass(this->number - other.number);
	}

	// �������������� ��������� *
	MyClass operator*(const MyClass& other) const
	{
		return MyClass(this->number * other.number);
	}

	// �������������� ��������� /
	MyClass operator/(const MyClass& other) const
	{
		return MyClass(this->number / other.number);
	}

	// �������������� ��������� +=
	// ��� �������� ������� �������� ���� ������� - this
	// �� ��������� ��������� - ������ ����
	// �� ������� ��� ����, ��� ���� ����� ������� ���� �����������:
	// c = a += b
	// ��� ���� ���������������� � ��������:
	// c = a.operator+=(b)
	MyClass& operator+=(int num)
	{
		this->number += num;
		return *this;
	}

	// �������������� �������� =
	// ����� ����� ���� ������� this �� ������� ������ ����
	// �� �� ����� ������� �������� �����������
	// c = a = b
	// ��� ���� ���������������� � ��������:
	// c = a.operator=(b)
	MyClass& operator=(const MyClass& other)
	{
		this->number = other.number;
		return *this;
	}
};

void main()
{
	MyClass m1(5);
	MyClass m2(10);

	// ����� Plus
	MyClass res = m1.Plus(m2);

	// �������� + (MyClass + MyClass)
	cout << res = m1 + m2 << endl;		// res = m1.operator+(m2);

	// �������� + (MyClass + int)
	res = m1 + 43;		// res = m1.operator+(43);

	// �������� - (MyClass - MyClass)
	res = m1 - m2;		// res = m1.operator-(m2);

	// �������� * (MyClass * MyClass)
	res = m1 * m2;		// res = m1.operator*(m2);

	// �������� / (MyClass / MyClass)
	res = m1 / m2;		// res = m1.operator/(m2);

	// �������� += (MyClass += int)
	m1 += 23;			// m1.operator+=(m2);

	// �������� = (MyClass = MyClass)
	m1 = m2;			// m1.operator=(m2);

	system("pause");
}