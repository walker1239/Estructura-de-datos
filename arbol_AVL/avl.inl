template <class K, class D>
node<K, D>::node(const K &_key, const D &_data)
{
    key = _key;
    data = _data;
    p_child[0] = NULL;
    p_child[1] = NULL;
    height=0;
}
static int i=1;
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
template<class K,class D>
int avl<K,D>::altura(node<K,D> *n)
{
    if(n==NULL){
        return 0;
    }
    if(n->p_child[0]==n->p_child[1]){
        return 1;
    }
    return max(altura(n->p_child[0]),altura(n->p_child[1]))+1;
}
template <class K, class D>
void avl<K,D>::insert(const K & _key, const D & _data){
    insert(&root,_key,_data);
}
template <class K, class D>
bool avl<K,D>::insert(node<K, D> **n,const K & _key, const D & _data)
{  
    
    if(*n == NULL){
        *n=new node<K,D>(_key,_data); 
        printOficial(i++); 
        return 1;
        
    }
    if ((*n)->key==_key)
    {
        return 0;
    }
    bool child=(*n)->key<_key;

    if (insert(&(*n)->p_child[child],_key,_data))
    {    
        
        (*n)->height = max((*n)->p_child[0]->getheight(), (*n)->p_child[1]->getheight() )+ 1;
        balance(n,child);
        
    }

     return 1;
}
template<class K,class D>
bool avl<K,D>::remove(const K &_key)
{
    node<K,D>**n;
    n=&root;
    remove(n,_key);

}
template<class K,class D>
node<K,D>* avl<K,D>::remove(node<K,D>**n, const K &_key)
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
        else
        {
            node<K,D>* temp = (*n)->p_child[1];
            while(temp->p_child[0])
                temp = temp->p_child[0];
            (*n)->key = temp->key;
            (*n)->p_child[1] = remove(&(*n)->p_child[1], temp->key);
        }
    }
    bool child=_key > (*n)->key;
        (*n)->p_child[child] = remove(&(*n)->p_child[child], _key);
    
    
    (*n)->height = max((*n)->p_child[0]->getheight(), (*n)->p_child[1]->getheight() )+ 1;

    balance(n,child);
    return (*n);
}

/*template<class K,class D>
void avl<K,D>::print()
{
    print(root);

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
}*/
template<class K,class D>
bool avl<K,D>::balance(node<K,D> **n,bool side){ 
    bool c=0;  
    cout<<"key"<<(*n)->key<<endl;
    node<K,D>**son=&(*n)->p_child[side];
    int hi=((*son)->p_child[0]->getheight())-((*son)->p_child[1]->getheight());
    int pa=((*n)->p_child[0]->getheight())-((*n)->p_child[1]->getheight());

    if (pa==-2 or pa==2)
    {
        if (hi*pa<=0){
            rotasimple(!side,son);
            c=1;
        }

        rotasimple(side,n);
        printOficial(i++);
    }

   return 1;  
}


template <class K, class D>
int node<K, D>::getheight(){
    return (this==NULL)? -1:this->height;
}
template <class K, class D>
void avl<K,D>::printOficial(int num){
    string num_arch = to_string(num);
    string ext1 = ".dot";
    string num_xt1=""+ num_arch +""+ ext1 +"";
    ofstream es(num_xt1);

    string s = to_string(num);
    string pt1="dot.lnk -Tpng  < ";
    string pt2=" > ";
    string pt3=".png";
    string rt=""+ pt1 +""+ num_xt1 +""+ pt2 +""+ s +""+ pt3 +"";
    const char *buffer = rt.c_str();

    es<<"graph {"<<endl;
    es<<root->key<<endl;
    printOficial(es,root);
    es<<"}"<<endl;
    es.close();
    system(buffer);
}

template <class K, class D>
void avl<K,D>::printOficial(ofstream & es, node<K,D> *n){
    if(n!=NULL)
    {    
        if(n->p_child[0]!=NULL){
            es<<n->key;
            es<<"--";
            es<<n->p_child[0]->key<<endl;
            printOficial(es,n->p_child[0]);
        }
        if(n->p_child[1]!=NULL){
            es<<n->key;
            es<<"--";
            es<<n->p_child[1]->key<<endl;
            printOficial(es,n->p_child[1]);
        }
    }
}
/*template<class K,class D>
void avl<K,D>::print(node<K,D> *n)
{

    if(n)
    {
        if (n->p_child[0])
        {
            os<<n->data;
            os<<"--";
            os<<n->p_child[0]->data<<endl;
            print(n->p_child[0]);
        }
        if (n->p_child[1])
        {
            os<<n->data;
            os<<"--";
            os<<n->p_child[1]->data<<endl;
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
    system("dot -Tpng graph.dot -o avl.png");
}*/

template<class K,class D>
void avl<K,D>::rotasimple(bool side, node<K,D> **n){
    node<K,D>* tmp; 
    tmp=(*n)->p_child[side]; 
    (*n)->p_child[side]=tmp->p_child[!side]; 
    tmp->p_child[!side]=*n; 
    *n=tmp; 
    ((*n))->height = max((*n)->p_child[0]->getheight(), (*n)->p_child[1]->getheight()) + 1;
    (tmp)->height = max((tmp)->p_child[1]->getheight(), ((*n))->height) + 1;
}
