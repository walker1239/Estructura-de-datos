template <class K, class D>
node<K, D>::node(const K &_key, const D &_data)
{
    key = _key;
    data = _data;
    p_child[0] = NULL;
    p_child[1] = NULL;
}

template <class K, class D>
node<K, D>::~node()
{
}

template <class K, class D>
bst<K,D>::bst(){
	root=NULL;
}
template <class K, class D>
bst<K,D>::~bst(){

}
template <class K, class D>
bool bst<K,D>::find(const K & _key, D & _data){
	node<K, D> ** _n;
	if(find(_key,_n)){
		_data=*_n->data;
		return true;
	}
	return false;

}
template <class K, class D>
bool bst<K,D>::insert(const K & _key, const D & _data){
	node<K, D> **_n;
	if(find(_key,_n)==false){
		(*_n)=new node<K, D>(_key, _data);
		return true;
	}
	return false;
}
template<class K,class D>
bool bst<K,D>::remove(const K &_key)
{
    node<K,D> **p;
    node<K,D> *temp;
    node<K,D> *itera;
    node<K,D> *replace;
    if(!find(_key,p))
        return;
    else if(*p->p_child[0] == NULL && *p->p_child[1] ==NULL){
        temp = *p;
        *p=NULL;
        delete temp;
    }
    else if(*p->p_child[0]==NULL){
        temp = *p;
        *p = *p->p_child[1];
        delete temp;
    }
    else if(*p->p_child[1]==NULL){
        temp = *p;
        *p = *p->p_child[0];
        delete temp;
    }
    else {
        itera =*p->p_child[0];
        replace = NULL;
        while (itera->p_child[0] != NULL)
        {
            replace=itera;
            itera = itera->p_child[1];
        }
        *p->key = itera->key;
        *p->data = itera->data;
        if(replace==NULL)
           *p->p_child[0] = itera->p_child[0];
        else
            replace->p_child[1] = itera->p_child[0];
        delete itera;
    }

}
template<class K,class D>
void bst<K,D>::print(node<K,D> *n)
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
void bst<K,D>::print()
{
    print(root);
}
template <class K, class D>
bool bst<K,D>::find(const K & _key, node<K, D> ** & _n){
 	_n=&root;
	while(*_n){
		if((*_n)->key==_key){
			return true;
		}
		(*_n)=(*_n)->p_child[(*_n)->key<_key];
	}
	return false;
}
