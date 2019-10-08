#include "List.h"
#include <iostream>
using namespace std;

void main()
{
	List list;
	int buff = 0;

	//list.AddTail(1);
	//list.AddTail(2);
	//list.AddTail(3);
	//list.AddTail(4);
	//list.AddTail(5);
	//list.AddTail(6);
	//list.ShowList();
	//cout << "--------------------\n";

	///*list.Add(1, 3);
	//list.ShowList();
	//cout << "--------------------\n";

	//list.Add(2, 9);
	//list.ShowList();
	//cout << "--------------------\n";*/

	//list.Add(4, 29);
	//list.ShowList();
	//cout << "--------------------\n";
	//list.DeletePos(2);
	//list.DeletePos(3);
	//list.ShowList();
	//cout << "--------------------\n";
	//cout << list.SearchPos(6) << endl;
	//cout << "--------------------\n";
	//list.ShowList();
	//cout << "--------------------\n";
	//list.DeleteTail();
	//list.ShowList();
	//cout << "--------------------\n";
	///*list.AddTail(6);
	//list.AddTail(18);
	//list.AddTail(3);
	//list.Sort();
	//list.ShowList();*/

	/*list.AddTail(1);
	list.AddTail(2);
	list.AddTail(3);
	cout << "--------------------\n";
	list.DeletePos(3);
	list.ShowList();
	cout << "--------------------\n";*/
	list.AddTail(3);
	list.AddTail(2);
	list.AddTail(1);
	list.ShowList();
	while (true) {
		cin >> buff;
	try {
		list.Add(buff, 2);
		break;
	}
	catch(InvalidPos e){
		e.message();
	}
	catch (...) {
		cout<<"Error\n";
	}
	}
	list.ShowList();
	
	while (true) {
		cin >> buff;
		try {
			list.DeletePos(buff);
			break;
		}
		catch (InvalidPos e) {
			e.message();
		}
		catch (...) {
			cout << "Error\n";
		}
	}
	list.ShowList();
	while (true) {
		cin >> buff;
		try {
			
			cout<<list.SearchPos(buff)<<endl;
			break;
		}
		catch (InvalidValue e) {
			e.message();
		}	
		catch (InvalidEmpti e) {
			e.message();
		}
		catch (...) {
			cout << "Error\n";
		}
	}

	
	//cout << "--------------------\n";
	//list.Sort();
	//list.ShowList();
	//cout << "--------------------\n"; 
	//cout << list.SearchPos(3) << endl;;
	system("pause");
}

