#include "../header/IteratorByPriority.hpp"
#include <vector>
#include <string>
#include <iostream>

IteratorByPriority::IteratorByPriority(Manager* mana) {
    std::vector<Task*> unsorted = mana->getTasks();
    for (auto u: unsorted) {
        if (u->getPriority() == 'h') {
            sortedTasks.push_back(u);
        }
    }
    for (auto u: unsorted) {
        if (u->getPriority() == 'm') {
            sortedTasks.push_back(u);
        }
    }
    for (auto u: unsorted) {
        if (u->getPriority() == 'l') {
            sortedTasks.push_back(u);
        }
    }
}
void IteratorByPriority::printAll() {
    for (auto s: sortedTasks) {
        if (!(s->getCompleteStatus())) {
                std::cout << s->print();
        }
    }
}
