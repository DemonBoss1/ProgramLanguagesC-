#include "main.h"
#include "Comment.h"

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
		for (int i = 0; i < vars.size(); i++) {
			if (vars[i].name == name) {
				vars[i].value = value;
				return;
			}
		}
		vars.push_back(Variable(name, value));
	}
	void setVariabls(string name) {
		for (int i = 0; i < vars.size(); i++) {
			if (vars[i].name == name) return;
		}
		vars.push_back(Variable(name, ""));
	}
	string getType() { return type; }
	bool searchVarible(string name) {
		for (int i = 0; i < vars.size(); i++)
			if (vars[i].name == name) return true;
		return false;
	}
	string getValue(string name) {
		for (int i = 0; i < vars.size(); i++)
			if (vars[i].name == name) return vars[i].value;
		cout << "Error no search value" << endl;
		return "0";
	}

};

class TableVarible {
private:
	vector<TableLine> table;
	string type, name, value;
	string str = "";
	int line = 1;
	bool afterComma = false;
	bool isEqually = false;
	bool isString = false;
	bool isCalculated = false;
	string mathematicalExpression = "";
public:
	TableVarible(ifstream& fin) {
		Comment comment;
		char ch;
		while (!fin.eof())
		{
			ch = fin.get();
			if (comment.checkComment(ch, line)) {
				if (type == "")advertisementType(ch);
				else if (name == "")checkName(ch);
				else checkValue(ch);
			}
		}
		cout << endl;
		this->printTable();
	}
	bool checkType() {
		if (str == "int" || str == "char" || str == "short" || str == "long" || str == "float" || str == "double" || str == "bool" || str =="string") {
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
		case '\t': case '^': case '&': case '*': case '(': case ')': case '-': case '+': case '`': case '~':
		case '[': case ']': case '{': case '}': case '<': case '>': case '/': case '?': case '\\': case '|':
			str = "";
			break;
		case ' ':
			if (searchVarible(str)) 
				name = str;
			else if (checkType())
				type = str;
			str = "";
			break;
		case '=':
			if (searchVarible(str)) {
				name = str;
				isEqually = true;
			}
			str = "";
			break;
		default:
			str += ch;

		}
	}
	void checkName(char ch) {
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
				str = "";
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
				str = "";
			}
			afterComma = true;
			name = "";
			str = "";
			break;
		case '=':
			isEqually = true;
			name = str;
			if (name != "") {
				cout << type << " " << name << " " << line << endl;
				this->addVarToTable(type, name);
				str = "";
			}
			break;
		case ':': case '.': case '"': case '\'': case '!': case '@': case '#': case '$': case '%':
		case '\t': case '^': case '*': case '(': case '-': case '+': case '`':
		case '~': case '[': case '{': case '<': case '>': case '/': case '?': case '\\': case '|':
			str = "";
			type = "";
		case '&':
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
				str = "";
			}
			break;
		default:
			str += ch;
		}
	}
	void checkValue(char ch) {
		if (isString) {
			writeString(ch);
			return;
		}
		if (isCalculated) {
			calculationValue(ch);
			return;
		}
		switch (ch)
		{
		case '=':
			if (isEqually) {
				isEqually = false;
				break;
			}
			isEqually = true;
			break;
		case '\n': case ';': case '}':	case ':': case '!': case '@': case '#':
		case '\t': case '^': case '&': case '*': case '+': case '`': case '$': case '%':
		case '~': case '{': case '<': case '>': case '/': case '?': case '\\': case '|':
			if (isEqually)
				if (str == "true" || str == "false" || isInteger(str) || isFloat(str))
					if ((type == "bool" && (str == "true" || str == "false")) || ((type == "int" || type == "char" || type == "long" || str == "short") && isInteger(str)) || ((type == "float" || type == "double") && isFloat(str))) {
						value = str;
						this->addVarToTable(type, name, value);
						cout << type << " " << name << " " << value << " " << line << endl;
						isEqually = false;
					}
					else cout << "Error type " << line << endl;
				else if (searchVar(str)) {
					isCalculated = true;
					calculationValue(ch);
					break;
				}
				else cout << "No write " << line << endl;
			str = type = name = value = "";
			break;
		case ',':
			if (isEqually)
				if (str == "true" || str == "false" || isInteger(str) || isFloat(str))
					if ((type == "bool" && (str == "true" || str == "false")) || ((type == "int" || type == "char" || type == "long" || str == "short") && isInteger(str)) || ((type == "float" || type == "double") && isFloat(str))) {
						value = str;
						this->addVarToTable(type, name, value);
						cout << type << " " << name << " " << value << " " << line << endl;
						isEqually = false;
						afterComma = true;
					}
					else cout << "Error type " << line << endl;
			else cout << "No write " << line << endl;
			name = value = str = "";
		case '"': case '\'':
			if (isEqually) {
				if (str == "") {
					str += ch;
					isString = true;
				}
				else cout << "Error " << line;
			}
			break;
		case ' ':
			break;
		case '.': case '-': case '(': case ')': case '[': case ']':
		default:
			if (isEqually) str += ch;
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
	void addVarToTable(string type, string name, string value) {
		for (int i = 0; i < table.size(); i++) {
			if (table[i].getType() == type) {
				table[i].setVariabls(name, value);
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
	bool searchVarible(string name) {
		for (int i = 0; i < table.size(); i++)
			if (table[i].searchVarible(name)) {
				type = table[i].getType();
				return true;
			}
		return false;
	}
	bool searchVar(string name) {
		for (int i = 0; i < table.size(); i++)
			if (table[i].searchVarible(name)) {
				return true;
			}
		return false;
	}
	string getValue(string name) {
		for (int i = 0; i < table.size(); i++)
			if (table[i].searchVarible(name)) {
				return table[i].getValue(name);
			}
		cout << "Error no search " << name << " " << line << endl;
		return "0";
	}
	void writeString(char ch) {
		switch (ch)
		{
		case '"': case '\'':
			if (str[0] == ch) {
				str += ch;
				value = str;
				this->addVarToTable(type, name, value);
				cout << type << " " << name << " " << value << " " << line << endl;
				str = type = name = value = "";
				isEqually = false;
				isString = false;
			}
			else str += ch;
			break;
		case '\n':
			cout << "ERROR string write!!" << endl;
			str = type = name = value = "";
			isEqually = false;
			isString = false;
			break;
		default:
			str += ch;
		}
	}
	void calculationValue(char ch) {
		if (mathematicalExpression == "") {
			mathematicalExpression = getValue(str);
			str = "";
		}
		switch (ch)
		{
		case ';':
			if (str != "") {
				int index = mathematicalExpression.size() - 1;
				if (mathematicalExpression[index] == '+' || mathematicalExpression[index] == '-' || mathematicalExpression[index] == '*' || mathematicalExpression[index] == '/' || mathematicalExpression[index] == '^') {
					mathematicalExpression += getValue(str);
					str = "";
				}
				else cout << "Error no sing!!!" << endl;
			}
			value = calculationExpression(mathematicalExpression);
			this->addVarToTable(type, name, value);
			cout << type << " " << name << " " << value << " " << line << endl;
			mathematicalExpression = "";
			isCalculated = false;
			isEqually = false;
		case ' ': case '\n': case '\t':
			break;
		case '+': case '-':
			if (str != "") {
				int index = mathematicalExpression.size() - 1;
				if (mathematicalExpression[index] == '+' || mathematicalExpression[index] == '-' || mathematicalExpression[index] == '*' || mathematicalExpression[index] == '/' || mathematicalExpression[index] == '^') {
					mathematicalExpression += getValue(str);
					str = "";
				}
				else cout << "Error no sing!!!" << endl;
			}
			if (mathematicalExpression[mathematicalExpression.size() - 1] == ch) {
				mathematicalExpression += '1';
				break;
			}
		case'*': case '/': case '^':
			mathematicalExpression += ch;
			break;
		default:
			str += ch;
			break;
		}
		
	}
};


void testEx3() {
	ifstream fin;
	fin.open("Test.txt");
	TableVarible tableVariable(fin);
	fin.close();
}