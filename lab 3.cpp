#include "main.h"

class Comment {
private:
	bool solidus = false;
	bool star = false;
	bool lineComent = false;
	bool multilineComment = false;
public:
	bool checkComment(char ch, int& line) {

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
};

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
	TableLine(string type, string name) {
		this->type = type;
		setVariabls(name, "");
	}
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
	void setVariabls(string name) {
		for (int i = 0; i < vars.size(); i++) {
			if (vars[i].name == name) return;
		}
		vars.push_back(Variable(name, ""));
	}
	string getType() { return type; }
};

class TableVarible {
private:
	vector<TableLine> table;
	string type, name, value;
	string str = "";
	int line = 1;
	bool afterComma = false;
public:
	TableVarible(ifstream& fin) {
		Comment comment;
		char ch;
		while (!fin.eof())
		{
			ch = fin.get();
			if (comment.checkComment(ch, line)) {
				if (type == "")advertisementType(ch);
				else {
					switch (ch)
					{
					case '\n':
						str = "";
						type = "";
						name = "";
						break;
					case ';': case ')': case ']': case '}':
						name = str;
						if (name != "") {
							cout << type << " " << name << " " << line << endl;
							this->addVarToTable(type, name);
						}
						name = "";
						type = "";
						str = "";
						afterComma = false;
						break;
					case ',':
						name = str;
						if (name != "") {
							cout << type << " " << name << " " << line << endl;
							this->addVarToTable(type, name);
						}
						afterComma = true;
						name = "";
						str = "";
						break;
					case ':': case '.': case '"': case '\'': case '!': case '@': case '#': case '$': case '%':
					case '\t': case '^': case '&': case '*': case '(': case '-': case '=': case '+': case '`':
					case '~': case '[': case '{': case '<': case '>': case '/': case '?': case '\\': case '|':
						str = "";
						type = "";
						break;
					case ' ':
						if (afterComma)
							if (checkType()) {
								afterComma = false;
								type = str;
								str = "";
								break;
							}
						name = str;
						if (name != "") {
							cout << type << " " << name << " " << line << endl;
							this->addVarToTable(type, name);
						}
						break;
					default:
						str += ch;
					}
				}
			}
		}
		this->printTable();
	}
	bool checkType() {
		if (str == "int" || str == "char" || str == "short" || str == "long" || str == "float" || str == "double" || str == "bool") {
			return true;
		}
		else return false;

	}
	void advertisementType(char ch) {
		switch (ch)
		{
		case '\n':
			str = "";
			break;
		case ';': case ',': case ':': case '.': case '"': case '\'': case '!': case '@': case '#': case '$': case '%':
		case '\t': case '^': case '&': case '*': case '(': case ')': case '-': case '=': case '+': case '`': case '~':
		case '[': case ']': case '{': case '}': case '<': case '>': case '/': case '?': case '\\': case '|':
			str = "";
			break;
		case ' ':
			if (type == "") {
				if (checkType())
					type = str;

			}
			str = "";
			break;
		default:
			str += ch;

		}
	}

	void addVarToTable(string type, string name) {
		for (int i = 0; i < table.size(); i++) {
			if (table[i].getType() == type) {
				table[i].setVariabls(name);
				return;
			}
		}
		table.push_back(TableLine(type, name));
	}
	void printTable() {
		for (int i = 0; i < table.size(); i++) {
			table[i].printVar();
		}
	}
};


void testEx3() {
	ifstream fin;
	fin.open("Test.txt");
	TableVarible tableVariable(fin);
}