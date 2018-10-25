#ifndef MAXHEAP
#define MAXHEAP 

#include<iostream>  
using namespace std; 
  
template<class T,size_t _cap=100>
class MaxHeap 
{ 
    T*arr;
    size_t cap;
    int n;
  public:

    MaxHeap(){ 
      n=0; 
      cap=_cap;
      arr = new T[cap]; 
    }

    int parent(int i){ 
      return (i-1)/2; 
    }

    int left(int i){ 
      return (2*i + 1); 
    }

    int right(int i){
      return (2*i + 2); 
    } 

    int getMax(){ 
      return arr[0]; 
    } 
    
    void insertKey(T k){ 
      if (n==cap) 
      { 
        return; 
      } 
      int i=n; 
      n++; 
      arr[i] = k;  
      up(i);
    }

    void up(int i){
      while (i != 0 && arr[parent(i)] < arr[i]) 
      { 
        swap(&arr[i], &arr[parent(i)]); 
        i = parent(i); 
      } 
    }

    void down(int i){
      while (i<n) 
      { 

        bool a=arr[right(i)]>arr[left(i)]; 
        if(a and n>right(i)){
          swap(&arr[i],&arr[right(i)]);
          i=right(i);
        }
        else if(!a and n>left(i)){
          swap(&arr[i],&arr[left(i)]);
          i=left(i);
        }
        else{
          break;
        }
      } 
    }

    void remove(){
      if (n==0){
        return;
      }
      n--;
      swap(&arr[0],&arr[n]);
      down(0);
    }

    void swap(T *x, T *y){ 
      T temp = *x; 
      *x = *y; 
      *y = temp; 
    } 

    void print(){
      for(int i=0;i<n;i++){
        cout<<arr[i]<<',';
      }
      cout<<endl;
    }
    void recursive_remove(){
      if (n==0){
        return;
      }
      n--;
      swap(&arr[0],&arr[n]);
      recursiver(0);
    }
    void recursiver(int i) 
    { 
      int l = left(i); 
      int r = right(i); 
      int max = i; 
      if (l<n && arr[l] > arr[i]) 
          max = l; 
      if (r<n && arr[r] > arr[max]) 
          max = r; 
      if (max != i) 
      { 
          swap(&arr[i], &arr[max]); 
          recursiver(max); 
      } 
    } 

    void recursive_insert(T k){ 
      if (n==cap) 
      { 
        return; 
      } 
      int i=n; 
      n++; 
      arr[i] = k;  
      recursivei(i);
    }

    void recursivei(int i) 
    { 
      if (i != 0 && arr[parent(i)]<arr[i]) 
      { 
          swap(&arr[i], &arr[parent(i)]); 
          recursivei(parent(i)); 
      } 
    } 
}; 

#endif