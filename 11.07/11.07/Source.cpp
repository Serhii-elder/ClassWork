#include <iostream>
#include <vector>		// for vector
#include<string>
#include<fstream>
using namespace std;

struct Time
{
	int h, m, s;

	Time()
		:h(0),m(0),s(0){}
	Time(int h,int m,int s)
		:h(h),m(m),s(s){}
};

class Train {
	int number;
	Time time;
	string arrivePlace;

public:
	Train()
		:number(0),arrivePlace(nullptr){}
	Train(int number,int h,int m,int s,string arrivePlace)
		:number(number),time(h,m,s),arrivePlace(arrivePlace){}

	bool operator > (const Train & other) const
	{
		return ((this->time.h * 60) + (this->time.m)+(this->time.s)) > ((other.time.h * 60) + (other.time.m)+(other.time.s));
	}

	

};

class Railway {

	vector<Train> trains;
	
public:
	
	void ShowAll() {
		for (int i = 0; i < trains.size(); i++) {
			cout << "\n\tNumber: " << trains[i].number << "\n\tTime: " << trains[i].time.h << ":" << trains[i].time.m << ":" << trains[i].time.s;
			cout << "\n\tArrive: " << trains[i].arrivePlace << endl;
		}
	}
	void ShowID(int number) {
		for (int i = 0; i < trains.size(); i++) {
			if (trains[i].number == number) {
				cout << "\n\tNumber: " << trains[i].number << "\n\tTime: " << trains[i].time.h << ":" << trains[i].time.m << ":" << trains[i].time.s;
				cout << "\n\tArrive: " << trains[i].arrivePlace << endl;
			}
		}
	}
	void ShowStation(string station) {
		for (int i = 0; i < trains.size(); i++) {
			if (trains[i].arrivePlace == station) {
				cout << "\n\tNumber: " << trains[i].number << "\n\tTime: " << trains[i].time.h << ":" << trains[i].time.m << ":" << trains[i].time.s;
				cout << "\n\tArrive: " << trains[i].arrivePlace << endl;
			}
		}
	}

	void Add(int number,int h,int m,int s,string arrive ){
		Train newtrain(number,h,m,s,arrive);

		trains.push_back(newtrain);
	}

	void timetrain(int number,int hh,int mm,int ss) {
		for (int i = 0; i < trains.size(); i++) {
			if (trains[i].number == number) {
				trains[i].time.h = hh;
				trains[i].time.m = mm;
				trains[i].time.s = ss;	
			}
		}
	}

	void sortTime() {
		Train tmp;
		int j;
		// цикл проход≥в, i - номер проходу
		for (int i = 0; i < trains.size(); i++)
		{
			tmp = trains[i];

			// пошук м≥сц€ дл€ елемента в л≥вому п≥дмасив≥
			for (j = i - 1; j >= 0 && trains[j] > tmp; j--)
			{
				// здвигаЇмо елемент вправо
				trains[j + 1] = trains[j];
			}

			// м≥сце знайдено, вставити елемент
			trains[j + 1] = tmp;
		}


	}
	void SaveInFile()
	{
		ofstream out("Trains.txt", ios_base::out);

		for (int i = 0; i < trains.size(); i++)
		{
			out <<trains[i].number << endl;
			out <<trains[i].time.h << endl;
			out <<trains[i].time.m << endl;
			out <<trains[i].time.s << endl;
			out <<trains[i].arrivePlace << endl;
		
		}
		out.close();
		cout << "Done!" << endl;
	}
	void LoadFromFile()
	{
	ifstream in("Trains.txt", ios_base::in);
		for (int i = 0; i <trains.size(); i++)
		{
			in >> trains[i].number;
			in >> trains[i].time.h;
			in >> trains[i].time.m;
			in >> trains[i].time.s;
			in >> trains[i].arrivePlace;			
		}
		in.close();
		
		cout << "Done!" << endl;
	}
};
int main()
{
	Pailway t;
	t.Add(9, 5, 36, 46, "Lviv");
	//t.ShowAll();
	t.Add(10, 11, 36, 46, "Lviv");
	//t.ShowAll();
	t.ShowID(10);
	t.ShowStation("Lviv");
	t.timetrain(10, 12, 15, 12);
	t.ShowID(10);
	//t.SaveInFile();
	t.sortTime();
	t.ShowAll();
	system("pause");
	return 0;
}