#ifndef VPTREE_H
#define VPTREE_H
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <cmath>
#include <limits>
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
        int index;

    public:
        node(int _x, int _y,const D & _data,int i);
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
    void search (int x,int y, int n,QPainter *q);
    void search (node<D>* tmp,node<D>* query, int n, priority_queue<pair<double, int>> &heap);
};

template<class D>
node<D>::node(int _x, int _y,const D & _data, int i){
  x=_x;
  y=_y;
  data=_data;
  p_child[1]=NULL;
  p_child[0]=NULL;
  radio=0;
  distancia=0;
  index=i;
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
void vptree<D>::search (int x,int y, int n, QPainter *q){
    cout<<5;
    priority_queue<pair<double,int> > heap;
    cout<<6;
    node<D>*query=new node<D>(x,y,root->data,0);
    query->distancia=std::numeric_limits<double>::max();
    cout<<3;
    search(root,query,n,heap);
    q->setPen("red");
    while( !heap.empty() ) {
        cout<<"a";
                q->drawEllipse(points[heap.top().second]->x-(2),points[heap.top().second]->y-(2),4,4);
                heap.pop();
            }
}
template <class D>
void vptree<D>::search (node<D>*tmp,node<D>* query, int n, priority_queue<pair<double,int>> &heap){
    if(tmp==NULL) return;
        cout<<2;
        double dis=d(tmp,query);
        if(dis<query->distancia){
            if(heap.size()==n) heap.pop();

            heap.push(make_pair(dis,tmp->index));
                          cout<<3;

            if(heap.size()==n) {
                query->distancia=heap.top().first;
            }
        }

        if (tmp->p_child[0]==NULL and tmp->p_child[1]==NULL) return;
        if ( dis < tmp->radio) {
                    if ( dis - query->distancia <= tmp->radio ) {
                        search( tmp->p_child[0], query, n, heap );
                    }

                    if ( dis + query->distancia >= tmp->radio ) {
                        search( tmp->p_child[1], query, n, heap );
                    }

                } else {
                    if ( dis + query->distancia >= tmp->radio ) {
                        search( tmp->p_child[1], query, n, heap );
                    }
                    if ( dis - query->distancia <= tmp->radio ) {
                        search( tmp->p_child[0], query, n, heap );
                    }


                }



    }
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
  q->setPen("white");
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
  q->drawEllipse(temp->x-(0.5),temp->y-(0.5),1,1);
  q->drawEllipse(temp->x-(temp->radio),temp->y-(temp->radio),2*temp->radio,2*temp->radio);
  if(root==NULL)
      root=temp;
  temp->p_child[0]=create_vptree(l,q);
  temp->p_child[1]=create_vptree(r,q);
  return temp;
}

#endif // VPTREE_H
