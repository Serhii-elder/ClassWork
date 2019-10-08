#include "List.h"
#include <iostream>
using std::cout;
using std::endl;

void List::AddTail(int data)
{
	Element * newElement = new Element;
	newElement->num = data;
	newElement->next = nullptr;
	newElement->prev = nullptr;

	if (head == nullptr)
		head = tail = newElement;
	else
	{
		tail->next = newElement;
		newElement->prev = tail;
		tail = newElement;
	}
	++size;
}

void List::AddHead(int data)
{
	Element * newElement = new Element;
	newElement->num = data;
	newElement->prev = nullptr;
	newElement->next = nullptr;

	if (head == nullptr)
		head = tail = newElement;
	else
	{
		newElement->next = head;
		head->prev = newElement;
		head = newElement;
	}
	++size;
}

void List::Add(int pos, int data)
{
	if (pos > size + 1 || pos <= 0)
		throw InvalidPos();

	if (pos == 1)
	{
		AddHead(data);
		return;
	}
	if (pos == size + 1)
	{
		AddTail(data);
		return;
	}

	Element * newElem = new Element;
	newElem->num = data;

	Element * temp = head;
	/*int counter = 0;
	while (temp != nullptr && counter != pos - 2)
	{
		temp = temp->next;
		++counter;
	}*/

	for (int p = 1; p != pos; ++p)
		temp = temp->next;

	newElem->next = temp;
	newElem->prev = temp->prev;
	temp->prev->next = newElem;
	temp->prev = newElem;

	++size;
}

void List::DeleteHead()
{
if (!IsEmpty())
{
	Element * temp = head;
	head = head->next;
	head->prev = nullptr;
	delete temp;

	if (head == nullptr)
		tail = nullptr;

	--size;
}
}

void List::DeletePos(int pos)
{

	if (!IsEmpty())
	{
		if (pos > size || pos <= 0)
			throw InvalidPos();

		if (pos == 1)
		{
			DeleteHead();
			return;
		}
		if (pos == size)
		{
			DeleteTail();
			return;
		}


		Element * temp = head;

		for (int p = 1; p != pos; ++p) {
			temp = temp->next;
		}

		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;

		delete temp;
		--size;
	}

}

void List::DeleteTail()
{

	if (!IsEmpty())
	{
		Element * temp = tail;


		tail->prev->next = nullptr;
		tail = tail->prev;
		delete temp;

		--size;
	}

}

int List::SearchPos(int value)
{
	Element * item = head;

	if (IsEmpty())
	{
		//cout << "List is empty!\n";
		throw InvalidEmpti();
	}

	for (int i = 1; i < size + 1; ++i) {



		if (item->num == value) {
			return i;
		}
		item = item->next;
	}
	throw InvalidValue();

	//for (Element * item = head; item != nullptr; item = item->next)
	//{
	//	i++;
	//	if(item->num == pos)
	//	cout << "Element: " << item->num << endl;
	//	return i;
	//	//else cout << "0" << endl;
	//}
}

void List::Sort() {


	Element * min = head;

	for (Element * i = head; i != nullptr; i = i->next) {
		min = i;
		for (Element * j = i->next; j != nullptr; j = j->next) {
			if (j->num < min->num) {

				min = j;

			}

		}
		int tmp = i->num;
		i->num = min->num;
		min->num = tmp;
	}

	/*for (Element * i = head; i != nullptr; i = i->next) {
		for	(Element * j = i->next; j != nullptr; j = j->next){
			if (i->num > j->num) {
				int num = i->num;
				i->num = j->num;
				j->num = num;

			}

		}

	}*/


}







void List::ShowList() const
{
	if (IsEmpty())
	{
		cout << "List is empty!\n";
		return;
	}

	/*Element * current = head;
	do
	{
		cout << "Element: " << current->num << endl;
		current = current->next;
	} while (current->next != nullptr);*/

	for (Element * item = head; item != nullptr; item = item->next)
	{
		cout << "Element: " << item->num << endl;
	}

	/*Element * current = head;
	while (current != nullptr)
	{
		cout << "Element: " << current->num << endl;
		current = current->next;
	}*/
}