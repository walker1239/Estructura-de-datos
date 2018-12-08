#include "vptree.h"
template<class D>
node<D>::node(int _x, int _y,const D & _data){
  x=_x;
  y=_y;
  data=_data;
  p_child[1]=NULL;
  p_child[0]=NULL;
  radio=0;
  distancia=0;
}
template<class D>
node<D>::~node(){

}

template<class D>
vptree<D>::vptree(){
  root=NULL;
}
template<class D>
int vptree<D>::d(node<D>* p,node<D>* d){
  return sqrt(((p->x - d->x)*(p->x-d->x)) + ((p->y - d->y) * (p->y - d->y)));
}
template<class D>
void vptree<D>::insert(int x,int y, D data){
  node<D> *temp;
  temp=new node<D>(x,y,data);
  points.push_back(temp);
}
template<class D>
node<D> *vptree<D>::select_best(vector<node<D>* >point){
  int i;
  int mu=0;

  srand (time(0));
  i = rand() % point.size() + 0;
  node<D>*new_root=point[i];
  for(int j=0;j<point.size();j++){
    point[j]->distancia=d(new_root,point[j]);
    mu+=point[j]->distancia;
  }

  new_root->radio=mu/(point.size()-1);
  cout<<"radio"<<mu<<endl;
  return new_root;
}
template<class D>
void vptree<D>::make_vptree(){
  create_vptree(points);
}
template<class D>
node<D> *vptree<D>::create_vptree(vector<node<D>* >point){
  if(point.size()==1) return NULL;
  node<D>*temp;
  temp=select_best(point);
  if(point.size()==points.size()) root=temp;
  vector<node<D>*>l;
  vector<node<D>*>r;
  for(int j=0;j<point.size();j++){
    if(temp->radio<=point[j]->distancia) r.push_back(point[j]);
    else l.push_back(point[j]);
  }
  cout<<"1"<<endl;
  temp->p_child[0]=create_vptree(l);
  cout<<"2"<<endl;
  temp->p_child[1]=create_vptree(r);
  cout<<"3"<<endl;
return temp;
}
