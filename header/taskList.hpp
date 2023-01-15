#ifndef __TASKLIST_HPP__
#define __TASKLIST_HPP__
#include "task.hpp"	

class TaskList : public Task
{
private:
	std::vector<Task*> list;

public:
	TaskList(std::string new_title, char new_priority, std::vector<int> new_date, std::string new_lecture, std::string new_description)
		: Task(new_title, new_priority, new_date, new_lecture, new_description) {}
	

	void AddTask(Task* to_add);
	Task* GetTask(std::string name);

	virtual std::string print();
	virtual bool isTaskList() { return true; }
};

#endif
