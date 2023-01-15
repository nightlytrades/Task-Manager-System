#ifndef __MANAGER_HPP__
#define __MANAGER_HPP__

#include <vector>
#include <string>
#include "basic.hpp"
#include "taskList.hpp"

class Manager {
private:
    std::vector<Task*> tasks;		//vector of both BasicTask and TaskList objects
    std::vector<std::string> classes; 	//vector of class names
    void display();
    void displayClasses();
    void displayTaskLists();
    void makeIterator();
    void makeComplete();
    void makeNewClass();
    Task* makeNewTask(bool is_list); //helper for makeNewBasicTask() and makeNewTaskList()
    void makeNewBasicTask();
    void makeNewTaskList();
public:
	Manager(); 
	~Manager();
	void interface();
	std::vector<Task*> getTasks() { return tasks; }
	std::vector<std::string> getClasses() { return classes; }
	void setTasks(std::vector<Task*> tks) { tasks = tks; }
	void setClasses(std::vector<std::string> cls) { classes = cls; }
};

#endif
