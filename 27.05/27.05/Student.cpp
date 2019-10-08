#include "Student.h"


bool Student::isValidName(string name)
{
	const int len = name.length();

	if (len <= 0)
	{
		return false;
	}

	for (int i = 0; i < len; ++i)
	{
		if (!isalpha(name[i]))
		{
			return false;
		}
	}

	return true;
}
bool Student::isValidAge(int age)
{
	const int minAge = 10;
	const int maxAge = 30;

	if (age < minAge || age > maxAge)
	{
		return false;
	}

	return true;
}

Student::Student(string name, string surname, int age, bool isDayForm)
{
	setAll(name, surname, age, isDayForm);
	cout << "I`m constructor from: ";
	cout << name << endl;
}

string Student::getName() const
{
	return name;
}
string Student::getSurname() const
{
	return surname;
}
void Student::setAge(int age)
{
	if (isValidAge(age))
	{
		this->age = age;
	}
	else
	{
		cout << "Invalid age!" << endl;
	}
}
void Student::setDayForm(bool isDayForm)
{
	this->isDayForm = isDayForm;
}
void Student::setAll(string name, string surname, int age, bool isDayForm)
{
	setName(name);
	setSurname(surname);
	setAge(age);
	setDayForm(isDayForm);
}

void Student::setName(string name)
{
	if (isValidName(name))
	{
		this->name = name;
	}
	else
	{
		cout << "Invalid name!" << endl;
	}
}
void Student::setSurname(string surname)
{
	if (isValidName(surname))
	{
		this->surname = surname;
	}
	else
	{
		cout << "Invalid surname!" << endl;
	}
}
int Student::getAge() const
{
	return age;
}
bool Student::getDayForm() const
{
	return isDayForm;
}

void Student::showStudent() const
{
	cout << setw(15) << left << "Name: " << setw(15) << left << name << endl;
	cout << setw(15) << left << "Surname: " << setw(15) << left << surname << endl;
	cout << setw(15) << left << "Age: " << setw(15) << left << age << endl;
	cout << setw(15) << left << "Is day form: " << setw(15) << left << boolalpha << isDayForm << endl;
}

const Student& Student::getOlderStudent(const Student& student) const
{
	if (student.age > this->age)
	{
		return student;
	}
	else
	{
		return *this;
	}
}