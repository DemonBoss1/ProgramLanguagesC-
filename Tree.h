#pragma once
#include "main.h"

class Tree {
public:
	char data;
	Tree* left = nullptr;
	Tree* right = nullptr;
	Tree(string str, int& index) {
		switch (str[index])
		{
		case '+': case '-': case '*': case '/': case '^':
			data = str[index];
			index--;
			left = new Tree(str, index);
			right = new Tree(str, index);
			break;
		default:
			data = str[index];
			index--;
			break;
		}
	}
	void print() {
		cout << this->data << endl;
		if (left != nullptr) {
			cout << "L";
			left->print();
		}
		if (right != nullptr) {
			cout << "R";
			right->print();
		}
	}
};