#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__
//#include manager.hpp

#include <vector>
#include "task.hpp"

class Iterator {

protected: 
	std::vector<Task*> sortedTasks;
public:
	virtual void printAll() = 0;
	std::vector<Task*> getSorted() { return sortedTasks; }
};


#endif 
