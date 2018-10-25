#include "maxheap.h"

int main() 
{ 
    MaxHeap<int>h; 
    for(int i=1;i<10;i++){
      h.recursive_insert(i);
      h.print(); 
    } 
    h.print();
    for(int i=1;i<5;i++){
      h.recursive_remove();
      h.print();
    }
    

    return 0; 
} 