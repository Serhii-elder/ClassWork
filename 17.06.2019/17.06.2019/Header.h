#pragma once
#include<iostream>
using namespace std;
struct Element 
{

	int num;

	Element * next;

};

class List {

private:
	Element * head;
public:
	List() {

		head = nullptr;
	}

	void AddToLast(int data) {

		Element * newElement = new Element;

		newElement->num = data;
		newElement->next = nullptr;

		if (head == nullptr)
			head = newElement;
		else {
			Element * temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = newElement;
		}

	}

	void showList() const {

		if (head == nullptr) {
			cout << "Is empty!" << endl;
			return;
		}
		/*Element * temp = head;
		do
		{
			cout << "Element: " << temp->num << endl;
			temp = temp->next;
			
		} while (temp->next != nullptr);
*/

		Element * current = head;
		while (current != nullptr)
		{
			cout << "Element: " << current << endl;
			current = current->next;
		}
	}
};