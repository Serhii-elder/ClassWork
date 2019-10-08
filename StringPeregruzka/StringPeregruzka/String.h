#pragma once

class String
{
	char * str;
	int size;

public:
	String()
	{
		str = nullptr;
		size = 0;
	}
	String(char symb, int size)
	{
		str = new char[size];
		for (int i = 0; i < size; ++i)
		{
			str[i] = symb;
		}
		this->size = size;
	}
	String(char * arr, int size)
	{
		str = new char[size];
		for (int i = 0; i < size; ++i)
		{
			str[i] = arr[i];
		}
		this->size = size;
	}

	String(const String& string)
	{
		size = string.size;
		str = new char[string.size];
		for (int i = 0; i < size; ++i)
		{
			str[i] = string.str[i];
		}
	}

	~String()
	{
		delete[] str;
	}

	void operator =(const String & other) {

		this->size = other.size;

		if (this->str != nullptr) {
			delete[] this->str;
		}

		this->str = new int[other.size];

		for (int i = 0; i < other.size; i++) {
			this->str[i] = other.str[i];
		}

	}

	char * GetString() const;
	void ShowString() const;
};