#include <iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<Windows.h>
using namespace std;

class DataBase {
protected:
	int Connect(string connect) {

		if (connect != "database.txt") {
			cout << "The wrong way!" << endl;
			return 0;
		}
		return 1;
	}
	void Log(string a) {
		SYSTEMTIME st;
		GetSystemTime(&st);
		string path = "database.txt";
		ofstream out(path, ios_base::app);

		out << st.wHour + 3 << ":" << st.wMinute << ":" << st.wSecond << "  " << a << "\n";

		out.close();
		cout << "Done!" << endl;
	}
public:

	virtual void WriteLog(string connect, string log) {
		int i = Connect(connect);
		int a = rand() % 3;

		if (i == 1) {
			if (a == 1) {
				cout << "60% - good connection!" << endl;
			}
			else {
				cout << "40% - bad connection!" << endl;
			}
			Log(log);
		}
	}
};
class DataBaseProxy : public DataBase {
public:
	void WriteLog(string connect, string log) {



		int a = Connect(connect);
		if (a == 1) {
			string f;
			ifstream in("databaselocal.txt", ios_base::in | ios_base::binary);
			
			
				in>>f;
			
			in.close();

			DataBase::WriteLog(connect, f);
		}
		else {
			SYSTEMTIME st;
			GetSystemTime(&st);
			string path = "databaselocal.txt";
			ofstream out(path, ios_base::app);

			out << st.wHour + 3 << ":" << st.wMinute << ":" << st.wSecond << "  " << a << "\n";

			out.close();
		}
	}
};
class Helper {
public:
	static DataBase* GetData() {
		return new DataBaseProxy();
	}
};
int main() {
	srand(unsigned(time(NULL)));

	DataBase* data = Helper::GetData();
	data->WriteLog("database.txt", "hello");
	/*DataBaseProxy data;
	data.WriteLog("database.txt", "hello");*/

	/*DataBase* data = Helper2.GetData();
	data->WriteLog("database.txt", "hello");
	*/

	system("pause");
	return 0;
}
