#include <iostream>
#include <string>

class Person{

public:
	std::string name;       //  имя
	int age;                // возраст
	void display()
	{
		std::cout << "Name: " << name << "\tAge: " << age << std::endl;
	}
};
class Employee : public Person
{
public:
	std::string company;    // компания

	void show() {

		Employee::display();
		std::cout <<"Company: "<< company << std::endl;
	}
};

int main()
{
	Person tom;
	tom.name = "Tom";
	tom.age = 23;
	tom.display();

	Employee bob;
	bob.name = "Bob";
	bob.age = 31;
	bob.company = "Microsoft";
	bob.show();
	system("pause");
	return 0;
}