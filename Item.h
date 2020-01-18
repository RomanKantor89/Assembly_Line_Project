// Project - Ms3
// Name: Roman Kantor
// Seneca Student ID: 159379171
// Seneca email: Rvindalovski@myseneca.ca
// Date of completion:Nov 25, 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include<string>
#include <iomanip>
#include<iostream>

#ifndef ITEM_H
#define ITEM_H

class Item
{
	std::string m_name;
	std::string m_description;
	unsigned int m_serialNumber;
	unsigned int m_quantity;
	static size_t m_widthField;

public:
	//custom constructor
	Item(const std::string& record);

	//returns the name of the current item object
	const std::string& getName() const;

	//returns the next serial number to be used on the assembly line and increments 
	const unsigned int getSerialNumber();

	//returns the remaining quantity of the current Item object
	const unsigned int getQuantity();

	//substracts 1 from the available quantity; should not be less than 0
	void updateQuantity();

	//inserts the content of the current object into os
	void display(std::ostream& os, bool full) const;

};

#endif

