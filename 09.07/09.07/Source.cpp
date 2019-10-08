#include<iostream>
#include<string>

using namespace std;

template<typename T>
class SmartPointer {
	T * ptr;

public:
	SmartPointer() :ptr(nullptr) {}


	SmartPointer(T* ptr) :ptr(ptr) {}

	~SmartPointer() {
		delete ptr;
	}

	T operator * () { return *ptr; }


	T * operator -> () { return ptr; }

	T *Get() { return ptr; }

	T operator =(SmartPointer<T> & other) = delete;

	T operator =(SmartPointer<T> && other) {
		this->ptr = other.ptr;
		other.ptr = nullptr;

	}

	void relese(SmartPointer<T> & other) {
		other.ptr = this->ptr;
		this->ptr = nullptr;
	}

	void swap(SmartPointer<T> & other) {

		SmartPointer<int> tmp(new int())

		other.ptr = tmp;

		this->ptr = nullptr;

	}

};

void SetString(string & str) {

	string *newStr = new string("My string");
	str = *newStr;

	delete newStr;
}

int main() {
	int *a = new int;
	SmartPointer<int> ptr(new int());
	

	std::shared_ptr<int> sp;  // empty

	sp.reset(new int);       // takes ownership of pointer
	*sp = 10;
	std::cout << *sp << '\n';

	sp.reset(new int);       // deletes managed object, acquires new pointer
	*sp = 20;
	std::cout << *sp << '\n';

	sp.reset();
	system("pause");
	return 0;
}