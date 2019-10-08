#include <iostream>
using namespace std;
class MyClass
{
	int number;

public:
	MyClass() : number(0)	// ініціалізація
	{
		// number = 0		// присвоєння
	}
	MyClass(int n) : number(n) { }

	void Show() const
	{
		std::cout << number << std::endl;
	}

	// Метод для сумування
	MyClass Plus(const MyClass& other) const
	{
		/*int res = this->number + other.number;
		MyClass c(res);
		return c;*/
		return MyClass(this->number + other.number);
	}

	// Для перевантаження оператора потрібно створити метод, назва якого є
	// operator_type
	// де _type - оператор для перевантаження
	// та передати ту кількість параметрів, яка необхідна для роботи цього оператора

	// для бінарних - два операнда
	// для унарних - один операнд
	// враховуючи те, що перший операнд це є об'єкт, який викликав метод, тобто this,
	// тому його в параметри передавати не потрібно

	// перевантаження оператора +
	// цей оператор є бінарним, тому потребує два операнди, в даному випадку вони є наступними:
	//		this	- перший операнд
	//		other	- другий
	// метод не повинен змінювати значення операндів, а лише повернути результат у вигляді нового об'єкту
	MyClass operator+(const MyClass& other) const
	{
		return MyClass(this->number + other.number);
	}

	// перевантаження оператора +
	// різниця в тому, що другим операндом тепер в нас є int
	MyClass operator+(const int other) const
	{
		return MyClass(this->number + other);
	}

	// перевантаження оператора -
	MyClass operator-(const MyClass& other) const
	{
		return MyClass(this->number - other.number);
	}

	// перевантаження оператора *
	MyClass operator*(const MyClass& other) const
	{
		return MyClass(this->number * other.number);
	}

	// перевантаження оператора /
	MyClass operator/(const MyClass& other) const
	{
		return MyClass(this->number / other.number);
	}

	// перевантаження оператора +=
	// цей оператор повинен змінювати лівий операнд - this
	// та повернути результат - самого себе
	// Це потрібно для того, щоб мати змогу зробити таку конструкцію:
	// c = a += b
	// яка буде інтерпритуватися в наступне:
	// c = a.operator+=(b)
	MyClass& operator+=(int num)
	{
		this->number += num;
		return *this;
	}

	// перевантажений оператор =
	// також змінює лівий операнд this та повертає самого себе
	// що дає змогу зробити наступну конструкцію
	// c = a = b
	// яка буде інтерпритуватися в наступне:
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

	// метод Plus
	MyClass res = m1.Plus(m2);

	// оператор + (MyClass + MyClass)
	cout << res = m1 + m2 << endl;		// res = m1.operator+(m2);

	// оператор + (MyClass + int)
	res = m1 + 43;		// res = m1.operator+(43);

	// оператор - (MyClass - MyClass)
	res = m1 - m2;		// res = m1.operator-(m2);

	// оператор * (MyClass * MyClass)
	res = m1 * m2;		// res = m1.operator*(m2);

	// оператор / (MyClass / MyClass)
	res = m1 / m2;		// res = m1.operator/(m2);

	// оператор += (MyClass += int)
	m1 += 23;			// m1.operator+=(m2);

	// оператор = (MyClass = MyClass)
	m1 = m2;			// m1.operator=(m2);

	system("pause");
}