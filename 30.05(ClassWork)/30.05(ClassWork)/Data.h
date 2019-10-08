#pragma once
class Data {
private:

	int data;

	int month;

	int year;

	
public:

	Data () : data(0),month(0),year(0){ }

	Data (int newdata,int newmonth,int newyear) : data(newdata),month(newmonth),year(newyear){ }

	bool  Visok(int newyear) const;

	int Dat() const;

	int operator-(const Data& other)const;


};

