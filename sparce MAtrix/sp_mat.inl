template<class T>
node<T>::node(unsigned int _i,unsigned int _j,const T &_value){
    i=_i;
    j=_j;
    p_next[0] = NULL;
    p_next[1] = NULL;
    value=_value;
}
template<class T>
node<T>::~node(){

}
template<class T>
sp_mat<T>::sp_mat(unsigned int m,unsigned int n){
    ptr_index[0]=new node<T>*[m];
    ptr_index[1]=new node<T>*[n];
}
template<class T>
sp_mat<T>::~sp_mat(){

}
template<class T>
T& sp_mat<T>::operator()(unsigned int _i, unsigned int _j)
{
    node<T> ** r;
    if(!find(r,_i,_j,0)){
        node<T>** c;
        find(c,_i,_j,1);
        *r=*c=new node<T>(_i,_j,1);
    }
    return (*r)->value;
}
template<class T>
T sp_mat<T>::find(node<T>**&n,unsigned int _i, unsigned int _j,bool rotate){
    int c;
    if (rotate)
        c=_i;
    else
        c=_j;
    (n)=&ptr_index[rotate][c];
    while((*n)){
        if ((*n)->p_next[rotate]->j==_j and (*n)->p_next[rotate]->i==_i)
        {
            return ((*n)->p_next[rotate]->value);
        }
        n=&((*n)->p_next[!rotate]);
    }
    return 0;
}
template<class T>
void sp_mat<T>::insert(unsigned int _i,unsigned int _j, const T &_value)
{
    node<T>** n;
    node<T>** s;
    find(s,_i,_j,0);
    find(n,_i,_j,1);
    (*n)=new node<T>(_i,_j,_value);
    (*s)=(*n);
}
/*friend ostream& operator<<(ostream& os,const sp_mat<T> & s) 
{ 
    int c=0;
    node<T> **i=&s.ptr_index[0][0];
    node<T> **j=&s.ptr_index[1][0];
    while((*j)->p_next[0]!=NULL){
        while((*i)->p_next[0]!=NULL){
            os<<(*i)->p_next[0]->value<<"     ";
        }
        os<<endl;
    }
    return os; 
} */
template<class T>
void sp_mat<T>::print()
{ 
    int c=0;
    node<T> **i=&ptr_index[0][0];
    node<T> **j=&ptr_index[1][0];
    while((*j)){
        while((*i)){
            cout<<(*i)->p_next[0]->value<<"     ";
            (*i)=(*i)->p_next[0];
        }
        cout<<endl;
        (*j)=(*j)->p_next[1];
    }
} 
