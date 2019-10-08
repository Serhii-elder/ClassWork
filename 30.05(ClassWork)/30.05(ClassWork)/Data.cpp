#include"Data.h"
#include<iostream>

using namespace std;

 bool   Data::Visok(int newyear) const {


	if (newyear % 4 == 0 || newyear % 100 == 0 && newyear % 400 == 0)
		return false;
	else  return true;

	
}

int Data::Dat() const {

	int days = 0;
	int newmonth = 0;
	int newyear = 0;

	for (int i = 0; i < year; i++) {

		if ( Visok (i) == true) {

			newyear += 366;

		}
		else if (Visok(i)  == false) {
			newyear += 365;
		}
	}

	for (int i = 1; i <= month; i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {

			newmonth += 31;

		}
		else if (i == 4 || i == 6 || i == 9 || i == 11) {
			newmonth += 30;
		}
		
	}

	days =  newyear + newmonth + data;
	
	return days;
}

int Data::operator-(const Data& other)const
{

	return this->Dat() - other.Dat();
}