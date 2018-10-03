template <class K, class D>
node<K, D>::node(const K &_key, const D &_data)
{
    key = _key;
    data = _data;
    p_child[0] = NULL;
    p_child[1] = NULL;
    parent=NULL;
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
template<class K,class D>
void redblack<K,D>::insert(const K & key,const D & data){
    node<K,D>*aux1;
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
            aux2=aux1;
            child=aux1->key<inserted->key;
            aux1=aux1->p_child[child];
        }
        inserted->parent=aux2;
            aux2->p_child[child]=inserted;
    }
    fixInsertRBTree(inserted,child);
}

template<class K,class D>
void redblack<K,D>::fixInsertRBTree(node<K,D> *&ptr,bool side){
    node<K,D> *parent = NULL;
    node<K,D> *grandparent = NULL;
    while(ptr!=root and ptr->getColor()==1 and ptr->parent->getColor()==1){
        parent = ptr->parent;
        grandparent = parent->parent;
        
            node<K,D> *tio = grandparent->p_child[!side];
            if(tio->getColor() == 1){
                tio->setColor(0);
                parent->setColor(0);
                grandparent->setColor(1);
                ptr = grandparent;
            }
            else{
                if(ptr == parent->p_child[!side]){
                    turnSide(parent,side);
                    ptr = parent;
                    parent = ptr->parent;
                }
                turnSide(grandparent,!side);
                swap(parent->color, grandparent->color);
                ptr = parent;
            }
    }
    root->setColor(0);
}

template<class K,class D>
bool redblack<K,D>::turnSide(node<K,D> *&ptr, bool side)
{
    side=!side;
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
    ptr->parent = right_child;
}

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
template<class K,class D>
void redblack<K,D>::del(const K & x)
{
     if(root==NULL)
     {
           return ;
     }
     node<K,D> **p;
     p=&root;
     node<K,D> *y=NULL;
     node<K,D> *q=NULL;
     bool found=0;
     node<K, D> ** _n;
    if(find(x,p)){
        found=1;
    }
    if(!found)return ;
    else
     { 
         if((*p)->p_child[0]==NULL||(*p)->p_child[1]==NULL)
              y=(*p);
         else
              y=successor(*p);
         if(y->p_child[0]!=NULL)
              q=y->p_child[0];
         else
         {
              if(y->p_child[1]!=NULL)
                   q=y->p_child[1];
              else
                   q=NULL;
         }
         if(q!=NULL)
              q->parent=y->parent;
         if(y->parent==NULL)
              root=q;
         else
         {
             if(y==y->parent->p_child[0])
                y->parent->p_child[0]=q;
             else
                y->parent->p_child[1]=q;
         }
         if(y!=(*p))
         {
             (*p)->color=y->color;
             (*p)->key=y->key;
         }
         if(y->color==0 && q != NULL )
             fixInsertRBTree(q,0);
     }
}

/*void RBtree::delfix(node *p)
{
    node *s;
    while(p!=root&&p->color=='b')
    {
          if(p->parent->left==p)
          {
                  s=p->parent->right;
                  if(s->color=='r')
                  {
                         s->color='b';
                         p->parent->color='r';
                         leftrotate(p->parent);
                         s=p->parent->right;
                  }
                  if(s->right->color=='b'&&s->left->color=='b')
                  {
                         s->color='r';
                         p=p->parent;
                  }
                  else
                  {
                      if(s->right->color=='b')
                      {
                             s->left->color=='b';
                             s->color='r';
                             rightrotate(s);
                             s=p->parent->right;
                      }
                      s->color=p->parent->color;
                      p->parent->color='b';
                      s->right->color='b';
                      leftrotate(p->parent);
                      p=root;
                  }
          }
          else
          {
                  s=p->parent->left;
                  if(s->color=='r')
                  {
                        s->color='b';
                        p->parent->color='r';
                        rightrotate(p->parent);
                        s=p->parent->left;
                  }
                  if(s->left->color=='b'&&s->right->color=='b')
                  {
                        s->color='r';
                        p=p->parent;
                  }
                  else
                  {
                        if(s->left->color=='b')
                        {
                              s->right->color='b';
                              s->color='r';
                              leftrotate(s);
                              s=p->parent->left;
                        }
                        s->color=p->parent->color;
                        p->parent->color='b';
                        s->left->color='b';
                        rightrotate(p->parent);
                        p=root;
                  }
          }
       p->color='b';
       root->color='b';
    }
}*/
/*template<class K,class D>
void redblack<K,D>::print()
{
    print(root);

}
template<class K,class D>
void redblack<K,D>::print(node<K,D> *n)
{
    if(n)
    {
        cout << n->key <<"(";
        print(n->p_child[0]);
        cout<<" , ";
        print(n->p_child[1]);
        cout<<")";
    }
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
