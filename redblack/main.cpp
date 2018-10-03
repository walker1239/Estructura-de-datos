#include "redblack.h"
int main()
{
	redblack<int,int> avl;


    for(int i=1;i<11;i++){
        avl.insert(i,1);  
        avl.printARBOL(i);

    }
	return 0;
}