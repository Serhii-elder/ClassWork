#pragma once
#include<iostream>
using namespace std;

// Двузв'язний список
class InvalidPos {

public:
	InvalidPos(){}
	void message() {
		cout << "Icorect pos!" << endl;
	}
};
class InvalidEmpti {

public:
	InvalidEmpti(){}
	void message() {
		cout << "List empty!" << endl;
	}
};
class InvalidValue {

public:
	InvalidValue(){}
	void message() {
		cout << "Invalide value!" << endl;
	}
};


class List
{
private:
	// Опис елемента
	struct Element
	{
		int num;		// дані
		Element * next;	// зв'язок з наступним елементом
		Element * prev;	// зв'язок з попереднім елементом
	};

	Element * head;		// голова списка (перший елемент)
	Element * tail;		// хвіст списка (останній елемент)

	int size;

public:
	// Конструктор по замовчуванню
	List()
	{
		// На початку список порожній,
		// тобто першого елемента не існує
		head = tail = nullptr;
		size = 0;
	}

	bool IsEmpty() const { return size == 0; }

	// Добавлення елемента вкінець списку
	void AddTail(int data);
	// Добавлення елемента на початок списку
	void AddHead(int data);

	// Добавлення елемента в позицію
	void Add(int pos, int data);

	// Видалення голови (першого елемента)
	void DeleteHead();


	void DeletePos(int pos);


	void DeleteTail();

	int SearchPos(int pos);

	void Sort();

	
	

	void Invalide();
	// Показ всіх елементів
	void ShowList() const;
};
