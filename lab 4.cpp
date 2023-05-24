#include "main.h"
#include "Comment.h"
#include "Tree.h"
#include "PolishWrite.h"

void testEx4() {
	ifstream fin;
	PolishWrite polishWrite;
	string filename = "Test.txt";
	fin.open(filename);
	if (Old::bracketTest(filename)) {
		polishWrite.transformation(fin);
		polishWrite.solution();
		ofstream fout("output.txt");
		fout << polishWrite.getResult();
		fout.close();
	}
	else cout << "Error bracket";
	fin.close();
}

string calculationExpression(string str) {
	string filename = "calculation.txt";
	ofstream fout;
	fout.open(filename);
	fout << str;
	fout.close();
	ifstream fin(filename);
	PolishWrite polishWrite;
	if (Old::bracketTest(filename)) {
		polishWrite.transformation(fin);
		polishWrite.solution();
		return polishWrite.getResult();
	}
	fin.close();
}