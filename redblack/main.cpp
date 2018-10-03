#include "redblack.h"
int main()
{
	redblack<int,int> avl;


    for(int i=1;i<11;i++){
        avl.insert(i,1);  
        avl.printARBOL(i);

    }
    avl.del(8);
    avl.del(4);
    avl.del(6);
    avl.printARBOL(11);
	return 0;
}