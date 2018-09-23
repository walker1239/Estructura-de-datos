#include "avl.h"
int main()
{
	avl<int, int> s;
	s.insert(1,2);s.print();
	s.insert(2,3);s.print();
	s.insert(3,2);s.print();
	s.insert(4,3);s.print();
	s.insert(5,2);s.print();
	s.insert(6,3);s.print();
	return 0;
}