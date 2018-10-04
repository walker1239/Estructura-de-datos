#include "redblack.h"
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int main(){
    
    redblack<int,int> avl;

    int iSecret, jSecret;
    srand (time(NULL));

    for(int i=1;i<30;i++){
        iSecret = rand() % 30 + 1;
        avl.insert(i,1);
            cout<<"Se inserto "<<iSecret<<endl;
            avl.printARBOL(iSecret);
    }
       

	return 0;
}