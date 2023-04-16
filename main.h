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

using namespace std;

namespace Old {
	void bracketTest(ifstream& fin);
	void easyBracketTest(ifstream& fin);
}

void createHistogram(string str);
void bracketTest(ifstream& fin);
stack<char> stringToStack(string str);
stack<char> fileToStack(ifstream& fin);

#endif // !MAIN_H
