#include <iostream>
#include <string>
using namespace std;

enum Priority { PLUS_MINUS, MULT_DIV, MAX_PR };

struct Node
{
	char data;
	Node* left, *right;
};

Priority GetPriority(char op)
{
	switch (op)
	{
	case '-': case '+': return PLUS_MINUS;
	case '/': case '*': return MULT_DIV;
	default: return MAX_PR;
	}
}

Node* CreateTree(string ex, int first, int last)
{
	Node* tree = new Node;
	
	for (int i = 0; i < ex.length(); i++) {

		if (ex[i] == ' ') {

			ex[i] = ex[i + 1];
			ex.length();
		}
	}
	

	if (first == last)
	{
		tree->data = ex[first];
		tree->left = nullptr;
		tree->right = nullptr;
		return tree;
	}

	int counter = 0;
	int k = first;
	int minPr = MAX_PR;
	for (int i = first; i <= last; ++i)
	{
		if (ex[i] == '(') ++counter;
		else if (ex[i] == ')') --counter;

		if (counter == 0)
		{
			if (GetPriority(ex[i]) <= minPr)
			{
				minPr = GetPriority(ex[i]);
				k = i;
			}
		}
	}

	if (minPr == MAX_PR)
	{
		delete tree;
		return CreateTree(ex, first + 1, last - 1);
	}

	tree->data = ex[k];
	tree->left = CreateTree(ex, first, k - 1);
	tree->right = CreateTree(ex, k + 1, last);

	return tree;
}

void PrintLPK(Node* tree)
{
	if (tree == nullptr)
		return;

	PrintLPK(tree->left);
	PrintLPK(tree->right);
	cout << tree->data << ' ';
}
void PrintLKP(Node* tree)
{
	if (tree == nullptr)
		return;

	PrintLKP(tree->left);
	cout << tree->data << ' ';
	PrintLKP(tree->right);
}

int CalcTree(Node* tree)
{
	if (tree->left == nullptr)
		return tree->data - '0';

	int left = CalcTree(tree->left);
	int right = CalcTree(tree->right);

	switch (tree->data)
	{
	case '+': return left + right;
	case '-': return left - right;
	case '*': return left * right;
	case '/': return left / right;
	}

	throw exception("Invalid operation");
}

int main()
{
	string ex = "(1+(6 -3))*4/2";
	Node* tree = CreateTree(ex, 0, ex.length() - 1);
	cout << "LPK: ";
	PrintLPK(tree);
	cout << endl;

	cout << "LKP: ";
	PrintLKP(tree);
	cout << endl;

	try
	{
		int result = CalcTree(tree);
		cout << "Result: " << result << endl;
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}

	system("pause");
	return 0;
}