#ifndef VPTREE_H
#define VPTREE_H
#include <iostream>
#include <vector>

using namespace std;

template <class D>
class vptree;

template <class D>
class node
{
    private:
        D data;
        vector<node<D> *> p_child[2];
        int radio;
        int x,y;

    public:
        node(const D & _data, int _radio);
        virtual ~node();

    friend class vptree<D>;
};

template <class D>
class vptree
{
private:
    node<D>*root;
public:
    vptree();
};

#endif // VPTREE_H
