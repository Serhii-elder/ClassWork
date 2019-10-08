#pragma once


// ���� ��������

class List
{
private:

	int size;

struct Element
{
	int num;// ���
	
	Element * next;	// ��'���� � ��������� ���������
};
	Element * head;		// ������ ������ (������ �������)
	Element * tail;		// ���� ������ (������� �������)

public:
	// ����������� �� ������������
	List()
	{
		// �� ������� ������ �������,
		// ����� ������� �������� �� ����
		head = nullptr;
		tail = nullptr;
	}

	bool IsEmpty() const { return head == nullptr; }

	// ���������� �������� ������ ������
	void AddToEnd(int data);

	// ���������� �������� �� ������� ������
	void AddToBegin(int data);

	//���������� �� �������
	void AddToIndex(int index,int data);

	//��������� �� �������
	void DellToIndex(int index);

	//����� �� �������
	void Search(int index);

	//����� �� �������
	void SearchAndReplacement(int index,int data);

	// ��������� ������ (������� ��������)
	void DeleteHead();

	//��������� � ����
	void DeleteEnd();

	// ����� ��� ��������
	void ShowList() const;
};