#include "main.h"

class Variable {
public:
	string name;
	string value;
	Variable(string name, string value) {
		this->name = name;
		this->value = value;
	}
};

class TableLine {
private:
	string type;
	vector<Variable> vars;
	
public:
	TableLine(string type, string name, string value) {
		this->type = type;
		setVariabls(name, value);
	}
	void printVar() {
		for (int i = 0; i < vars.size(); i++)
			cout << type << " " << vars[i].name << " = " << vars[i].value << endl;
	}
	void setVariabls(string name, string value) {
		vars.push_back(Variable(name, value));
	}
};

bool checkComment(char ch, bool& solidus, bool& star, bool& lineComent, bool& multilineComment, int& line) {

	if (!lineComent && !multilineComment) {

		switch (ch)
		{
		case '/':
			if (solidus) {
				solidus = false;
				lineComent = true;
				return false;
			}
			solidus = true;
			break;
		case '*':
			if (solidus) {
				star = true;
				multilineComment = true;
				return false;
			}
			break;
		case '\n':
			line++;
			break;
		default:
			if (solidus)solidus = false;
			break;
		}
		return true;
	}
	else {
		if (lineComent) {
			if (ch == '\n') {
				lineComent = false;
				line++;
			}
		}
		else {
			switch (ch) {
			case '*':
				star = false;
				break;
			case '/':
				if (!star) {
					solidus = false;
					multilineComment = false;
				}
				break;
			case '\n':
				line++;
				break;
			default:
				star = true;
			}
		}

	}
}

void checkType(string& str, string& type, int line) {
	if (str == "int" || str == "char" || str == "short" || str == "long" || str == "float" || str == "double") {
		type = str;
		cout << type << " " << line << endl;
	}
}
void advertisementType(char ch, string& str, string& type, int& line) {
	switch (ch)
	{
	case '\n':
		line++;
		break;
	case ';': case ',': case ':': case '.': case '"': case '\'': case '!': case '@': case '#': case '$': case '%': 
	case '\t': case '^': case '&': case '*': case '(': case ')': case '-': case '=': case '+': case '`': case '~':
	case '[': case ']': case '{': case '}': case '<': case '>': case '/': case '?': case '\\': case '|':
		str = "";
		break;
	case ' ':
		if (type == "") {
			checkType(str, type, line);
		}
		str = "";
		break;
	default:
		str += ch;

	}
}
void tableVatiable(ifstream& fin) {
	char ch;
	bool solidus = false;
	bool star = false;
	bool lineComent = false;
	bool multilineComment = false;
	string str = "";
	string type, name, value;
	int line = 1;
	while (!fin.eof())
	{
		ch = fin.get();
		if (checkComment(ch, solidus, star, lineComent, multilineComment, line)) {
			if (type == "")advertisementType(ch, str, type, line);
			else {
				switch (ch)
				{
				case '\n':
					line++;
					break;
				case ';':
					type = "";
				case ',': case ':': case '.': case '"': case '\'': case '!': case '@': case '#': case '$': case '%': case'\t':
				case '^': case '&': case '*': case '(': case ')': case '-': case '=': case '+': case '`': case '~':
				case '[': case ']': case '{': case '}': case '<': case '>': case '/': case '?': case '\\': case '|':

				case ' ':

				default:
					str += ch;
				}
			}
		}
	}
}
void testEx3() {
	ifstream fin;
	fin.open("Test.txt");
	tableVatiable(fin);
}