#include "bst.h"
int main(){
	bst<int, float> tree;
	tree.insert(41, .43);
	tree.insert(20, .5454);
	tree.insert(65, .23);
	tree.insert(50, .4542);
	tree.insert(91, 43.5454);
	tree.insert(72, 3.23);
	tree.insert(99, 321.32);
	tree.print();
}