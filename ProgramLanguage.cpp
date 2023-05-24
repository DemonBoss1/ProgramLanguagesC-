#include "main.h"


void testTransfer();
void testEx3();
void testEx4();
void testEx5();

int main()
{
	/*ifstream fin;
	fin.open("Test.txt");
	cout << Old::bracketTest(fin) << endl;
	fin.close();*/
	testEx5();
}

bool isInteger(string word) {
	bool isNumber = true;
	for (string::const_iterator k = word.begin(); k != word.end(); ++k) {
		if (*(word.begin()) == '-' || *(word.begin()) == '+') continue;
		isNumber = isNumber && isdigit(*k);
	}
	return isNumber;
}
bool isFloat(string word) {
	bool decimalPoint = false;
	bool isNumber = true;
	for (string::const_iterator k = word.begin(); k != word.end(); ++k) {
		if (*k == '.')
			if (!decimalPoint) {
				decimalPoint = true;
				continue;
			}
			else return false;
		if (*(word.begin()) == '-' || *(word.begin()) == '+') continue;
		isNumber = isNumber && isdigit(*k);
	}
	return isNumber;
}
