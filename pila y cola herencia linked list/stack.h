#ifndef STACK
#define STACK

#include <iostream>
#include "linked_list.h"
using namespace std;

template<class T>
class stack : public linked_list<T>
{
	public:
		stack();
		void push(const T & d);
		void remove();
};
#include "stack.inl"
#endif

