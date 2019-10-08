#pragma once


// Опис елемента

class List
{
private:

	int size;

struct Element
{
	int num;// дані
	
	Element * next;	// зв'язок з наступним елементом
};
	Element * head;		// голова списка (перший елемент)
	Element * tail;		// хвіст списку (останній елемент)

public:
	// Конструктор по замовчуванню
	List()
	{
		// На початку список порожній,
		// тобто першого елемента не існує
		head = nullptr;
		tail = nullptr;
	}

	bool IsEmpty() const { return head == nullptr; }

	// Добавлення елемента вкінець списку
	void AddToEnd(int data);

	// Добавлення елемента на початок списку
	void AddToBegin(int data);

	//Добавлення по індексу
	void AddToIndex(int index,int data);

	//видалення по індексу
	void DellToIndex(int index);

	//пошук по індексу
	void Search(int index);

	//заміна по індуксу
	void SearchAndReplacement(int index,int data);

	// Видалення голови (першого елемента)
	void DeleteHead();

	//Видалення з кінця
	void DeleteEnd();

	// Показ всіх елементів
	void ShowList() const;
};