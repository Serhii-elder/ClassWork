#include<iostream>

#include "array.h"

using namespace std;

Array::Array(int newValue, int newSize) {
	
	size = newSize;
	arr = new int[size];

	for (int i = 0; i < size; i++) {

		arr[i] = newValue;

	}
}

Array::Array() {

	arr = nullptr;
	size = 0;
}



void Array::Print() {


	for (int i = 0; i < size; i++) {

		cout << " " << arr[i];

	}
	cout << endl;
}

void Array::AddFirst() {

	int number = 0;

	cout << "\n\tEnter number + : ";
	cin >> number;
	int *arrNew = new int[size + 1];

	for (int i = 0; i < size;i++) {

		arrNew[i+1] = arr[i];
	}
	arrNew[0] = number;

	delete[] arr;
	arr = arrNew;
	++size;

}

void Array::DelIndex() {



}