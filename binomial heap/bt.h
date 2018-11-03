#ifndef BT
#define BT 

#include<iostream>  
#include<vector>
#include <cstring>
#include <fstream>

using namespace std; 

template<class T,size_t tam=64>
class bh;
  
template<class T>
class bt
{
private:
	T dato;
	vector<bt<T>*>child;
	int cant;
public:
	bt(const T _dato){
		dato=_dato;
	}
	~bt();
	void print(ostream & os){
		os<<"p"<<this<<" [label=\""<<dato<<"\"]"<<endl;
		for(bt<T>*p:child){
			p->print(os);
			os<<"p"<<this<<" -> p"<<p<<endl;
		}
	}
  void print1(){
		cout<<"p"<<dato<<endl;
		for(bt<T>*p:child){
			p->print1();
		}
  }
	friend class bh<T>;
};
template<class T,size_t tam>
class bh
{
private:
	bt<T>* trees[tam];
public:
	bh(){
		memset(trees,0,sizeof(trees));
	}
	~bh(){

	}
	bt<T>* unir(bt<T>* t1,bt<T>* t2){
		if(t1->dato>t2->dato){
			t2->child.push_back(t1);
			return t2;
		}	
		t1->child.push_back(t2);
		return t1;
	}  
	void insert(const T & d){
		insert(new bt<T>(d));
	}
	void insert(bt<T> * b){
		int i = b->child.size();
		if(trees[i]==NULL){
			trees[i]=b;
			return;
		}
		insert(unir(trees[i],b));
		trees[i]=NULL;
	}
  bt<T>* getMin() 
  { 
    bt<T>* t;
    bool c=1;
    for(int i=0;i<tam;i++){
      if(trees[i]){
      	if(c){
      		t=trees[i];
      	}
      	
        if (trees[i]->dato<t->dato)
        {
        	t=trees[i];
        }
      c=0;
	  }
	}
    
    return t;
  } 
  void remove(){  
    bt<T>* heap,lo,temp,it; 

    // temp contains the pointer of minimum value 
    // element in heap 
    temp = getMin(); 
    for (int i = 0; i < tam; ++i)
    {
    	if(!trees[i]){
    		trees[i]=temp;
    	}
    	else
    		unir(trees[i],temp);
    }
    delete temp;
  }
	
	void print(){
		ofstream os("binh.dot");
		os<<"digraph bh{ "<<endl;
		for(int i=0; i<sizeof(trees); i++){
			if(trees[i]) trees[i]->print(os);
		}
		os<<"}"<<endl;
		os.close();
	}
};
#endif
