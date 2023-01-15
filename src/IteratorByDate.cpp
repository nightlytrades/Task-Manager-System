#include "../header/IteratorByDate.hpp"
#include <vector>
#include <string>
#include <iostream>

IteratorByDate::IteratorByDate(Manager* mana) {
    std::vector<Task*> unsorted = mana->getTasks();  
    //find smallest date in unsorted (initially the first value) 
    //sortedTasks.push_back(min), remove min from unsorted 
    //repeat until unsorted is empty
    while (!unsorted.empty()) {
        Task* minTask = unsorted.at(0); 
        for (auto currTask: unsorted) {                //0->month, 1->day, 2->year
            std::vector<int> currDate = currTask->getDueDate();        
            std::vector<int> minDate = minTask->getDueDate();
            if (currDate.at(2) < minDate.at(2)) {              
                minTask = currTask; 
            }
            else if ((currDate.at(2) == minDate.at(2)) && (currDate.at(0) < minDate.at(0))) {   
                minTask = currTask; 
            }
            else if ((currDate.at(2) == minDate.at(2)) && (currDate.at(0) == minDate.at(0)) && (currDate.at(0) < minDate.at(0))) {
                minTask = currTask; 
            }
            else { }
        }
        sortedTasks.push_back(minTask);
        for (int i = 0; i < unsorted.size(); ++i) {
            if (unsorted.at(i) == minTask) {
                unsorted.erase(unsorted.begin() + i); 
            }
        }
    }
}
void IteratorByDate::printAll() {
    for (auto s: sortedTasks) {
        if (!(s->getCompleteStatus())) {
                std::cout << s->print();
        }
    }
}
