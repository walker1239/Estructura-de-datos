#ifndef VPTREE_H
#define VPTREE_H
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <cmath>
#include <QPainter>
#include <QTimer>
using namespace std;

template <class D>
class vptree;

template <class D>
class node
{
    private:
        D data;
        node<D> * p_child[2];
        double radio;
        int x,y;
        double distancia;
        int id;

    public:
        node(int _x, int _y,const D & _data,int _id);
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
    float d(node<D>* p,node<D>* d);
    void insert(int x,int y, D data);
    //void insert(node<D> * point);
    node<D> * select_best(vector<node<D>* >point);
    void make_vptree(QPainter *q);
    node<D>* create_vptree(vector<node<D>* >point,QPainter *p);
    void search (int x,int y, int n, vector<node<D>*>result);
    void search (node<D>* tmp,int x,int y, int n, priority_queue<int> heap);
    float d(int x1,int x2, int y1, int y2){
      return sqrt(((x1 - x2)*(x1-x2)) + ((y1 - y2) * (y1 - y2)));
    }
};
template<class D>
node<D>::node(int _x, int _y,const D & _data,int _id){
  x=_x;
  y=_y;
  data=_data;
  p_child[1]=NULL;
  p_child[0]=NULL;
  radio=0;
  distancia=0;
  id=_id;
}
template<class D>
node<D>::~node(){

}

template<class D>
vptree<D>::vptree(){
  root=NULL;
}

template<class D>
float vptree<D>::d(node<D>* p,node<D>* d){
  return sqrt(((p->x - d->x)*(p->x-d->x)) + ((p->y - d->y) * (p->y - d->y)));
}
template<class D>
void vptree<D>::insert(int _x,int _y, D _data){
  node<D> *temp;
  temp=new node<D>(_x,_y,_data,points.size());
  points.push_back(temp);
}
template <class D>
void vptree<D>::search (int x,int y, int n, vector<node<D>* > result){
    priority_queue<int> heap;
    search(root,x,y,n,heap);

}
template <class D>
void vptree<D>::search (node<D>*root,int x,int y, int n, priority_queue<int> heap){}
template<class D>
node<D> *vptree<D>::select_best(vector<node<D>* >point){
  //cout<<point.size();
  int i;
  double mu=0;

  srand (time(0));

  if (point.size()==0)
  {
    return NULL;
  }
  if (point.size()==1) {
    i=0;
    point[i]->radio=3;
    return point[i];
  }
  else  i = rand() % (point.size()-1)+0;
  node<D>*new_root=point[i];
  for(int j=0;j<point.size();j++){
    if (i!=j){
      point[j]->distancia=d(new_root,point[j]);
      mu+=point[j]->distancia;
    }
  }

  new_root->radio=mu/(point.size()-1);
  return new_root;
}
template<class D>
void vptree<D>::make_vptree(QPainter *q){
  create_vptree(points,q);
  q->setPen("black");
  q->drawPoint(root->x,root->y);
  q->drawEllipse(root->x-(root->radio),root->y-(root->radio),2*root->radio,2*root->radio);
}
template<class D>
node<D> *vptree<D>::create_vptree(vector<node<D>* >point,QPainter *q){
  if(point.size()==0)
      return NULL;
  node<D>*temp;
  temp=select_best(point);
  vector<node<D>*>l;
  vector<node<D>*>r;
  for(int j=0;j<point.size();j++){
    if (temp==point[j])continue;
    if(temp->radio<=point[j]->distancia)
      r.push_back(point[j]);
    else
      l.push_back(point[j]);
  }
  q->drawEllipse(temp->x-(1),temp->y-(1),2,2);
  q->drawEllipse(temp->x-(temp->radio),temp->y-(temp->radio),2*temp->radio,2*temp->radio);
  if(root==NULL)
      root=temp;
  temp->p_child[0]=create_vptree(l,q);
  temp->p_child[1]=create_vptree(r,q);
  return temp;
}

#endif // VPTREE_H
