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
	bool closeBracket = false;
	string result;
public:
	vector <string> variables;
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
		while ((!fin.eof()) && (!closeBracket))
		{
			ch = fin.get();
			if (comment.checkComment(ch)) {
				writeVar(ch, fin);
			}
		}
		while (!sings.empty()) {
			composingAnEquation(sings.begin(), partMath.begin());
		}
		finishWhite = *partMath.begin();
		cout << finishWhite << endl << endl;
		for (int i = 0; i < variables.size(); i++) cout << "A[" << i << "] = " << variables[i] << endl;
		cout << endl;
	}
	 
	void writeVar(char ch, ifstream& fin) {
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
			if (number != ' ') {
				if (str != "") {
					variables.push_back(str);
					str = "A[";
					str += to_string(variables.size() - 1);
					str += ']';
					partMath.push_back(str);
				}
				else {
					str = number;
					partMath.push_back(str);
				}
				str = "";
				number = ' ';
			}
			break;
		case '(':
			if (str != "") cout << "Error!!!";
			else {
				string partBracket = partInBracket(fin);
				partMath.push_back(partBracket);
			}
			break;
		case ')':
			if (str != "") {
				variables.push_back(str);
				str = "A[";
				str += to_string(variables.size() - 1);
				str += ']';
				partMath.push_back(str);
			}
			else {
				str = number;
				partMath.push_back(str);
			}
			str = "";
			number = ' ';
			closeBracket = true;
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
		else composingAnEquation(s_it, pm_it);
	}
	string partInBracket(ifstream& fin) {
		PolishWrite polishWrite;
		polishWrite.variables = this->variables;
		polishWrite.transformation(fin);
		this->variables = polishWrite.getVariables();
		return polishWrite.getFinishWhite();
	}
	string getFinishWhite() { return finishWhite; }
	vector <string> getVariables() { return variables; }
	void solution(string type) {

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
