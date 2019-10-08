#include <iostream>
#include <string>
#include "array.h"
#include <ctime>

using namespace std;

int main() {

	Array arr(20,5);
	
    arr.Print();
	arr.AddFirst();
	arr.Print();
	system("pause");
	return 0;
}