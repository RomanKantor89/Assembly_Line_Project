// Project - Ms3
// Name: Roman Kantor
// Seneca Student ID: 159379171
// Seneca email: Rvindalovski@myseneca.ca
// Date of completion: Nov 25, 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include<algorithm>
#include"CustomerOrder.h"

size_t CustomerOrder::m_widthField = 0;

//defoult constructor
CustomerOrder::CustomerOrder() {
	m_lstItem = nullptr;
}

//custom constructor
CustomerOrder::CustomerOrder(std::string& record) {

	Utilities utiObj;
	bool check = true;
	size_t pos = 0;

	m_name = utiObj.extractToken(record, pos, check);
	m_product = utiObj.extractToken(record, pos, check);
	m_cntItem = std::count(record.begin(), record.end(), utiObj.getDelimiter());
	m_cntItem--;

	m_lstItem = new ItemInfo*[m_cntItem];

	for (size_t i = 0u; i < m_cntItem; ++i) {
		m_lstItem[i] = new ItemInfo(utiObj.extractToken(record, pos, check));
	}

	if (CustomerOrder::m_widthField < utiObj.getFieldWidth()) {
		CustomerOrder::m_widthField = utiObj.getFieldWidth();
	}
}


//copy constructor
CustomerOrder::CustomerOrder(const CustomerOrder& src) {
	throw std::string("ERROR: Cannot make copies");
}

//move constructor
CustomerOrder::CustomerOrder(CustomerOrder&& src)noexcept {
	m_lstItem = nullptr;
	*this = std::move(src);
}
//move assignment
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) {
	if (this != &src) {
		if (m_lstItem != nullptr) {
			for (unsigned i = 0; i < m_cntItem; ++i) {
				delete m_lstItem[i];
			}
			delete[] m_lstItem;
		}

		m_cntItem = src.m_cntItem;
		m_name = src.m_name;
		m_product = src.m_product;
		m_lstItem = src.m_lstItem;
		src.m_lstItem = nullptr;
	}
	return *this;
}

//destructor
CustomerOrder::~CustomerOrder() {

	if (m_lstItem != nullptr) {

		for (size_t i = 0; i < m_cntItem; ++i) {
			delete m_lstItem[i];
		}

		delete[]m_lstItem;
	}

}

//return m_fillState of the item in the parameter if item doesnt exist in order returns true
bool CustomerOrder::getItemFillState(std::string str) const {

	bool fillState = true;

	for (unsigned i = 0; i < m_cntItem; ++i) {

		if (m_lstItem[i]->m_itemName == str) {

			fillState = m_lstItem[i]->m_fillState;

		}

	}

	return fillState;
}

//returns true if all the items in the order have been filled, false otherwise
bool CustomerOrder::getOrderFillState() const {

	bool orderState = true;

	for (unsigned i = 0; i < m_cntItem; ++i) {

		if (m_lstItem[i]->m_fillState == false) {

			orderState = false;
		}
	}

	return orderState;
}


//manages item 
void CustomerOrder::fillItem(Item& item, std::ostream& os) {

	for (unsigned i = 0; i < m_cntItem; ++i) {

		if (m_lstItem[i]->m_itemName == item.getName())
		{
			if (item.getQuantity() > 0) {
				item.updateQuantity();

				m_lstItem[i]->m_serialNumber = item.getSerialNumber();

				m_lstItem[i]->m_fillState = true;

				os << "Filled " << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;
			}
			else {
				os << "Unable to fill " << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;
			}
		}
	}
}

void CustomerOrder::display(std::ostream& os) const {

	os << m_name << " - " << m_product << std::endl;

	for (unsigned i = 0; i < m_cntItem; ++i) {

		os << "[";
		os << std::right << std::setfill('0');
		os.width(6);
		os << m_lstItem[i]->m_serialNumber << "] ";
		os << std::setfill(' ');
		os.width(m_widthField);
		os << std::left;
		os << m_lstItem[i]->m_itemName << " - ";
		if (m_lstItem[i]->m_fillState == true) {

			os << "FILLED" << std::endl;
		}
		else {

			os << "MISSING" << std::endl;
		}
	}
}