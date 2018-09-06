#include"linked_list.h"
#include<iostream>
using namespace std;
int main(){
    linked_list<int> * s=new linked_list<int>();
    s->insert(1);
    s->insert(2);
    s->insert(3);
    s->insert(4);
    s->insert(5);
    s->insert(6);
    s->print();
    linked_list<int> * z=new linked_list<int>();
    z=s;
    z->insert(109);
    
    cout<<endl<<endl;
    z->print();
    cout<<endl;
    s->print();
    s->insert(9);
    z->print();
    cout<<endl;
    s->print();
    z->insert(10);
    s->remove(4);
    s->remove(2);
    s->print();
    s->insert(11);
    s->insert(12);
    s->insert(92);

    return 0;
}