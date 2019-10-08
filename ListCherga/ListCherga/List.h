#pragma once
#include<iostream>
using namespace std;

// �����'����� ������
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
	// ���� ��������
	struct Element
	{
		int num;		// ���
		Element * next;	// ��'���� � ��������� ���������
		Element * prev;	// ��'���� � ��������� ���������
	};

	Element * head;		// ������ ������ (������ �������)
	Element * tail;		// ���� ������ (������� �������)

	int size;

public:
	// ����������� �� ������������
	List()
	{
		// �� ������� ������ �������,
		// ����� ������� �������� �� ����
		head = tail = nullptr;
		size = 0;
	}

	bool IsEmpty() const { return size == 0; }

	// ���������� �������� ������ ������
	void AddTail(int data);
	// ���������� �������� �� ������� ������
	void AddHead(int data);

	// ���������� �������� � �������
	void Add(int pos, int data);

	// ��������� ������ (������� ��������)
	void DeleteHead();


	void DeletePos(int pos);


	void DeleteTail();

	int SearchPos(int pos);

	void Sort();

	
	

	void Invalide();
	// ����� ��� ��������
	void ShowList() const;
};
