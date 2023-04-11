#include "main.h"

stack<char> stringToStack(string str) {
	stack<char> term;
	int i = 0;
	while (str[i]!='\0')
	{
		term.push(str[i]);
		i++;
	}
	return term;
}
stack<char> stringToStack(string str, stack<char> term) {
	int i = 0;
	while (str[i] != '\0')
	{
		term.push(str[i]);
		i++;
	}
	return term;
}
stack<char> fileToStack(ifstream& fin) {
	stack<char> programStack;
	while (!fin.eof()) {
		programStack.push(fin.get());
	}
	return programStack;
} 
void testTransfer() {
	ifstream fin;
	fin.open("Test.txt");
	try {
		stack<char> term = fileToStack(fin);
		for (int i = 0; !term.empty(); i++) {
			cout << term.top();
			term.pop();
		}
	}
	catch(exception e) {
		cout << "ERROR";
	}
}