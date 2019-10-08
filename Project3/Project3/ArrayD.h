#pragma once
#include<iostream>
using namespace std;


template <typename T>

class Array {
private:
	int *arr;
	int size;

public:

	Array(int newsize);

	Array();
	Array(const Array & other);

	void Print() const;
	//void Add() ;
	void Fill();

	~Array();

	Array(Array &&);
	Array & operator = (const Array&);
	Array & operator = (Array&&);


	
};


template <typename T>
Array<T>::~Array()
{
	if (this->arr != nullptr) {

		delete[] arr;
	}
	else arr = nullptr;
}


template<typename T>
inline Array<T>::Array(int newsize)
{
	this->size = newsize;
	
}

template <typename T>
Array<T>::Array()
{
	arr = nullptr;
	size = 0;

}




template <typename T>
Array<T>::Array(const Array<T> & other)
{
	this->arr = other.arr;
	this->size = other.size;
	other.arr = nullptr;
	other.size = 0;
}


template <typename T>
void Array<T>::Print() const
{
	

		for (int i = 0; i < size; i++) {

			arr[i] = 0;
		}
	
	
	// cout << "Array dosen't exist" << endl;
}

//template <typename T>

//void Array<T>::Add() {
//
//
//	*newarr = new int[size + 1];
//
//	for (int i = 1; i < size + 1; i++)
//	{
//		newarr[i] = arr[i];
//
//	}
//	newarr[o] = 1;
//
//	delete[]arr;
//	arr = newarr;
//}

template <typename T>
void Array<T>::Fill()
{
	for (int i = 0; i < size; i++)
	{

		cout << arr[i] << " ";
	}
	cout << endl;
}

template <typename T>
Array<T>::Array(Array<T> && other)
{
	arr = other.arr;
	other.arr = nullptr;
	
}

template <typename T>
Array<T> & Array<T>::operator=(const Array<T> & other)
{
	if (this != &other)
	{
		delete arr;
		arr = new  T;
	}
	*arr = *other.arr;
	return *this;
}

template <typename T>
Array<T> & Array<T>::operator=(Array<T> && other)
{
	if (this->arr != other.arr)
	{
		arr = other.arr;
		other.arr = nullptr;
	}
	return *this;
}
