#include "Student.h"

void main()
{
	Student st1("Vova", "Kolie", 20, true);
	Student st2 = Student("Lilia", "Kolie", 25, true);

	st1.showStudent(); // for static
	st2.showStudent(); // for pointers

	Student oldestSt = st1.getOlderStudent(st2);

	system("pause");
}