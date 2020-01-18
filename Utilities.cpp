// Project - Ms3
// Name: Roman Kantor
// Seneca Student ID: 159379171
// Seneca email: Rvindalovski@myseneca.ca
// Date of completion:Nov 25, 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include "Utilities.h"

char Utilities::m_delimiter;

//setes the fieldwidth of the current object
void Utilities::setFieldWidth(size_t width) {

	m_widthField = width;
}

//returns the fieldwidth of the current object
size_t Utilities::getFieldWidth() const {

	return m_widthField;

}

//extracts tokens from the string (str is single line from a file)
const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {

	std::string token = "";
	int endPos = 0;

	endPos = str.find(m_delimiter, next_pos);

	if (endPos != -1) {

		token = str.substr(next_pos, (endPos - next_pos));
	}
	else
	{
		token = str.substr(next_pos);
	}

	if (token.empty() && endPos != -1) {

		throw std::string("Two delimiters with no token between them");
		more = false;
	}
	else {
		
		next_pos += token.size() + 1;
		more = true;

		size_t temp = token.length();

		if (temp > m_widthField && endPos != -1) {

			m_widthField = temp;
		}
	}
	
	more = (next_pos < str.size() - 1);

	return token;
}

//set the delimeter to the character received
void Utilities::setDelimiter(const char del) {

	m_delimiter = del;
}

//returns the delimiter character of the current object
const char Utilities::getDelimiter() const {

	return m_delimiter;
}



