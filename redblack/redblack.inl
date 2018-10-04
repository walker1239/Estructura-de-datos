template <class K, class D>
node<K, D>::node(const K &_key, const D &_data)
{
    key = _key;
    data = _data;
    p_child[0] = NULL;
    p_child[1] = NULL;
    color=1;
}
static int i=1;
template <class K, class D>
node<K, D>::~node()
{
}
template <class K, class D>
redblack<K,D>::redblack(){
	root=NULL;

}
template <class K, class D>
redblack<K,D>::~redblack(){

}
template <class K, class D>
bool redblack<K,D>::find(const K & _key, D & _data){
	node<K, D> ** _n;
	if(find(_key,_n)){
		_data=*_n->data;
		return true;
	}
	return false;
}
template <class K, class D>
bool redblack<K,D>::find(const K & _key, node<K, D> ** & _n){
    _n=&root;
    while(*_n){
        if((*_n)->key==_key){
            return true;
        }
        _n=&(*_n)->p_child[(*_n)->key<_key];
    }
    return false;
}
template <class K, class D>
bool redblack<K,D>::insert(const K & _key,const D & _data){
    insert(_key,_data,&root,NULL);
    return true;
}
template<class K,class D>
node<K,D>* redblack<K,D>::insert(const K & key,const D & data, node<K,D> ** n, node<K,D> ** p){
    if((*n)==NULL){
        *n = new node<K,D>(key,data);
        return *n;
    }
    if((*n)->key==key){
        return NULL;
    }
    bool child = ((*n)->key < key);
    node<K,D> *aux = insert(key,data,&(*n)->p_child[child],n); 
    if(!aux){
        return (*n);
    }
    if(!p){
        return NULL;
    }
       
        
       // convertirRedblack(p,n,child,aux);
    
  /*  node<K,D>*aux1;
    node<K,D>*aux2;
    node<K,D>*inserted=new node<K,D>(key,data);
    aux1=root;
    aux2=NULL;
    bool child;
    if(root==NULL)
    {
        root=inserted;
        inserted->parent=NULL;
    }
    else
    {
        while(aux1!=NULL)
        {
            if(aux1->key==inserted->key)
                return;
            aux2=aux1;
            child=aux1->key<inserted->key;
            aux1=aux1->p_child[child];
        }
        inserted->parent=aux2;
            aux2->p_child[child]=inserted;
    }*/
    fixInsertRBTree(p,n,child,aux);
}

template<class K,class D>
void redblack<K,D>::fixInsertRBTree(node<K,D> **n,node<K,D> **p,bool side,node<K,D> *&ptr){
    node<K,D> *parent = *p;
    node<K,D> *grandparent = *n;
    while(ptr!=root and ptr->getColor()==1 and parent->getColor()==1){
        
            node<K,D> *tio = (*n)->p_child[!side];
            if(tio->getColor() == 1){
                tio->setColor(0);
                parent->setColor(0);
                grandparent->setColor(1);
                ptr = grandparent;
            }
            else{
                if(ptr == parent->p_child[!side]){
                    turnSide(&parent,side);
                    ptr = parent;
                    parent = grandparent;
                }
                turnSide(&grandparent,!side);
                swap(parent->color, grandparent->color);
                ptr = parent;
            }
    }
    root->setColor(0);
}

template<class K,class D>
bool redblack<K,D>::turnSide(node<K,D> ** n, bool side)
{

    node<K,D> *mid = (*n)->p_child[side];
    (*n)->p_child[side] = mid->p_child[!side];
    mid->p_child[!mid] = (*n);
    (*n) = mid;
}
    /*side=!side;
    node<K,D> *right_child = ptr->p_child[side];
    ptr->p_child[side] = right_child->p_child[!side];
    if (ptr->p_child[side] != NULL){
        ptr->p_child[side]->parent = ptr;
    }

    right_child->parent = ptr->parent;

    if (ptr->parent == NULL){
        root = right_child;
    }
    else{
        if (ptr == ptr->parent->p_child[!side]){
            ptr->parent->p_child[!side] = right_child;
        }

        else{
            ptr->parent->p_child[side] = right_child;
        }
    }
    right_child->p_child[!side] = ptr;
    ptr->parent = right_child;*/

template<class K,class D>
bool node<K,D>::getColor() {
    if (this == NULL){
        return 0;
    }
    return this->color;
}

template<class K,class D>
void node<K,D>::setColor(bool _color) {
    if (this == NULL){
        return;
    }
    this->color = _color;
}
template<class K,class D>
node<K,D>* redblack<K,D>::successor(node<K,D> *p)
{
      node<K,D> *y=NULL;
     if(p->p_child[0]!=NULL)
     {
         y=p->p_child[0];
         while(y->p_child[1]!=NULL)
              y=y->p_child[1];
     }
     else
     {
         y=p->p_child[1];
         while(y->p_child[0]!=NULL)
              y=y->p_child[0];
     }
     return y;
}
/*bool redblack<K,D>::remove(const K &_key)
{
    node<K,D>**n;
    n=&root;
    remove(n,_key);
}
node<K,D>* redblack<K,D>::remove(node<K,D>**n, const K &_key)
{
    if(!root)
        return NULL;
    if(_key == (*n)->key)
    {

        if((*n)->p_child[1] == NULL)
        {
            node<K,D>* temp = (*n);
            (*n) = (*n)->p_child[0];
            delete (temp);
            return (*n);
        }
        else if((*n)->p_child[0] == NULL)
        {
            node<K,D>* temp = (*n);
            (*n) = (*n)->p_child[1];
            delete (temp);
            return (*n);
        }
        else
        {
            node<K,D>* temp = (*n)->p_child[1];
            while(temp->p_child[0])
                temp = temp->p_child[0];
            (*n)->key = temp->key;
            (*n)->p_child[1] = &remove(&(*n)->p_child[1],temp->key);
        }
    }
    fixInsertRBTree((*n),0);
}*/

template<class K, class D>
void redblack<K,D>::printCOLOR(ofstream & es,node<K,D> *ptr){
  if (ptr == NULL)
    return;
  if(ptr->color == 0){
    es<< ptr->key << "[style=filled, fillcolor=black, fontcolor=white]"<< endl;
  }
  else es<< ptr->key << "[style=filled, fillcolor=red]"<< endl;
  printCOLOR(es,ptr->p_child[0]);
  printCOLOR(es,ptr->p_child[1]);
}

template<class K, class D>
void redblack<K,D>::printARBOL(int num){
    string num_arch = to_string(num);
    string ext1 = ".dot";
    string num_xt1=""+ num_arch +""+ ext1 +"";
    ofstream es(num_xt1);
    ////////
    string s = to_string(num);
    string pt1="dot.lnk -Tpng  < ";
    string pt2=" > ";
    string pt3=".png";
    string rt=""+ pt1 +""+ num_xt1 +""+ pt2 +""+ s +""+ pt3 +"";
    const char *buffer = rt.c_str();
    ////////
    es<<"digraph mentions {"<<endl;
    printARBOL(es,root);
    printCOLOR(es,root);
    es<<"}"<<endl;
    es.close();
    system(buffer);
}

template<class K, class D>
void redblack<K,D>::printARBOL(ofstream & es,node<K,D> *n){
    if(n!=NULL){
        if(n->p_child[0]!=NULL){
            es<<n->key;
            es<<" -> ";
            es<<n->p_child[0]->key<<endl;
            printARBOL(es,n->p_child[0]);
        }
        if(n->p_child[1]!=NULL){
            es<<n->key;
            es<<" -> ";
            es<<n->p_child[1]->key<<endl;
            printARBOL(es,n->p_child[1]);
        }
    }
}
