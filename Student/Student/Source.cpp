
#include <iostream>
#include <string>
#include "Student.h"
#include "Group.h"

using namespace std;

int main() {

	
	Student student("Sergo",2001,"shkilna",10.9);
	//Student student;
	//student.Show();
	student.Fill();
	student.Show();
	
	student.Fill();
	student.Show();
	
	/*Group group;
	group.AddStudent();
	group.Show();*/


	system("pause");
	return 0;
}

