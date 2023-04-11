#include "main.h"

int countErrorNoOpenBracket = 0;
int countErrorNoCloseBracket = 0;


void ErrorNoOpenBracket(int i, char c) {
	std::cout << "Error: The opening parenthesis '" << c << "' is missing. Position of the closing parenthesis: " << i << endl;
	countErrorNoOpenBracket++;
}
void caseCloseBracket(map<char, int>& bracketCount, vector<char>&lastOpenBracket, int i, char c) {
	map<char, int>::iterator it;
	it = bracketCount.find(c);
	if (it->second  == 0) {
		ErrorNoOpenBracket(i, c);
	}
	else if (lastOpenBracket.empty()) {
		ErrorNoOpenBracket(i, c);
	}
	else while (find(lastOpenBracket.begin(), lastOpenBracket.end(), c) != lastOpenBracket.end()) {
		if (lastOpenBracket[0] == it->first) {
			//cout << "close" << c << endl;
			it->second--;
			lastOpenBracket.erase(lastOpenBracket.begin());
			break;
		}
		else {
			std::cout << "Error: The bracket is not closed yet '" << lastOpenBracket[0] << "'" << endl;
			bracketCount.find(lastOpenBracket[0])->second--;
			countErrorNoCloseBracket++;
			lastOpenBracket.erase(lastOpenBracket.begin());
		}
	}
}

void bracketCount(stack<char>programStack) {
	stack<char>term = programStack;
	map<char, int> bracketCount;
	bracketCount.insert(map<char, int>::value_type(')', 0));
	bracketCount.insert(map<char, int>::value_type(']', 0));
	bracketCount.insert(map<char, int>::value_type('}', 0));
	bracketCount.insert(map<char, int>::value_type('>', 0));
	int i = 0;
	map<char, int>::iterator it;
	vector <char> lastOpenBracket;
	bool solidus = false;
	bool star = false;
	bool lineComent = false;
	bool multilineComment = false;
	while (!term.empty())
	{
		if (!lineComent && !multilineComment) {
			it = bracketCount.find(term.top());
			if (it != bracketCount.end()) {
				//cout << str[i] << endl;
				it->second++;
				lastOpenBracket.insert(lastOpenBracket.begin(), it->first);
			}
			switch (term.top())
			{
			case '(':
				if (solidus)solidus = false;
				caseCloseBracket(bracketCount, lastOpenBracket, i, ')');
				break;
			case '[':
				if (solidus)solidus = false;
				caseCloseBracket(bracketCount, lastOpenBracket, i, ']');
				break;
			case '{':
				if (solidus)solidus = false;
				caseCloseBracket(bracketCount, lastOpenBracket, i, '}');
				break;
			case '<':
				if (solidus)solidus = false;
				caseCloseBracket(bracketCount, lastOpenBracket, i, '>');
				break;
			case '/':
				solidus = true;
				break;
			case '*':
				if (solidus) {
					star = true;
					multilineComment = true;
				}
				break;
			case '\n':
				lineComent = true;
			default:
				if (solidus)solidus = false;
				break;
			}
		}
		else {
			if (lineComent) {
				if (term.top() == '/') {
					if (solidus) {
						lineComent = false;
						solidus = false;
					}
					solidus = true;
				}
				break;
			}
			else {
				switch (term.top()) {
				case '*':
					star = false;
					break;
				case '/':
					if (!star) {
						solidus = false;
						multilineComment = false;
					}
					break;
				default:
					star = true;
				}
			}
		}
		term.pop();
	}
	std::cout << "Number of unclosed brackets" << endl;
	for (it = bracketCount.begin(); it != bracketCount.end(); it++) {
		std::cout << it->first << " " << it->second << endl;
	}
	std::cout << "No open bracket: " << countErrorNoOpenBracket << endl;
	std::cout << "No close bracket: " << countErrorNoCloseBracket << endl;
}

void bracketTest(ifstream& fin) {
	stack<char> programStack = fileToStack(fin);
	bracketCount(programStack);
}
//, ..., , , <<<  }} > }}}}}}}})0990909)9000>  < ))]]}}}}]]]}]
