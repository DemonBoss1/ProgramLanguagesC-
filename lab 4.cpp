#include "main.h"

class PolishWrite {
	bool secondVarWrite = false;
	string finishWhite;
	map<char, int> operationPriority;
	list <string> partMath;
	list <char> sings;
	char number;
	string str;
public:
	PolishWrite() {
		operationPriority.insert(map<char, int>::value_type('-', 0));
		operationPriority.insert(map<char, int>::value_type('+', 0));
		operationPriority.insert(map<char, int>::value_type('*', 1));
		operationPriority.insert(map<char, int>::value_type('/', 1));
		operationPriority.insert(map<char, int>::value_type('^', 2));
		str = "";
	}
	vector <int> variable;
	void transformation(ifstream& fin) {
		char ch1 = ' ', ch2 = ' ';
		char ch;
		while (!fin.eof())
		{
			ch = fin.get();
			writeVar(ch);
		}
	}
	 
	void writeVar(char ch) {
		switch (ch)
		{
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
			if (number != ' ') {
				if (str == "")str += number;
				str += ch;
			}
			else number = ch;
			break;
		case '+': case '-': case '*': case '/': case '^':
			if (str != "") partMath.push_back(str);
			else {
				str = number;
				partMath.push_back(str);
			}
			str = "";
			sings.push_back(ch);
			break;
		default:
			cout << "ERROR!!!!" << endl;
			break;
		}
	}
	void print() {
		for (list <string>::iterator it = partMath.begin(); it != partMath.end(); it++)
			cout << it->data() << endl;
	}
};

void testEx4() {
	ifstream fin;
	PolishWrite polishWrite;
	string filename = "Test.txt";
	fin.open(filename);
	if (Old::bracketTest(filename)) {
		polishWrite.transformation(fin);
	}
	else cout << "Error bracket";
	fin.close();
}
