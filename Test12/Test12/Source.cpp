#include"Test.h"
#include<iostream>
#include<string>

using namespace std;
int main() {
	int exist = 0;
	string login;
	string password;
	Test T;
	bool exit = true;
	int choice = 0;
	Test *arr = nullptr;

	while (exit) {
		cout << "\t1.Registration!\n\t2.Authorization\n\t0.Exit\n";
		cout << "Enter choice: ";
		cin >> choice;
		if (choice == 1) {
			system("cls");
			T.fillakk(T);
			T.Registration(T);
			
		}
		else if (choice == 2) {
			system("cls");
			T.fillakk(T);
			exist = T.authorization(arr, T);
			if (exist == 1) {
				while (exit) {
					cout << "1.Test\n\t2.MyAVGPoints0.Exit\n";
					cin >> choice;
					if (choice == 1) {
						system("cls");
						T.test(T);
					}
					else if (choice == 2) {
						system("cls");
						T.myavgpoints(login, password);
					}
					else  if (choice == 0) {
						system("cls");
						exit = false;
					}
				}
				exit = true;
			}
		}
		else if (choice == 0) {
			exit = false;
		}

	}

	return 0;
}