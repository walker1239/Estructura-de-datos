#include"queue.h"
#include "stack.h"
#include<iostream>
using namespace std;
int main(){
    cout<<"queue"<<endl;
    queue<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.getFirstDato()<<endl;
    cout<<s.getLastDato()<<endl;
    s.print();
    s.remove();
    s.remove();
    s.print();
    cout<<"stack"<<endl;
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.print();
    st.remove();
    st.print();

    return 0;
}