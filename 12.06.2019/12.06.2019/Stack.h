#pragma once

class Stack
{
	enum { EMPTY = -1, FULL = 10 };
	int data[FULL + 1];
	int topIndex;

public:
	Stack() { topIndex = EMPTY; }
	~Stack() = default;

	bool Push(int elem);
	int Pop();

	int GetCount() const;
	bool IsEmpty() const;
	bool IsFull() const;
	void Clear();
};