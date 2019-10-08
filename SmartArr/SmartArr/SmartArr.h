#pragma once
#include<iostream>
using namespace std;

class SmartArray
{
private:

	int **arr;
	int col;
	int row;

public:

	SmartArray();
	SmartArray(int, int, int);
	SmartArray(const SmartArray & other)
	{
		
	}
	~SmartArray();


	
	

	

		
	

	void Show();

	void Add(int newArr[], int newRow);

	SmartArray & operator=(SmartArray&& other);
};