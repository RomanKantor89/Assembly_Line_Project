// Project - Ms3
// Name: Roman Kantor
// Seneca Student ID: 159379171
// Seneca email: Rvindalovski@myseneca.ca
// Date of completion:Nov 25, 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#include<fstream>
#include "LineManager.h"

//custom constructor
LineManager::LineManager(const std::string& file, std::vector<Task*>& Tasks, std::vector<CustomerOrder>& CusOrders) {

	m_cntCustomerOrder = 0;
	//read the file and setup NextTask references in the Task objects Linking each Task Object together 
	std::string fileRec;
	std::ifstream fName(file);
	Utilities utiObj;
	std::string nextTask;
	std::string curTask;
	size_t CurNum;


	if (fName) {
		
		while (getline(fName, fileRec))
		{
			bool check = true;
			size_t pos = 0;

			curTask = utiObj.extractToken(fileRec, pos, check);

			if(check)
				nextTask = utiObj.extractToken(fileRec, pos, check);

			for (size_t i = 0; i < Tasks.size(); ++i) {

				if (Tasks[i]->getName() == curTask) {

					CurNum = i;
				}
			}


			if (!nextTask.empty()) {

				for (size_t i = 0; i < Tasks.size(); ++i) {

					if (Tasks[i]->getName() == nextTask) {

						Tasks[CurNum]->setNextTask(*Tasks[i]);

						nextTask = "";
						break;
					}
				}
			}
		}
	}

	//move all customerOrder objects into the front of the ToBeFilled
	for (auto &order : CusOrders) 
		ToBeFilled.push_back(std::move(order));
	

	//copy all the Task objects into the AssemblyLine container
	for (auto task : Tasks) 
		AssemblyLine.push_back(task);

}

//performs one cycle of operations on the assembly line
bool LineManager::run(std::ostream& os) {
	bool check = false;
	
	if (!ToBeFilled.empty()) {

			*AssemblyLine[4] += std::move(ToBeFilled.front());
			ToBeFilled.pop_front();
			m_cntCustomerOrder++;
	}

	for (auto task : AssemblyLine)
		task->runProcess(os);

	
	for (size_t i = 0; i < AssemblyLine.size(); ++i) {

		if (AssemblyLine[i]->moveTask()) {

			CustomerOrder cusOrd;
			if (AssemblyLine[i]->getName() == "SSD") {
				if (AssemblyLine[i]->getCompleted(cusOrd)) {

					Completed.push_back(std::move(cusOrd));
				}
			}
		}
	}
	
	
	if(Completed.size() == m_cntCustomerOrder)
		check = true;
	

	return check;

}

//displays all the orders that were completed
void LineManager::displayCompleted(std::ostream& os) const {

	for (size_t i = 0; i < Completed.size(); ++i) {

		Completed[i].display(os);
	}
}

//validates each task on the assembly line
void LineManager::validateTasks() const {

	for (size_t i = 0; i < AssemblyLine.size(); ++i) {

		AssemblyLine[i]->validate(std::cout); 
	}
}



