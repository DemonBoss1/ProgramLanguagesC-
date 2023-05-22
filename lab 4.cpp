#include "main.h"
#include "Comment.h"

class PolishWrite {
	Comment comment;
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
		number = ' ';
	}
	vector <int> variable;
	void transformation(ifstream& fin) {
		char ch1 = ' ', ch2 = ' ';
		char ch;
		while (!fin.eof())
		{
			ch = fin.get();
			if (comment.checkComment(ch)) {
				writeVar(ch);
			}
		}
		while (!sings.empty()) {
			composingAnEquation(sings.begin(), partMath.begin());
		}
		cout << *partMath.begin() << endl;
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
			sings.push_back(ch);
		case '=': case -1:
			if (str != "") partMath.push_back(str);
			else {
				str = number;
				partMath.push_back(str);
			}
			str = "";
			number = ' ';
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
	void composingAnEquation(list<char>::iterator sing, list<string>::iterator pMath) {
		list<char>::iterator s_it = sing;
		s_it++;
		if (s_it == sings.end())s_it = sing;
		list<string> ::iterator pm_it = pMath;
		pm_it++;
		if ((operationPriority.find(*(sing))->second) >= (operationPriority.find(*(s_it))->second)) {
			str = (*pMath);
			str += *(pm_it);
			str += *(sing);
			*pMath = str;
			partMath.erase(pm_it);
			sings.erase(sing);
		}
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
