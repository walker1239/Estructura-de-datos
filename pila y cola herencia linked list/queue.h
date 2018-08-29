#ifndef QUEUE
#define QUEUE

#include <iostream>
#include "linked_list.h"
using namespace std;

template<class T>
class queue : public linked_list<T>
{
	private:
		node<T> * cola;
	public:
		queue();
		void push(const T & d);
		void remove();
};
#include "queue.inl"
#endif

