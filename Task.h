// Project - Ms3
// Name: Roman Kantor
// Seneca Student ID: 159379171
// Seneca email: Rvindalovski@myseneca.ca
// Date of completion: Nov 25, 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#include<deque>
#include"CustomerOrder.h"
#include"Item.h"

#ifndef TASK_H
#define TASK_H

class Task : public Item {

	std::deque<CustomerOrder> m_orders;
	Task* m_pNextTask;

public:
	//custom constructor
	Task(const std::string& record);

	//Preventing moving and copying
	Task(const CustomerOrder&) = delete;
	Task& operator=(const CustomerOrder&) = delete;
	Task(CustomerOrder&&) = delete;
	Task& operator=(CustomerOrder&&) = delete;

	// runs a single cycle of the assembly line for the current task.
	void runProcess(std::ostream& os);

	//moves the last CustomerOrder in the queue to the next task on the assembly line 
	bool moveTask();

	//stores the provided Task object’s reference into the m_pNextTask pointer.
	void setNextTask(Task& task);

	//Removes the last CustomerOrder from the queue, places it in the parameter and returns true. 
	//If the CustomerOrder queue is empty, return false.
	bool getCompleted(CustomerOrder& CusOrder);


	void validate(std::ostream& os);

	//Moves the parameter onto the front of the CustomerOrder queue
	Task& operator+=(CustomerOrder&& src);


};





#endif