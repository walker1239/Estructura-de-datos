#include "minheap.h"
int main() 
{ 
    MinHeap<int>h; 
    for(int i=1;i<10;i++){
      h.recursive_insert(i); 
    } 
    h.recursive_insert(100);
    h.recursive_insert(30);
    h.recursive_insert(4);
    h.recursive_insert(8);
    h.recursive_insert(300);
    h.recursive_insert(55);
    h.recursive_insert(132);
    h.print();
    for(int i=1;i<5;i++){
      h.recursive_remove();
      h.print();
    }
    

    return 0; 
} 