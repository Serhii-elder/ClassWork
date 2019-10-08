#include "Stack.h"

//Stack::Stack(int newdata, int newprior) {
//
//
//	data = newdata;
//
//
//}

void Stack::InsertWithPriority(int elem, int prior)
{

	for (int i = 0; i < size; i++) {

		data[i] = elem;
		priorytis[i] = prior;
	}







}



//bool Stack::Push(int elem)
//{
//	if (!IsFull())
//	{
//		data[++topIndex] = elem;
//		return true;
//	}
//	return false;
//}
//
//int Stack::Pop()
//{
//	if (!IsEmpty())
//		return data[topIndex--];
//
//	return 0;
//}
//
//int Stack::GetCount() const
//{
//	return topIndex + 1;
//}
//
bool Stack::IsEmpty() const
{
	return size == 0;
}

bool Stack::IsFull() const
{
	return size == maxsize;
}

void Stack::Clear()
{
	size = 0;
}
