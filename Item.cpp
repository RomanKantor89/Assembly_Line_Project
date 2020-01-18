// Project - Ms3
// Name: Roman Kantor
// Seneca Student ID: 159379171
// Seneca email: Rvindalovski@myseneca.ca
// Date of completion:Nov 25, 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include "Item.h"
#include "Utilities.h"

size_t Item::m_widthField = 0;

Item::Item(const std::string& record) {

	Utilities utiObj;
	bool check = true;
	size_t pos = 0;

	try {
		m_name = utiObj.extractToken(record, pos, check);

		m_serialNumber = stoi(utiObj.extractToken(record, pos, check));

		m_quantity = stoi(utiObj.extractToken(record, pos, check));

		m_description = utiObj.extractToken(record, pos, check);
	}
	//catch the error if there are two delimiters in a row
	catch (std::string err) { std::cout << err << std::endl; }
	// catch any other error 
	catch (...) { std::cout << "Unknown Error" << std::endl; }


	if (Item::m_widthField < utiObj.getFieldWidth()) {

		Item::m_widthField = utiObj.getFieldWidth();
	}



}

//returns the name of the current item object
const std::string& Item::getName() const {

	return m_name;
}

//returns the next serial number to be used on the assembly line and increments 
const unsigned int Item::getSerialNumber() {

	return m_serialNumber++;
}

//returns the remaining quantity of the current Item object
const unsigned int Item::getQuantity() {

	return m_quantity;
}

//substracts 1 from the available quantity; should not be less than 0
void Item::updateQuantity() {

	if (m_quantity > 0) {
		m_quantity--;
	}
}

//inserts the content of the current object into os
void Item::display(std::ostream& os, bool full) const {

	if (full == false) {

		os << std::setfill(' ');
		os.width(m_widthField);
		os << std::left;
		os << m_name << " [";
		os << std::right << std::setfill('0');
		os.width(6);
		os << m_serialNumber << "]" << std::endl;
	}
	else
	{
		os << std::setfill(' ');
		os.width(m_widthField);
		os << std::left;
		os << m_name << " [";
		os << std::right << std::setfill('0');
		os.width(6);
		os << m_serialNumber << "]" << " Quantity: ";
		os.width(m_widthField);
		os << std::left;
		os << std::setfill(' ');
		os << m_quantity;
		os << " Description: " << m_description << std::endl;

	}
}



