#include "List.h"
#include <iostream>
using std::cout;
using std::endl;

namespace ListRes {

	void List::AddToEnd(int data)
	{
		Element * newElement = new Element;
		newElement->num = data;
		newElement->next = nullptr;

		if (head == nullptr)
		{
			head = tail = newElement;
		}
		else
		{
			tail->next = newElement;
			tail = newElement;
		}
		++size;
	}
	void List::AddToBegin(int data)
	{
		Element * newElement = new Element;
		newElement->num = data;
		newElement->next = nullptr;

		if (head == nullptr)
			head = tail = newElement;
		else
		{
			newElement->next = head;
			head = newElement;
		}
		++size;
	}
	void List::AddToIndex(int index, int data)
	{
		if (!IsEmpty())
		{
			if (index > size&&index >= 0)
				return;

			Element * newElement = new Element;
			newElement->num = data;

			Element * temp = head;

			for (int p = 1; p != index - 1; ++p) {
				temp = temp->next;
			}
			newElement->next = temp->next;
			temp->next = newElement;
		}
		++size;
	}

	void List::DellToIndex(int index)
	{
		if (!IsEmpty())
		{
			if (index > size&&index >= 0)
				return;

			Element * temp = head;

			for (int p = 1; p != index - 1; ++p) {
				temp = temp->next;

			}
			temp->next = temp->next->next;
		}
		--size;
	}

	void List::Search(int index)
	{
		if (!IsEmpty())
		{
			if (index > size&&index >= 0) {
				cout << "Does not exist!" << endl;
				return;
			}
			Element * temp = head;

			for (int p = 1; p != index; ++p) {
				temp = temp->next;

			}
			cout << "Search result: " << temp->num << endl;
		}
	}

	void List::SearchAndReplacement(int index, int data)
	{
		if (!IsEmpty())
		{
			if (index > size&&index >= 0)
				return;

			Element * newElement = new Element;
			newElement->num = data;

			Element * temp = head;

			for (int p = 1; p != index - 1; ++p) {
				temp = temp->next;

			}

			newElement->next = temp->next->next;
			temp->next = newElement;
		}
	}

	void List::DeleteHead()
	{
		if (!IsEmpty())
		{
			Element * temp = head;
			head = head->next;
			delete temp;
		}
		--size;
	}

	void List::DeleteEnd()
	{
		if (!IsEmpty())
		{
			Element * temp = tail;

			Element * current = head;

			while (current->next != tail)
			{
				current = current->next;
			}

			delete tail;

			current->next = nullptr;

			tail = current;
		}
		--size;
	}

	void List::ShowList() const
	{
		if (IsEmpty())
		{
			cout << "List is empty!\n";
			return;
		}

		Element * current = head;
		while (current != nullptr)
		{
			cout << "Element: " << current->num << endl;
			current = current->next;
		}
	}
}