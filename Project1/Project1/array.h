#pragma once
#include<iostream>

using namespace std;

class Array {
private:

	int *arr;
	int size;
	int a;


public:

	Array();
	Array(int newValue,int newSize);

	
	void Print();
	void AddFirst();
	void DelIndex();

};