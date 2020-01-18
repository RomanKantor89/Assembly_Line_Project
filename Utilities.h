// Project - Ms3
// Name: Roman Kantor
// Seneca Student ID: 159379171
// Seneca email: Rvindalovski@myseneca.ca
// Date of completion:Nov 25, 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include<string>

#ifndef UTILITIES_H
#define UTILITIES_H

class Utilities
{
	size_t m_widthField = 1;
	static char m_delimiter;


public:

	//setes the fieldwidth of the current object
	void setFieldWidth(size_t);

	//returns the fieldwidth of the current object
	size_t getFieldWidth() const;

	//extracts tokens from the string (str is single line from a file)
	const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

	//set the delimeter to the character received
	static void setDelimiter(const char del);

	//returns the delimiter character of the current object
	const char getDelimiter() const;

};

#endif