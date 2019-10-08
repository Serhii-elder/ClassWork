#include "List.h"
#include <iostream>
using namespace std;

using namespace ListRes;

void main()
{
	List list;

	list.ShowList();
	cout << "============================" << endl;
	list.AddToEnd(1);
	list.AddToEnd(2);
	list.AddToEnd(3);
	cout << "============================" << endl;
	list.ShowList();

	list.AddToBegin(7);
	cout << "============================" << endl;
	list.ShowList();
	list.DeleteEnd();
	cout << "============================" << endl;
	list.ShowList();

	cout << "============================" << endl;
	list.AddToIndex(2, 222);
	list.ShowList();
	cout << "============================" << endl;
	list.DellToIndex(2);
	list.ShowList();
	cout << "============================" << endl;
	list.Search(2);
	cout << "============================" << endl;
	list.SearchAndReplacement(2, 5);
	list.ShowList();
	//list.ShowList();

	system("pause");
}