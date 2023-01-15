#ifndef __ITERATORBYPRIORITY_HPP__
#define __ITERATORBYPRIORITY_HPP__
#include "iterator.hpp"
#include "manager.hpp"

class IteratorByPriority : public Iterator
{
public: 
	IteratorByPriority(Manager* mana);
	void printAll();
};

#endif
