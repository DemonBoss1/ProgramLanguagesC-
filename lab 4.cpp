#include "main.h"
#include "Comment.h"
#include "Tree.h"

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
	bool isIndex = false;
	bool isDecided = false;
	string type = "int";
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
		cout << finishWhite << endl;
		print();
	}
	 
	void writeVar(char ch, ifstream& fin) {
		switch (ch)
		{
		case '.':
			type = "float";
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
		case ' ':
			break;
		default:
			cout << "ERROR!!!!" << endl;
			break;
		}
	}
	void print() {
		cout << endl;
		for (int i = 0; i < variables.size(); i++) cout << "A[" << i << "] = " << variables[i] << endl;
		cout << endl;
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
	void solution() {
		while (!isDecided) {
			solutionPart();
		}
		print();
		if (finishWhite.size() > 1) {
			result = variables[variables.size() - 1];
		}
		else result = finishWhite;
	}
	void solutionPart() {
		char sing = ' ';
		string num1 = "", num2 = "";
		string index = "";
		for (int i = 0; i <= finishWhite.size(); i++) {
			if (finishWhite[i] == '+' || finishWhite[i] == '-' || finishWhite[i] == '*' || finishWhite[i] == '/' || finishWhite[i] == '^') {
				sing = finishWhite[i];
				for (int j = i - 1; j >= 0; j--) {
					switch (finishWhite[j])
					{
					case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.':
						if (!isIndex) {
							if (num2 == "")
								if (num1 == "")num1 = finishWhite[j];
								else {
									num2 = finishWhite[j];
									finishWhite.erase(j, i - j + 1);
									calculation(type, sing, num1, num2, j);
									cout << finishWhite << endl;
									return;
								}
							else cout << "Error var" << endl;
						}
						else {
							index += finishWhite[j];
						}
						break;
					case ']':
						isIndex = true;
						break;
					case '[':
						isIndex = false;
						break;
					case 'A':
						if (num2 == "")
							if (num1 == "") {
								num1 = variables[stoi(index)];
								index = "";
							}
							else {
								num2 = variables[stoi(index)];
								finishWhite.erase(j, i - j + 1);
								calculation(type, sing, num1, num2, j);
								cout << finishWhite << endl;
								return;
							}
						else cout << "Error var" << endl;
					default:
						break;
					}
				}
			}
			if (i == finishWhite.size()) {
				isDecided = true;
				return;
			}
		}
	}
	void calculation(string type, char sing, string& num1, string& num2, int j) {
		if (type == "int") {
			if (sing == '+') {
				num1 = to_string(stoi(num1) + stoi(num2));
				if (num1.size() > 1) {
					variables.push_back(num1);
					str = "A[";
					str += to_string(variables.size() - 1);
					str += ']';
					finishWhite.insert(j, str);
				}
				else finishWhite.insert(j, num1);
				
			}
			else if (sing == '-') {
				num1 = to_string(stoi(num2) - stoi(num1));
				if (num1.size() > 1) {
					variables.push_back(num1);
					str = "A[";
					str += to_string(variables.size() - 1);
					str += ']';
					finishWhite.insert(j, str);
				}
				else finishWhite.insert(j, num1);
			}
			else if (sing == '*') {
				num1 = to_string(stoi(num1) * stoi(num2));
				if (num1.size() > 1) {
					variables.push_back(num1);
					str = "A[";
					str += to_string(variables.size() - 1);
					str += ']';
					finishWhite.insert(j, str);
				}
				else finishWhite.insert(j, num1);
			}
			else if (sing == '/') {
				num1 = to_string(stoi(num2) / stoi(num1));
				if (num1.size() > 1) {
					variables.push_back(num1);
					str = "A[";
					str += to_string(variables.size() - 1);
					str += ']';
					finishWhite.insert(j, str);
				}
				else finishWhite.insert(j, num1);
			}
			else if (sing == '^') {
				num1 = to_string(pow(stoi(num2), stoi(num1)));
				if (num1.size() > 1) {
					variables.push_back(num1);
					str = "A[";
					str += to_string(variables.size() - 1);
					str += ']';
					finishWhite.insert(j, str);
				}
				else finishWhite.insert(j, num1);
			}
		}
		else if (type == "float") {
			if (sing == '+') {
				num1 = to_string(stof(num1) + stof(num2));
				if (num1.size() > 1) {
					variables.push_back(num1);
					str = "A[";
					str += to_string(variables.size() - 1);
					str += ']';
					finishWhite.insert(j, str);
				}
				else finishWhite.insert(j, num1);

			}
			else if (sing == '-') {
				num1 = to_string(stof(num2) - stof(num1));
				if (num1.size() > 1) {
					variables.push_back(num1);
					str = "A[";
					str += to_string(variables.size() - 1);
					str += ']';
					finishWhite.insert(j, str);
				}
				else finishWhite.insert(j, num1);
			}
			else if (sing == '*') {
				num1 = to_string(stof(num1) * stof(num2));
				if (num1.size() > 1) {
					variables.push_back(num1);
					str = "A[";
					str += to_string(variables.size() - 1);
					str += ']';
					finishWhite.insert(j, str);
				}
				else finishWhite.insert(j, num1);
			}
			else if (sing == '/') {
				num1 = to_string(stof(num2) / stof(num1));
				if (num1.size() > 1) {
					variables.push_back(num1);
					str = "A[";
					str += to_string(variables.size() - 1);
					str += ']';
					finishWhite.insert(j, str);
				}
				else finishWhite.insert(j, num1);
			}
			else if (sing == '^') {
				num1 = to_string(pow(stof(num2), stof(num1)));
				if (num1.size() > 1) {
					variables.push_back(num1);
					str = "A[";
					str += to_string(variables.size() - 1);
					str += ']';
					finishWhite.insert(j, str);
				}
				else finishWhite.insert(j, num1);
			}
		}
	}
	string getResult() { return result; }

	void createTree() {
		int index = finishWhite.size() - 1;
		Tree* tree = new Tree(finishWhite, index);
		tree->print();
	}
};

void testEx4() {
	ifstream fin;
	PolishWrite polishWrite;
	string filename = "Test.txt";
	fin.open(filename);
	if (Old::bracketTest(filename)) {
		polishWrite.transformation(fin);
		polishWrite.createTree();
		/*polishWrite.solution();
		ofstream fout("output.txt");
		fout << polishWrite.getResult();
		fout.close();*/
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