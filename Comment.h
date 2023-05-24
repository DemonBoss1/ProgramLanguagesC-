#pragma once

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
					return true;
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
						return true;
					}
					break;
				case '\n':
					line++;
				default:
					star = true;
				}
			}
			return false;
		}
	}
	bool checkComment(char ch) {
		int line = 1;
		return checkComment(ch, line);
	}
};