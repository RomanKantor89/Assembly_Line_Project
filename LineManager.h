// Project - Ms3
// Name: Roman Kantor
// Seneca Student ID: 159379171
// Seneca email: Rvindalovski@myseneca.ca
// Date of completion:Nov 25, 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include <vector>
#include "CustomerOrder.h"
#include "Task.h"

#ifndef LINEMANAGER_H
#define LINEMANAGER_H

class LineManager {

	std::vector<Task*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder;

public:

	//custom constructor sets up the tasks one after another in the AssemblyLine
	LineManager(const std::string& file, std::vector<Task*>& Tasks, std::vector<CustomerOrder>& CusOrders);

	//displays all the orders that were completed
	void displayCompleted(std::ostream& os) const;

	//validates each task on the assembly line
	void validateTasks() const;

	//performs one cycle of operations on the assembly line
	bool run(std::ostream& os);
};



#endif
