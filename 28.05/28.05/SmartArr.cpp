#include<iostream>
#include "SmartArr.h"

using namespace std;

Array::Array(int newValue, int newcol, int newrow) {

	col = newcol;
	row = newrow;
	
	
	
	arr = new int*[row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}

	for (int i = 0; i < row; ++i) {

		for (int j = 0; j < row; ++j) {

			arr[i][j] = newValue;
		}

	}
}

Array::Array() {

	arr = nullptr;
	col = 0;
	row = 0;
	
}


void Array::Print() {


	for (int i = 0; i < col; i++) {

		
		for (int j = 0; j < row; j++) {

			cout << " " << arr[i][j];


		}
		cout << endl;
	}
	cout << endl;
}



void Array::AddFirst(int newValue) {

	
	int **arrNew = new int*[row+1];

	for (int i = 0; i < col; i++) {

		arrNew[i] = new int [col];
	}
	for (int i = 0; i < row; i++) {

		 
		for (int j = 0; j < col; j++) {


			*arrNew[i] = *arr[i];

		}

	}


	delete[] arr;
	arr = arrNew;
	++row;

}



void Array::DelIndex() {

}
