#ifndef __BASIC_HPP__
#define __BASIC_HPP__
#include "task.hpp"
#include <string>
#include <vector>

class BasicTask : public Task {

public:
	BasicTask(std::string new_title, char new_priority, std::vector<int> new_date, std::string new_lecture, std::string new_description)
		: Task(new_title, new_priority, new_date, new_lecture, new_description){} 
	virtual std::string print();
	virtual bool isTaskList() { return false; }
	virtual void AddTask(Task* to_add) { }
        virtual Task* GetTask(std::string name) { return nullptr; } 
};

#endif
