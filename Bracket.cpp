#include "main.h"

int countErrorNoOpenBracket = 0;
int countErrorNoCloseBracket = 0;


void ErrorNoOpenBracket(int i, char c) {
	cout << "Error: The opening parenthesis '" << c << "' is missing. Position of the closing parenthesis: " << i << endl;
	countErrorNoOpenBracket++;
}
void caseCloseBracket(map<char, int>& bracketCount, vector<char>&lastOpenBracket, int& bracket, int i, char c) {
	map<char, int>::iterator it;
	it = bracketCount.find(c);
	if (it->second - bracket == 0) {
		ErrorNoOpenBracket(i, c);
	}
	else if (lastOpenBracket.empty()) {
		ErrorNoOpenBracket(i, c);
	}
	else while (true) {
		if (lastOpenBracket[0] == it->first) {
			//cout << "close" << c << endl;
			it->second--;
			lastOpenBracket.erase(lastOpenBracket.begin());
			break;
		}
		else {
			cout << "Error: The bracket is not closed yet '" << lastOpenBracket[0] << "'" << endl;
			bracket++;
			countErrorNoCloseBracket++;
			lastOpenBracket.erase(lastOpenBracket.begin());
		}
	}
}

void bracketTest(string str) {
	map<char, int> bracketCount;
	bracketCount.insert(map<char, int>::value_type('(', 0));
	bracketCount.insert(map<char, int>::value_type('[', 0));
	bracketCount.insert(map<char, int>::value_type('{', 0));
	bracketCount.insert(map<char, int>::value_type('<', 0));
	int i = 0;
	map<char, int>::iterator it;
	vector <char> lastOpenBracket;
	int parenthesis = 0, squareBracket = 0, curlyBrace = 0, angleBracket = 0;
	while (str[i]!='\0')
	{
		it = bracketCount.find(str[i]);
		if (it != bracketCount.end()) {
			//cout << str[i] << endl;
			it->second++;
			lastOpenBracket.insert(lastOpenBracket.begin(), it->first);
		}
		switch (str[i])
		{
		case ')':
			caseCloseBracket(bracketCount, lastOpenBracket, parenthesis, i, '(');
			break;
		case ']':
			caseCloseBracket(bracketCount, lastOpenBracket, squareBracket, i, '[');
			break;
		case '}':
			it = bracketCount.find('{');
			caseCloseBracket(bracketCount, lastOpenBracket, curlyBrace, i, '{');
			break;
		case '>':
			caseCloseBracket(bracketCount, lastOpenBracket, angleBracket, i, '<');
			break;
		default:
			break;
		}
		i++;
	}
	cout << "Number of unclosed brackets" << endl;
	for (it = bracketCount.begin(); it != bracketCount.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	cout << "No open bracket: " << countErrorNoOpenBracket << endl;
	cout << "No close bracket: " << countErrorNoCloseBracket << endl;
}