#include "bt.h"
int main()
{
	bh<int> b;
	cout<<'a';
	b.insert(5);
	cout<<'a';
	b.insert(15);
	cout<<'b';
	b.insert(25);
	cout<<'a';
	b.getMin();
	b.insert(35);
	b.insert(45);
	cout<<'a';
	b.print();
	return 0;
}