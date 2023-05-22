#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <fstream>
#include <stack>
#include <Windows.h>
#include <string>
#include <list>

using namespace std;

namespace Old {
	bool bracketTest(ifstream& fin);
	bool bracketTest(string filemane);
	void easyBracketTest(ifstream& fin);
}

void createHistogram(string str);
void bracketTest(ifstream& fin);
stack<char> stringToStack(string str);
stack<char> fileToStack(ifstream& fin);

#endif // !MAIN_H
