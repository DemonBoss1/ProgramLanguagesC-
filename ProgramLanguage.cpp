#include "main.h"


void testTransfer();
void testEx3();
void testEx4();

int main()
{
	/*ifstream fin;
	fin.open("Test.txt");
	cout << Old::bracketTest(fin) << endl;
	fin.close();*/
	testEx3();
}

bool isInteger(string word) {
	bool isNumber = true;
	for (string::const_iterator k = word.begin(); k != word.end(); ++k)
		isNumber = isNumber && isdigit(*k);
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
		isNumber = isNumber && isdigit(*k);
	}
	return isNumber;
}
