#include "Stack.h"
#include <iostream>
using namespace std;

void main()
{

	char str[255];
	cin.getline(str,255);

	Stack st;


	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '<') {

			st.Push(1);
		}
		else if (str[i] == '{') {

			st.Push(2);
		}
		else if (str[i] == ')') {

			
				st.Push(3);
		}
		else if (str[i] == ')') {
			
				st.Push(3);
		
		}
		else if (str[i] == '}') {
			
			st.Push(2);
	
		}
		else if (str[i] == '>') {
			
			st.Push(1);
			
		}
		

		
	}

	if (st.IsEmpty()) {

		cout << "Good" << endl;

	}
	else if (!st.IsEmpty()) { cout << "Error" << endl; }

	system("pause");
}