#ifndef __ITER_TESTS_HPP__
#define __ITER_TESTS_HPP__
#include "gtest/gtest.h"
#include <vector>
#include <string>

TEST(IterByPriority, SortedTest){ 
	Manager* man = new Manager();
	std::vector<Task*> tasks;
	std::vector<std::string> classes;  
	std::vector<int> ptr1{9, 25, 2021};
        std::vector<int> ptr2{8, 10, 2021};
	std::vector<int> ptr3{6, 20, 2021};
	BasicTask* task1 = new BasicTask("task1", 'm', ptr1, "CS100", "Placeholder text");
	BasicTask* task2 = new BasicTask("task2", 'l', ptr2, "CS100", "Placeholder text");
	BasicTask* task3 = new BasicTask("task3", 'h', ptr3, "CS100", "Placeholder text");
	tasks.push_back(task1);
	tasks.push_back(task2); 
	tasks.push_back(task3);
	classes.push_back("CS100");
	man->setTasks(tasks);
	man->setClasses(classes);
	IteratorByPriority* iter = new IteratorByPriority(man);
	std::vector<Task*> answer;
	answer.push_back(task3);
	answer.push_back(task1);
	answer.push_back(task2);
	EXPECT_EQ(answer, iter->getSorted());
}

TEST(IterByClass, SortedTest){
        Manager* man = new Manager();
        std::vector<Task*> tasks;
        std::vector<std::string> classes;
        std::vector<int> ptr1{9, 25, 2021};
        std::vector<int> ptr2{8, 10, 2021};
        std::vector<int> ptr3{6, 20, 2021};
        BasicTask* task1 = new BasicTask("task1", 'm', ptr1, "CS100", "Placeholder text");
        BasicTask* task2 = new BasicTask("task2", 'm', ptr2, "CS104", "Placeholder text");
        BasicTask* task3 = new BasicTask("task3", 'm', ptr3, "CS102", "Placeholder text");
        tasks.push_back(task1);
        tasks.push_back(task2);
        tasks.push_back(task3);
        classes.push_back("CS102");
	classes.push_back("CS100");
	classes.push_back("CS104");
        man->setTasks(tasks);
        man->setClasses(classes);
        IteratorByClass* iter = new IteratorByClass(man);
        std::vector<Task*> answer;
        answer.push_back(task3);
        answer.push_back(task1);
        answer.push_back(task2);
        EXPECT_EQ(answer, iter->getSorted());
}

TEST(IterByDate, SortedTest){
        Manager* man = new Manager();
        std::vector<Task*> tasks;
        std::vector<std::string> classes;
        std::vector<int> ptr1{9, 25, 2021};
        std::vector<int> ptr2{8, 10, 2021};
        std::vector<int> ptr3{6, 20, 2021};
        BasicTask* task1 = new BasicTask("task1", 'm', ptr1, "CS100", "Placeholder text");
        BasicTask* task2 = new BasicTask("task2", 'l', ptr2, "CS100", "Placeholder text");
        BasicTask* task3 = new BasicTask("task3", 'h', ptr3, "CS100", "Placeholder text");
        tasks.push_back(task1);
        tasks.push_back(task2);
        tasks.push_back(task3);
        classes.push_back("CS100");
        man->setTasks(tasks);
        man->setClasses(classes);
        IteratorByDate* iter = new IteratorByDate(man);
        std::vector<Task*> answer;
        answer.push_back(task3);
        answer.push_back(task2);
        answer.push_back(task1);
        EXPECT_EQ(answer, iter->getSorted());
}

#endif
