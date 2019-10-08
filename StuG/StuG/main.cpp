#include<iostream>
#include"Group.h"
#include"Student.h"
using namespace std;

int main()
{
	Group A;
	Group B;
	Group Best;
	int choise = 0;

	while (true)
	{
		cout << "1 Add Student Group A\n2 Add Student Group B\n3 Show Group A\n4 Show Group B\n5 Show Best Group\n";
		cin >> choise;
		if (choise == 1)
		{
			Student New;
			New.Fill();

			A.AddStudent(New);
		}
		else if (choise == 2)
		{
			Student New;
			New.Fill();

			B.AddStudent(New);
		}
		else if (choise == 3)
		{
			A.ShowGroup();
		}
		else if (choise == 4)
		{
			B.ShowGroup();
		}
		else if (choise == 5)
		{
			Best.GetBestGroup(B);
			Best.ShowGroup();
		}
	}

	system("pause");
	return 0;
}