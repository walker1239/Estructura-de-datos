template <class K, class D>
node<K, D>::node(const K &_key, const D &_data)
{
    key = _key;
    data = _data;
    p_child[0] = NULL;
    p_child[1] = NULL;
    height=1;
}

template <class K, class D>
node<K, D>::~node()
{
}

template <class K, class D>
avl<K,D>::avl(){
	root=NULL;
}
template <class K, class D>
avl<K,D>::~avl(){

}
template <class K, class D>
bool avl<K,D>::find(const K & _key, D & _data){
	node<K, D> ** _n;
	if(find(_key,_n)){
		_data=*_n->data;
		return true;
	}
	return false;
}
template <class K, class D>
int avl<K,D>::max(int a, int b)
{
    return a>b?a:b;
}

template <class K, class D>
bool avl<K,D>::find(const K & _key, node<K, D> ** & _n){
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
void avl<K,D>::insert(const K & _key, const D & _data){
    node<K,D>**n;
    n=&root;
    insert(n,_key,_data);
}
template <class K, class D>
bool avl<K,D>::insert(node<K, D> **n, const K & _key, const D & _data)
{  

    if((*n) == NULL){
        *n=new node<K,D>(_key,_data); 
        (*n)->key=_key; 
        cout<<"2";
        return 1;
        
    }
    if ((*n)->key==_key)
    {
        cout<<"3";
        return 0;
    }
    bool child=(*n)->key<_key;

    if (insert(&(*n)->p_child[child],_key,_data))
    {
        balance(n,child);
    }
     
}
template<class K,class D>
bool avl<K,D>::remove(const K &_key)
{
    remove(&root,_key);

}
template<class K,class D>
void avl<K,D>::remove(node<K,D>**&n,const K &_key)
{
    bool child;
    if(!*n){
        *n=NULL;
    }
    if (_key==(*n)->key)
    {
        if ((*n)->p_child[1]==NULL)
        {
            node<K,D> *tmp=*n;
            (*n)=(*n)->p_child[0];
            delete(tmp);
        }
        else
        {
            node<K,D> *tmp=(*n)->p_child[1];
            while(tmp->p_child[0])
                tmp=tmp->p_child[0];
            (*n)->key=tmp->key;
            remove((*n)->p_child[0],tmp->key);
            child=0;
        }
    }
    else{
        child=(*n)->key<_key;
        remove((*n)->p_child[child],_key);
    }
    (*n)->height=max(getHeight((*n)->p_child[0]), getHeight((*n)->p_child[1])) + 1;
    balance(n,child);
}
template<class K,class D>
void avl<K,D>::print(node<K,D> *n)
{
    if(n)
    {
        cout << n->key <<"(";
        print(n->p_child[0]);
        cout<<" , ";
        print(n->p_child[1]);
        cout<<")";
    }
}
template<class K,class D>
bool avl<K,D>::balance(node<K,D> **n,bool side){
    (*n)->height=max((*n)->p_child[0]->getheight(), (*n)->p_child[0]->getheight()) + 1;    
    node<K,D>*son=(*n)->p_child[side];
    int hi=((son)->p_child[0]->getheight())-((son)->p_child[1]->getheight());
    int pa=((*n)->p_child[0]->getheight())-((*n)->p_child[1]->getheight());
    if (pa==2 or pa==-2)
    {
        if (hi*pa<0)
        {
            rotasimple(!side,&(*n)->p_child[side]);
        }
        rotasimple(side,n);
        return 0;
    }
   return 1;  
}

template<class K,class D>
void avl<K,D>::print()
{
    print(root);

}
template <class K, class D>
int node<K, D>::getheight(){
    return (this==NULL)? -1:this->height;
}
/*
template<class K,class D>
void avl<K,D>::print(node<K,D> *n)
{
    if(n)
    {
        if (n->p_child[0])
        {
            os<<n->data;
            os<<"--";
            os<<n->p_child[0]->dato<<endl;
            print(n->p_child[0]);
        }
        if (n->p_child[1])
        {
            os<<n->data;
            os<<"--";
            os<<n->p_child[1]->dato<<endl;
            print(n->p_child[1]);
        }
    }
}

template<class K,class D>
void avl<K,D>::print()
{   
    os<<"graph {"<<endl;
    os<<root->data<<endl;
    print(root);
    os<<"}";
    system("dot.lnk -Tpng -o < grap.dot > out2.png");

}
*/
template<class K,class D>
void avl<K,D>::rotasimple(bool side, node<K,D> **n){
    node<K,D> *tmp=(*n)->p_child[side];
    (*n)->p_child[side]=(tmp)->p_child[!side];
    (tmp)->p_child[!side]=(*n);
}
/*
*/