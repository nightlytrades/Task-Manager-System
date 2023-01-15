#ifndef __TASK_TESTS_HPP__
#define __TASK_TESTS_HPP__
#include "gtest/gtest.h"
#include <vector>

// ----BASIC TASK TESTS----------

TEST(BasicTaskTest, ConstructorTest){
	std::vector<int> date{3, 11, 2021};
	BasicTask* t1 = new BasicTask("Final project", 'H', date, "CS100", "Final project due");
	
	EXPECT_EQ("Final project due", t1->getDescription());
}

TEST(BasicTaskTest, CompleteTest){
	std::vector<int> date{3, 11, 2021};
        BasicTask* t1 = new BasicTask("Final project", 'H', date, "CS100", "Final project due");
	EXPECT_FALSE(t1->getCompleteStatus());
	t1->isComplete();
	EXPECT_TRUE(t1->getCompleteStatus());
}

TEST(BasicTaskTest, getTaskListTest){
        std::vector<int> date{3, 11, 2021};
        BasicTask* t1 = new BasicTask("Final project", 'H', date, "CS100", "Final project due");
        EXPECT_FALSE(t1->isTaskList());
                
}

TEST(BasicTaskTest, printTest) {
	std::vector<int> date{3, 11, 2021};
        BasicTask* t1 = new BasicTask("Final project", 'H', date, "CS100", "Final project due");
	EXPECT_EQ("Final project H 3/11/2021 CS100\n - Final project due\n", t1->print());
}

// ----TASKLIST TESTS-----------

TEST(TaskListTest, ConstructorTest){
	std::vector<int> date{3, 11, 2021};
	std::vector<int> date2{3, 7, 2021};
	TaskList* t1 = new TaskList("Final project", 'H', date, "CS100", "Final project due");
	TaskList* sub1 = new TaskList("OML", 'H', date2, "CS100", "Update OML diagram");
	
	EXPECT_EQ("Final project due", t1->getDescription());
	EXPECT_EQ("Update OML diagram", sub1->getDescription());
}

TEST(TaskListTest, PrintTest){
        std::vector<int> date{3, 11, 2021};
        std::vector<int> date2{3, 7, 2021};
	TaskList* t1 = new TaskList("Final project", 'H', date, "CS100", "Final project due");
	TaskList* sub1 = new TaskList("OML", 'H', date2, "CS100", "Update OML diagram");
        t1->AddTask(sub1);
        
	EXPECT_EQ("Final project H 3/11/2021 CS100\n - Final project due\n\tOML H 3/7/2021 CS100\n\t - Update OML diagram\n", t1->print());     
}

TEST(TaskListTest, MultipleSubTasksPrintTest){
        std::vector<int> date{3, 11, 2021};
        std::vector<int> date2{3, 7, 2021};
	std::vector<int> date3{3, 10, 2021};       
	TaskList* t1 = new TaskList("Final project", 'H', date, "CS100", "Final project due");
        TaskList* sub1 = new TaskList("OML", 'H', date2, "CS100", "Update OML diagram");
        t1->AddTask(sub1);
        TaskList* sub2 = new TaskList("ReadMe", 'H', date3, "CS100", "Update ReadMe");
        t1->AddTask(sub2);
	
        EXPECT_EQ("Final project H 3/11/2021 CS100\n - Final project due\n\tOML H 3/7/2021 CS100\n\t - Update OML diagram\n\tReadMe H 3/10/2021 CS100\n\t - Update ReadMe\n", t1->print());
}


#endif
