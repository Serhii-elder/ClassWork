#include<string>
#include<iostream>
#include<fstream>
#include<ctime>
#include <windows.h>

using namespace std;

class Loger {
private:
	static Loger * p_instance;
	Loger() {}
	Loger(const Loger&) {}
	Loger& operator=(Loger&) {}
public:
	void Log(string log) {
		//time_t seconds;

		//seconds = time(NULL); // получить текущую дату, выраженную в секундах
		////cout << seconds / 3600 << std::endl;
		//ofstream out("Log.txt", ios_base::app);
		//out << log << seconds / 3600 <<endl;
		//out.close();

		SYSTEMTIME st;
		GetSystemTime(&st);
		string path = "log.txt";
		ofstream out(path, ios_base::app);

		out << st.wHour + 3 << ":" << st.wMinute << ":" << st.wSecond << "  " << log << "\n";

		out.close();
	}
	static Loger * getInstance() {
		if (!p_instance)
			p_instance = new Loger();
		return p_instance;
	}
};
Loger* Loger::p_instance = 0;



int main() {

	Loger::getInstance()->Log("Log!");

	

	system("Pause");
	return 0;
}
