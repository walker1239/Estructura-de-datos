#include "avl.h"
int main()
{
	avl<int,int> avl;


    for(int i=1;i<7;i++){
        avl.insert(i,1);  
        avl.printOficial(i);

    }

    for(int i=1;i<7;i++){
        avl.remove(i);
        avl.printOficial(i);
    }


	return 0;
}