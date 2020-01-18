// Project - Ms3
// Name: Roman Kantor
// Seneca Student ID: 159379171
// Seneca email: Rvindalovski@myseneca.ca
// Date of completion: Nov 25, 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include "Task.h"

Task::Task(const std::string& record) : Item::Item(record) {

	m_pNextTask = nullptr;
}

// runs a single cycle of the assembly line for the current task.
void Task::runProcess(std::ostream& os) {
	
	if (!m_orders.empty()) {

		size_t orderSize = m_orders.size();

		for (size_t i = 0; i < orderSize; ++i) {

			while(!(m_orders.back().getItemFillState(this->getName()))) 
			{
				m_orders.back().fillItem(*this, os);
			}
		}
	}
}

//moves the most recent CustomerOrder in the queue to the next task on the assembly line 
bool Task::moveTask() {

	if (!m_orders.empty()) {

		if (m_orders.front().getItemFillState(this->getName())) {
			
			if (m_pNextTask) {
				m_pNextTask->m_orders.push_back(std::move(m_orders.front()));
				m_orders.pop_front();
			}
		}
	}
	
	return !m_orders.empty();
}

//stores the provided Task object’s reference into the m_pNextTask pointer.
void Task::setNextTask(Task& task) {
	m_pNextTask = &task;
}

//Removes the last CustomerOrder from the queue, places it in the parameter and returns true. 
//If the CustomerOrder queue is empty, return false.
bool Task::getCompleted(CustomerOrder& CusOrder) {

	bool check = false;

	if (!m_orders.empty()) {

		if (m_orders.front().getItemFillState(this->getName())) {

			CusOrder = std::move(m_orders.front());
			m_orders.pop_front();
			check = true;
		}
	}

	return check;
}


void Task::validate(std::ostream& os) {

	if (m_pNextTask != nullptr) {

		os << this->getName() << " --> " << m_pNextTask->getName() << std::endl;
	}
	else {
		os << this->getName() << " --> END OF LINE" << std::endl;
	}
}

//Moves the parameter onto the front of the CustomerOrder queue
Task& Task::operator+=(CustomerOrder&& src) {

	m_orders.push_front(std::move(src));
	return *this;
}