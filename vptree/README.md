Vantage point tree
=========

![](https://github.com/walker1239/Estructura-de-datos/blob/master/vptree/img/points.PNG "points")
![](https://github.com/walker1239/Estructura-de-datos/blob/master/vptree/img/vptree.png "vp tree")

## Description
Vp tree implemented in c++. Qt creator is used in order to demonstrate how the code works.The vp tree are binary space partition trees that divide points according to the circle they form with respect to the radius. Those who are inside are the left children and those who are outside are the right children. So recursively until there are no points.

## Build and Run

### Compilation instruction:

	double click on vptreee.pro
  click in configure project

### Finally execute:

	press Ctrl + r

## Struct of the nodes
```c++
template <class D>
class node
{
    private:
        D data;
        node<D> * p_child[2];
        double radio;
        int x,y;
        double distancia;
        int index;

    public:
        node(int _x, int _y,const D & _data,int i);
        virtual ~node();

    friend class vptree<D>;
};
```

## Struct of the vp tree

```c++
template <class D>
class vptree
{
private:
    node<D>*root;
    vector<node<D> * > points;
    node<D> * select_best(vector<node<D>* >point);
    node<D>* create_vptree(vector<node<D>* >point,QPainter *p);
    void search (node<D>* tmp,node<D>* query, int n, priority_queue<pair<double, int>> &heap);
    float d(node<D>* p,node<D>* d);

public:
    vptree();
    void insert(int x,int y, D data);
    //void insert(node<D> * point);
    void make_vptree(QPainter *q);
    void search (int x,int y, int n,QPainter *q);
    void print_points(QPainter * p);
    void clear();
};
```
## Distance
  - Basic euclidean distance
## Search
  - (O(log(n)))
  ![](https://github.com/walker1239/Estructura-de-datos/blob/master/vptree/img/search.png "search")
### Implementation and theory
Part of the implementation of search and the theory for the basic guide of the code was from the article: [Dynamic vp-Tree Indexing for n-Nearest Neighbor Search Given PairWise Distances](https://www.researchgate.net/publication/243134425_Dynamic_vp-Tree_Indexing_for_n-Nearest_Neighbor_Search_Given_PairWise_Distances) for more details.
Part of the implementation of insert and the theory for the basic guide of the code was from the article: [Data Structures and Algorithms for Nearest Neighbor Search in General Metric Spaces](https://www.researchgate.net/publication/2596667_Data_Structures_and_Algorithms_for_Nearest_Neighbor_Search_in_General_Metric_Spaces) for more details.
## Authors
- [Walker Fernando Manrique Chalco](https://github.com/walker1239)
