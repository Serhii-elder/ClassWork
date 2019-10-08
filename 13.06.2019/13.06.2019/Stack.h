#pragma once

class Stack
{

	int *data;
	int *priorytis;
	int size;
	int maxsize;
	

public:
	//Stack(int newdata,int newprior);
	~Stack() = default;

	void InsertWithPriority(int elem, int prior);



	/*bool Push(int elem);
	int Pop();

	bool IsEmpty() const;*/
	
	bool IsEmpty() const;
	bool IsFull() const;

	void Clear();
};