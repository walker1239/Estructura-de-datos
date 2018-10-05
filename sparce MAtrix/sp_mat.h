#ifndef SP_MAT_H
#define SP_MAT_H

#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

template <class T>
class sp_mat;

template <class T>
class node
{
    private:
        T value;
        unsigned int i,j;
        node<T>*p_next[2];
    
    public:
        node(unsigned int _i,unsigned int _j, const T& _value);
        ~node();
    friend class sp_mat<T>;
};



template <class T>
class sp_mat
{
    private:
        node<T> ** ptr_index[2];
    public:
        sp_mat(unsigned int m,unsigned int n);
        ~sp_mat();
        T& operator()(unsigned int _i, unsigned int _j);
        /*{
            if(_i>=(*ptr_index[0])->i or _j>=(*ptr_index[0])->i ) 
                throw;
            node<T> **n;
            insert(_i,_j,)
            return ;
        }*/
        T find(node<T>**&n,unsigned int _i, unsigned int _j,bool rotate);
        void insert(unsigned int _i,unsigned int _j, const T &_value);
        void print();
        //friend ostream& operator<<(ostream& os,const sp_mat<T> & s);
};
#include "sp_mat.inl"
#endif //SP_MAT