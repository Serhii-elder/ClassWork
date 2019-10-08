#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//ostream& operator<<(ostream& os, const file_saver& my)
//{
//	os.write((char*)&my, sizeof(my));
//	return os;
//}
//// file.opeartor<<(obj).operator<<(obj2).operator<<(obj3);
//
//istream& operator>>(istream& is, const file_saver& my)
//{
//	is.read((char*)&my, sizeof(my));
//	return is;
//}

class File {
private:
	ifstream file;
	string str;

public:

	File(string name) {

		file.open(name, ios_base::in);
		if (!file.is_open())
		{
			cerr << "File could`n open.";
			exit(1);
		}
	}
	~File() {

		file.close();
	}

	void read() {

		file >> str;

	}

	void show() {
		cout << str << endl;
	}
};




int main() {


	File str("MyClass.txt");

	str.read();
	str.show();
	
	system("pause");
	return 0;
}

