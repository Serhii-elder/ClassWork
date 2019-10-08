#pragma once 
#include <iostream>
using namespace std;
//#define Item int;


class Tree {

private:
struct  Node
{
	int data;
	Node * left;
	Node *right;

	Node(int data, Node * left = nullptr, Node * right = nullptr)
		: data(data), left(left), right(right)
	{

	}

};

	Node * root;
	void Add(int data, Node *& node) {

		if (node == nullptr) {
			node = new Node(data);
		}

		if (data > node->data)
			Add(data, node->right);
		else
			Add(data, node->left);
	}

	void PrintLKP(const Node * node) const {
		if (node != nullptr) {
			PrintLKP(node->left);
			cout << node->data << endl;
			PrintLKP(node->right);
		}
	}

public: 
	Tree()
	{
		root = nullptr;
	}

	void Add(int data) {

		Add(data, root);
	}

	void Show()const {
		PrintLKP(root);
	}

};