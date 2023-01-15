#ifndef __ITERATORBYCLASS_HPP__
#define __ITERATORBYCLASS_HPP__
#include "iterator.hpp"
#include "manager.hpp"

class IteratorByClass : public Iterator
{
public: 
	IteratorByClass(Manager* mana);
	void printAll();
};

#endif 
