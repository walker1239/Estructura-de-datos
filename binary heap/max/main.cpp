#include "maxheap.h"

int main() 
{ 
    MaxHeap<int>h; 
    for(int i=1;i<10;i++){
      h.recursive_insert(i);
    } 
    h.print();
    for(int i=1;i<5;i++){
      h.recursive_remove();
    }
    h.print();

    int arr[] = {5,4,3,7,6,8,1,3,6,26,1,6,7,1,35}; 

    h.convert(arr,15);
    h.heapSort();
    h.print();


    return 0; 
} 