#include "String.h"
#include <iostream>

char * String::GetString() const
{
	char * strCopy = new char[size + 1];
	for (int i = 0; i < size; ++i)
	{
		strCopy[i] = str[i];
	}
	strCopy[size] = '\0'; // 0
	return strCopy;
}

void String::ShowString() const
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << str[i];
	}
}
