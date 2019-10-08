#include<iostream>
#include"SmartArr.h"

using namespace std;

int main()
{

	int *arr1 = new int[3];
	for (int i = 0; i < 3; i++) {
		arr1[i] = 2;

	}

	SmartArray arr(1, 3, 3);

	arr.Show();

	arr.Add(arr1, 1);
	cout << endl;
	arr.Show();

	system("pause");
	return 0;
}