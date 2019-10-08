#include <iostream>
#include <fstream>
using namespace std;

class MyClass
{
	int data;
public:
	MyClass() : data(0) {}
	MyClass(int d) : data(d) {}
	void Show() const
	{
		cout << "Data: " << data << endl;
	}
};

ostream& operator<<(ostream& os, const MyClass& my)
{
	os.write((char*)&my, sizeof(my));
	return os;
}
// file.opeartor<<(obj).operator<<(obj2).operator<<(obj3);

istream& operator>>(istream& is, const MyClass& my)
{
	is.read((char*)&my, sizeof(my));
	return is;
}

int main()
{
	/*int num;
	cin >> num;

	if (num == 0)
		clog << "Error...\n";

	cout << "Your number: " << num << endl;*/

	/*ifstream input;
	input.open("Text.txt", ios_base::in);

	if (!input.is_open())
	{
		cerr << "File could`n open.";
		exit(1);
	}*/

	/*while (!input.eof())
	{
		char s;
		input.get(s);
		cout << s;
	}*/

	//input.close();

	/*char buff[255];
	input.getline(buff, 255, '-');
	cout << buff;*/

	/*cout << (char)input.peek();
	char s;
	input.get(s);
	cout << s;*/

	/*ofstream output("TextOut.txt", ios_base::out | ios_base::trunc);

	if (!output.is_open())
	{
		cerr << "File could`n open.";
		exit(1);
	}

	output << buff;

	output.close();

	output.open("TextOut2.txt", ios_base::out | ios_base::trunc);

	output << buff;
	output.close();*/

	MyClass my(40);
	MyClass m;

	ofstream ofile;
	ofile.open("MyClass.txt", ios_base::out | ios_base::binary);
	if (!ofile.is_open())
	{
		cerr << "File could`n open.";
		exit(1);
	}

	my.Show();
	ofile << my;
	ofile.close();

	ifstream ifile;
	ifile.open("MyClass.txt", ios_base::in | ios_base::binary);

	if (!ifile.is_open())
	{
		cerr << "File could`n open.";
		exit(1);
	}
	ifile >> m;
	m.Show();

	ifile.close();
	

	

	//ofile.write((char*)&my, sizeof(MyClass));
	
	

	
	

	system("pause");
	return 0;
}