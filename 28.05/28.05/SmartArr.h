#pragma once
#include<iostream>

using namespace std;

class Array {
private:

	int **arr = nullptr;
	int col;
	int row;
	
	int a;


public:

	Array();
	Array(int newValue, int newcol,int newrow);

	

	~Array() {
		delete[]arr;
	}

	void Print();
	void AddFirst(int newValue);
	void DelIndex();

};