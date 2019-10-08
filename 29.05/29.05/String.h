#pragma once

class String
{
	char * str;
	int ten;
	
public:

	static int count;

	String() ;

	String(const String & string);

	~String();

	void SetStringFromKeyboard();

	void ShowString() const;





	
};
