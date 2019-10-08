#include "String.h"
#include <iostream>

using namespace std;

void String::SetStringFromKeyboard() {

	if (str != nullptr) {
		delete[] str;
	}

	char word[255];

	cin.getline(word,255);

	ten = strlen(word);

		str = new char[ten];

		for (int i = 0; i < ten; i++) {

			str[i] = word[i];
		}

		str[ten] = '\0';
}

String::String() {

	str = nullptr;
	ten = 0;
	count++;
}

String::String(const String & string) {

	if (string.str != nullptr) {

		this->ten = string.ten;
		str = new char[ten + 1];

	}
	for (int i = 0; i < ten; i++)
	{

		str[i] = string.str[i];
	}

	str[ten] = '\0';


}

String::~String() {
	
		delete[] str;
	
}


void String::ShowString() const
{
	cout << endl;
		cout << str;
		cout << endl;
}





