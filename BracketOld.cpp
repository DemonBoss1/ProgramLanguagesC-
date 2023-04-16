#include "main.h"

namespace Old{

	int countErrorNoOpenBracket = 0;
	int countErrorNoCloseBracket = 0;


	void ErrorNoOpenBracket(int i, char c) {
		std::cout << "Error: The opening parenthesis '" << c << "'. Position of the closing parenthesis: " << i << " line" << endl;
		countErrorNoOpenBracket++;
	}
	void caseCloseBracket(map<char, int>& bracketCount, vector<char>& lastOpenBracket, int i, char c) {
		map<char, int>::iterator it;
		it = bracketCount.find(c);
		if (it->second == 0) {
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
	void bracketTest(ifstream& fin) {
		map<char, int> bracketCount;
		bracketCount.insert(map<char, int>::value_type('(', 0));
		bracketCount.insert(map<char, int>::value_type('[', 0));
		bracketCount.insert(map<char, int>::value_type('{', 0));
		bracketCount.insert(map<char, int>::value_type('<', 0));
		int i = 0;
		map<char, int>::iterator it;
		vector <char> lastOpenBracket;
		char ch;
		bool solidus = false;
		bool star = false;
		bool lineComent = false;
		bool multilineComment = false;
		int line = 1;
		while (!fin.eof())
		{
			ch = fin.get();
			if (!lineComent && !multilineComment) {
				it = bracketCount.find(ch);
				if (it != bracketCount.end()) {
					//cout << str[i] << endl;
					it->second++;
					lastOpenBracket.insert(lastOpenBracket.begin(), it->first);
				}
				switch (ch)
				{
				case ')':
					if (solidus)solidus = false;
					caseCloseBracket(bracketCount, lastOpenBracket, line, '(');
					break;
				case ']':
					if (solidus)solidus = false;
					caseCloseBracket(bracketCount, lastOpenBracket, line, '[');
					break;
				case '}':
					it = bracketCount.find('{');
					if (solidus)solidus = false;
					caseCloseBracket(bracketCount, lastOpenBracket, line, '{');
					break;
				case '>':
					if (solidus)solidus = false;
					caseCloseBracket(bracketCount, lastOpenBracket, line, '<');
					break;
				case '/':
					if (solidus) {
						solidus = false;
						lineComent = true;
					}
					solidus = true;
					break;
				case '*':
					if (solidus) {
						star = true;
						multilineComment = true;
					}
					break;
				case '\n':
					line++;
					break;
				default:
					if (solidus)solidus = false;
					break;
				}
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
			i++;
		}
		std:: cout << "Number of unclosed brackets" << endl;
		for (it = bracketCount.begin(); it != bracketCount.end(); it++) {
			std::cout << it->first << " " << it->second << endl;
		}
		std::cout << "No open bracket: " << countErrorNoOpenBracket << endl;
		std::cout << "No close bracket: " << countErrorNoCloseBracket << endl;
	}
	void easyBracketTest(ifstream& fin) {
		stack<char> lastOpens;
		char ch1, ch2;
		int i = 0;
		bool solidus = false;
		bool star = false;
		bool lineComent = false;
		bool multilineComment = false;
		while (!fin.eof())
		{
			i++;
			ch1 = ch2 = fin.get();
			if (!lineComent && !multilineComment) {
				switch (ch1)
				{
				case '(': case '[': case '{':
					if (solidus)solidus = false;
					lastOpens.push(ch1);
					break;
				case ']': case '}':
					ch2--;
				case ')':
					ch2--;
					if (!lastOpens.empty())
						if (lastOpens.top() == ch2)lastOpens.pop();
						else {
							Old::ErrorNoOpenBracket(i, ch1);
							lastOpens.push(ch1);
						}
					else Old::ErrorNoOpenBracket(i, ch1);
					if (solidus)solidus = false;
					break;
				case '/':
					if (solidus) {
						solidus = false;
						lineComent = true;
					}
					solidus = true;
					break;
				case '*':
					if (solidus) {
						star = true;
						multilineComment = true;
					}
					break;
				default:
					if (solidus)solidus = false;
					break;
				}
			}
			else {
				if (lineComent) {
					if (ch1 == '\n') lineComent = false;
				}
				else {
					switch (ch1) {
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
		}
	}
}

