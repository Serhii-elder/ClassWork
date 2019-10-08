#include<iostream>
#include "Data.h"
using namespace std;



int main() {


	Data d1(1, 1, 4);
	Data d2(1, 1, 3);
	
	
	cout << d1 - d2 << endl;;
	
	system("pause");
	return 0;
}