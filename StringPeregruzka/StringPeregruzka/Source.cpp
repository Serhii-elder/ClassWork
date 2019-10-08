#include "String.h"
#include <iostream>

String Create()
{
	String str1 = String('#', 5);
	str1.ShowString();
	std::cout << "\nCreated!\n";
	return str1;
}

void main()
{
	String str = Create();
	str.ShowString();


	


	




	system("pause");
}