#include "SmartArr.h"
#include<iostream>

using namespace std;

SmartArray::SmartArray()
{
	arr = nullptr;
	int col = 0;
	int row = 0;
}

SmartArray::SmartArray(int value, int col, int row)
{
	arr = new int*[row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			arr[i][j] = value;
		}
	}

	this->col = col;
	this->row = row;
}

SmartArray::~SmartArray()
{
	for (int i = 0; i < row; i++)
	{
		delete[]arr[i];
	}
}

void SmartArray::Show()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

void SmartArray::Add(int addArr[], int newRow)
{
	int ** newArr = new int*[row + 1];
	for (int i = 0; i < row + 1; i++)
	{
		newArr[i] = new int[col];
	}

	for (int i = 0; i < newRow; i++)
	{
		newArr[i] = arr[i];
	}
	newArr[newRow] = addArr;
	for (int i = newRow; i < row; i++)
	{
		newArr[i + 1] = arr[i];
	}


	
	arr = newArr;

	this->row++;
}
