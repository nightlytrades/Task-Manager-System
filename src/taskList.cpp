#include "../header/taskList.hpp"
#include <iostream>
#include <vector>

void TaskList::AddTask(Task* to_add) {
	list.push_back(to_add);
}


Task* TaskList::GetTask(std::string name) {
	for(int i = 0; i < list.size(); i++){
		if(list.at(i)->getTitle() == name)
			return list.at(i);
	}
}

std::string TaskList::print() { 
	std::string ss;
	ss = this->getTitle() + " " + this->getPriority() + " ";
	std::vector<int> due = this->getDueDate();
	for (int i = 0; i < 3; i++) {
		if (i == 1 || i == 2) { ss += "/"; }
		ss += std::to_string(due.at(i));
	}
	ss += " " + this->getLectureClass() + "\n - " + this->getDescription();

	ss += "\n\t";

	for (int i = 0; i < list.size(); i++) {	
		ss += list[i]->getTitle() + " " + list[i]->getPriority() + " ";
		std::vector<int> date1 = list.at(i)->getDueDate();
		for (int i = 0; i < 3; i++) {
			if (i == 1 || i == 2) { ss += "/"; }
			ss += std::to_string(date1.at(i));
		}
		ss += " " + this->getLectureClass() + "\n\t - " + list[i]->getDescription() + "\n";
		if (i != list.size() - 1) {
			ss += "\t";
		}
	}
	return ss;
}
