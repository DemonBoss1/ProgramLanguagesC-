#pragma once
#include "main.h"
#include "PolishWrite.h"

class Tree {
	PolishWrite polishWrite;
public:
	char data;
	Tree* left = nullptr;
	Tree* right = nullptr;
	Tree(string filename) {
		ifstream fin;
		fin.open(filename);
		if (Old::bracketTest(filename)) {
			polishWrite.transformation(fin);
			int index = polishWrite.getFinishWhite().size() - 1;
			string finishWhite = polishWrite.getFinishWhite();
			createTree(finishWhite, index);
			print();
		}
		else cout << "Error bracket";
		fin.close();
	}
	Tree(string str, int& index) { createTree(str, index); }
	void createTree(string str, int& index) {
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