#include <vector>
#include <string>
#include <iostream>
#include "../header/manager.hpp"
#include "basic.cpp"
#include "taskList.cpp"
#include "IteratorByClass.cpp"
#include "IteratorByDate.cpp"
#include "IteratorByPriority.cpp"


void Manager::display() {
  	std::cout << "The following is a list of character inputs, followed by the corresponding command." << std::endl;
  	std::cout << "1 --> new task" << std::endl;
  	std::cout << "2 --> new task list" << std::endl;
  	std::cout << "3 --> new class" << std::endl;
	std::cout << "4 --> mark task or task list as complete" << std::endl;
	std::cout << "5 --> view classes" << std::endl;
	std::cout << "6 --> view task lists" << std::endl;
	std::cout << "7 --> view all tasks and task lists" << std::endl;
  	std::cout << "q --> quit Task Manager" << std::endl;
	std::cout << "Please enter one of the following characters: ";
}

void Manager::displayClasses() {
	for (auto c: classes) { std::cout << c << std::endl; }
}

void Manager::displayTaskLists() {
	for (auto t: tasks) {
		if (t->isTaskList()) {
			std::cout << t->print();
		}
	}
}

void Manager::makeIterator() {
	char iterType; 
	std::cout << "    Please select how you would like to view your upcoming tasks:" << std::endl;
	std::cout << "    d --> view by date" << std::endl;
	std::cout << "    c --> view by class" << std::endl;
	std::cout << "    p --> view by priority" << std::endl;
	std::cin >> iterType; 
	std::cin.ignore(100, '\n');
	if (iterType == 'd') { 
		IteratorByDate* iter = new IteratorByDate(this);	
		iter->printAll();
                delete iter;
	}
	else if (iterType == 'c') { 
		IteratorByClass* iter = new IteratorByClass(this);
  		iter->printAll();
                delete iter;
	}
  	else if (iterType == 'p') { 
    		IteratorByPriority* iter = new IteratorByPriority(this); 
  		iter->printAll();
                delete iter;
	}
	else {
		std::cout << "    Error: Invalid input.\n    Returning to main display:" << std::endl;
		return;
	} 	
}

void Manager::makeComplete() {
	std::string taskName;
	char isList;
	std::cout << "    Is the completed task within a task list?\n    Please enter 'y' if yes or any other character if no:";
	std::cin >> isList; 
	std::cin.ignore(100, '\n');
	if (isList == 'y') {
		std::string taskListName; 
		std::cout << "    Please enter the title of the task list:";
		std::getline(std::cin, taskListName);
		std::cout << "    Please enter the title of the task within the list that you've completed:";
		std::getline(std::cin, taskName); 
		for (auto a: tasks) {
			if (a->getTitle() == taskListName) {
				if (a->isTaskList()) {
          				Task* completed = a->GetTask(taskName);
                                	completed->isComplete();
                                	std::cout << "    " << taskName << " set as complete." << std::endl;
                                	return; 
				} 
				std::cout << "    Error: " << taskListName << "is not a task list.\n    Returning to main display:" << std::endl;
                                return;
			}
		}
		std::cout << "    Error: " << taskName << " not found within " << taskListName << ".\n    Returning to main display:" << std::endl; 
	}
	else {    
		std::cout << "    Please enter the title of the task or task list that you have completed:" << std::endl; 	
    		std::getline(std::cin, taskName);
		for (auto a: tasks) {
			if (a->getTitle() == taskName) {
				a->isComplete();
				std::cout << "    " << taskName << " set as complete." << std::endl;
        			return;
			}
		}
		std::cout << "    Error: " << taskName << "not found.\n    Returning to main display:" << std::endl;		
	}
}

void Manager::makeNewClass() {
	std::string new_c; 
	std::cout << "    Please enter the name of the new class: ";
	std::getline(std::cin,new_c);
	for (auto r: classes) {  //check if name already exists
		if (r == new_c) {
			std::cout << "    Error: Class already exists.\n    Returning to main display:" << std::endl;
		}
	}
	classes.push_back(new_c); 
}

Task* Manager::makeNewTask(bool is_list) {   //helper function for makeNewBasicTask and makeNewTaskList 
	std::string new_title; 
	char new_pri;
	std::vector<int> new_date;
	std::string new_class;
	std::string new_description;  
	if (is_list) { std::cout << "    Please enter the title of the new task list: "; }
	else { std::cout << "    Please enter the title of the new task: "; }
	std::getline(std::cin, new_title);
	std::cout << "    Please enter the priority of the new task (h --> high, m --> medium, l --> low): ";
  	std::cin >> new_pri;  
	std::cin.ignore(100, '\n');
  	while (!(new_pri == 'h' || new_pri == 'm' || new_pri == 'l')) {   //ensure proper priority char
		std::cout << "    Please enter a proper character for the corresponding priority (h --> high, m --> medium, l --> low): ";
		std::cin >> new_pri;
	}
	std::cout << "    Please enter the due date of the task by entering the month, day, and year with a space between each number: ";
	int arr[3];
	std::cin >> arr[0] >> arr[1] >> arr[2]; 
	std::cin.ignore(100, '\n'); 
	for (int i = 0; i < 3; ++i) { new_date.push_back(arr[i]); } 
	//std::cout << *new_date << " " << *(new_date+1) << " " << *(new_date+2) << std::endl;
  	bool isRealClass = false;
	std::cout << "    Please enter the lecture class associated with this task: "; 
	while (!isRealClass) {
		std::getline(std::cin, new_class);
		for (auto c: classes) {
			if (c == new_class) { isRealClass = true; }
		}
		if (!isRealClass) { 
			std::cout << "    The entered title is not a valid class. Please enter a valid lecture class: "; 
		}
	}
	std::cout << "    Finally, please enter a description for this task: "; 
	std::getline(std::cin, new_description);
	if (is_list) {  //make taskList
		TaskList* newL = new TaskList(new_title, new_pri, new_date, new_class, new_description); 
		return newL;
	}
	else {		//make basicTask
		BasicTask* newB = new BasicTask(new_title, new_pri, new_date, new_class, new_description); 
		return newB; 
	} 
}

void Manager::makeNewBasicTask() {
	Task* newTask = makeNewTask(false); 
	char isAddList;
	std::cout << "    Do you wish for this task to be added to an existing task list?\n    Please enter 'y' if yes or any other character if no: "; 
	std::cin >> isAddList; 
	std::cin.ignore(100, '\n');
	if (isAddList == 'y') {
		bool rightList = false;
		std::string listName; 
		while (!(rightList)) {
			std::cout << "    Please enter the title of the task list that this task will be added to: ";
			std::getline(std::cin, listName); 
			for (auto t: tasks) {
				if (t->getTitle() == listName) {
					t->AddTask(newTask);
					rightList = true; 
				}
			}
			if (!(rightList)) { 
				std::cout << "    Error: Incorrect task list. " << std::endl;
				std::cout << "    Would you like to try again? If no, the task will be added as a basic task. " << std::endl;
				std::cout << "    Please enter 'y' if yes or any other character if no: "; 
				char tryAgain; 
				std::cin >> tryAgain;
        			std::cin.ignore(100, '\n');
				if (tryAgain == 'y') {
					std::cout << "        Would you like to see a list of tasks?" << std::endl;
					std::cout << "        Please enter 'y' if yes or any other character if no: ";
                                	char seeClass;
                                	std::cin >> seeClass; 
					std::cin.ignore(100, '\n');
					if (seeClass == 'y') {
						this->displayTaskLists();
					} 
				}	
				else {
					tasks.push_back(newTask);
					rightList = true;
				}
			}
		}
	}
	else {
		tasks.push_back(newTask); 
	}
}

void Manager::makeNewTaskList() { 
	Task* newTask = makeNewTask(true);
	tasks.push_back(newTask);
}

//public

Manager::Manager() {}
Manager::~Manager() {
	while (!tasks.empty()) { tasks.pop_back(); }
}
void Manager::interface() {
	if (classes.empty()) {
		std::cout << "Since this is a new account, we will need to add a lecture class to get you started." << std::endl; 
		std::cout << "Please enter the name of a lecture class: ";
		std::string first_class;
		std::getline(std::cin, first_class); 
		classes.push_back(first_class);		
	}
	char input; 
 	this->display();	//call cout of all instructions 
 	std::cin >> input;
	std::cin.ignore(100, '\n');
 	while (input != 'q') {  		//while quit isn't called
		if (input == '7') {		//view ALL tasks
 			this->makeIterator(); 
		}
		else if (input == '1') {	//new task
			this->makeNewBasicTask();							
   		}
    		else if (input == '2') {	//new task list 
      			this->makeNewTaskList();	
    		}
		else if (input == '6') {	//view task lists
			this->displayTaskLists();
		}
                else if (input == '3') {        //new class
                         this->makeNewClass();
                }
		else if (input == '5') {        //view classes
                        this->displayClasses();
		}
                else if (input == '4') {        //mark complete
                        this->makeComplete();
                }
		else {
			std::cout << "Error: Invalid command input." << std::endl;
    		}
		this->display();
    		std::cin >> input;
		std::cin.ignore(100, '\n'); 
	}
}

