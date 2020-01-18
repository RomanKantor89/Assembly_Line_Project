// Project - Ms3
// Name: Roman Kantor
// Seneca Student ID: 159379171
// Seneca email: Rvindalovski@myseneca.ca
// Date of completion:Nov 25, 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include"Utilities.h"
#include"Item.h"
#include<string>
#ifndef CUSTOMER_ORDER_H
#define CUSTOMER_ORDER_H

struct ItemInfo
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder {

	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	ItemInfo** m_lstItem;
	static size_t m_widthField;

public:
	//defoult constructor
	CustomerOrder();

	//custom constructor
	CustomerOrder(std::string& record);

	//copy constructor
	CustomerOrder(const CustomerOrder& src);

	//deleting copy assignment
	CustomerOrder& operator=(const CustomerOrder& src) = delete;

	//move constructor
	CustomerOrder(CustomerOrder&& src) noexcept;

	//move assignment
	CustomerOrder& operator=(CustomerOrder&& src);

	//destructor
	~CustomerOrder();

	//return m_fillState of the item in the parameter if item doesnt exist in order returns true
	bool getItemFillState(std::string str) const;

	//returns true if all the items in the order have been filled, false otherwise
	bool getOrderFillState() const;

	//fills an item 
	void fillItem(Item& item, std::ostream& os);

	//display
	void display(std::ostream& os) const;

};

#endif