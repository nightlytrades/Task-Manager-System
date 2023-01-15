#ifndef __ITERATORBYDATE_HPP__
#define __ITERATORBYDATE_HPP__
#include "iterator.hpp"
#include "manager.hpp"

class IteratorByDate : public Iterator
{
public: 
	IteratorByDate(Manager* mana);
	void printAll();
};


#endif
