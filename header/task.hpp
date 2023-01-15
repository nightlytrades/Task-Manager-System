#ifndef __TASK_HPP__
#define __TASK_HPP__
#include <string>
#include <vector>


class Task {
protected:
	std::string title;
	char priority;
	std::vector<int> dueDate;
	std::string description;
	std::string LectureClass;
	bool complete;
public:
	Task(std::string new_title, char new_priority, std::vector<int> new_date, std::string new_lecture, std::string new_description) {
		complete = false;
		title = new_title;
		priority = new_priority;
		dueDate = new_date;
		LectureClass = new_lecture;
		description = new_description;
	}

	void isComplete() { complete = true; }
	
	std::string getTitle() { return title; }
	char getPriority() { return priority; }
	std::vector<int> getDueDate() { return dueDate; }
	std::string getDescription() { return description; }
	std::string getLectureClass() { return LectureClass; }
	bool getCompleteStatus() { return complete; }

	virtual std::string print() = 0;
	virtual bool isTaskList() = 0;
	virtual void AddTask(Task*) = 0; 
	virtual Task* GetTask(std::string) = 0;
};

#endif
