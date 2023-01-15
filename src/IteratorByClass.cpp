#include "../header/IteratorByClass.hpp"
#include <vector>
#include <string>
#include <iostream>

IteratorByClass::IteratorByClass(Manager* mana) {
		std::vector<Task*> unsorted = mana->getTasks();
		std::vector<std::string> lectures = mana->getClasses();
		for (auto c: lectures) {
			for (auto u: unsorted) {
				if (u->getLectureClass() == c) {
                    sortedTasks.push_back(u);
                }
            }
	  }
}
void IteratorByClass::printAll() {
    for (auto s: sortedTasks) {
	if (!(s->getCompleteStatus())) {
		std::cout << s->print();
    	}
    }
}
