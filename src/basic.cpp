#include "../header/basic.hpp"
#include <iostream>
#include <string>
#include <vector>


std::string BasicTask::print() {

	std::string ss;
	ss = this->getTitle() + " " + this->getPriority() + " ";
	std::vector<int> due = this->getDueDate();
	for (int i = 0; i < 3; i++) {
		if (i == 1 || i == 2) { ss += "/"; }
		ss += std::to_string(due.at(i));
	}
	ss += " " + this->getLectureClass() + "\n - " + this->getDescription() + "\n";
	return ss;
	//std::cout << ss << std::endl;
}

