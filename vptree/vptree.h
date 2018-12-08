#ifndef VPTREE_H
#define VPTREE_H
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using namespace std;

template <class D>
class vptree;

template <class D>
class node
{
    private:
        D data;
        node<D> * p_child[2];
        int radio;
        int x,y;
        int distancia;

    public:
        node(int _x, int _y,const D & _data);
        virtual ~node();

    friend class vptree<D>;
};

template <class D>
class vptree
{
private:
    node<D>*root;
    vector<node<D> * > points;
public:
    vptree();
    int d(node<D>* p,node<D>* d);
    void insert(int x,int y, D data);
    //void insert(node<D> * point);
    node<D> * select_best(vector<node<D>* >point);
    void make_vptree();
    node<D>* create_vptree(vector<node<D>* >point);
};
#endif // VPTREE_H
