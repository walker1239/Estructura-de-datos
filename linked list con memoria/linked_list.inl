template<class T>
node<T>::node(const T & d, node<T> * n )
{
	dato = d;
	p_next =n;
}
template<class T>
node<T>::node()
{
	p_next = NULL;
}
template<class T>
node<T>::~node()
{
	if(p_next)
		delete p_next;
}
template<class T>
void node<T>::print()
{
	cout<<dato<<" -> ";
}


template<class T>
linked_list<T>::linked_list(){
	p_head=NULL;
	p_last=NULL;
	list= new node<T> [10000];
	p_free=&list[0];
	c=1;
}
template<class T>
linked_list<T>::~linked_list(){

}
template<class T>
void linked_list<T>::insert(const T & d){
	node<T> *n;
	node<T> *p;
	if(find(p,d))
		return;
	n=p_free;
	n->dato=d;
	if(!p_head){
		p_head=n;
	}

	if (p_free->p_next){
		p_free=p_free->p_next;
		p_free->p_next=NULL;
		p->p_next=n;
		return;
	}
	p_free=&list[c];
	n->p_next=p_free;
	c++;
}
template<class T>
void linked_list<T>::remove(const T & d){
	node<T> *n;
	if(find(n,d)){
		if (p_free->p_next==NULL)
		{
			p_free->p_next=n;
		}		
		else
		{
			node<T> *temp;
			temp=p_free;
			while(temp->p_next)
			{
				temp=temp->p_next;
			}
			temp=n;
		}
		if (n->p_next)
		{
			node<T> *tmp;
			tmp=p_free;
			while(1){
				if(tmp->p_next->dato==n->dato)
					break;
				tmp=tmp->p_next;
			}
			tmp=n->p_next;
		}
		n->p_next=NULL;
		
	}
}
/*template<class T>
void linked_list<T>::insert_front(const T & d){
	if(!p_head){
		p_head=new node<T>(d);
		p_last=p_head;
		return;
	}
	node<T> *tmp;
	tmp=new node<T>(d,p_head);
	p_head=tmp;
}	
template<class T>
void linked_list<T>::insert_back(const T & d){
	node<T> *tmp;
	tmp=new node<T>(d);
	if(!p_head){
		p_head=tmp;
		p_last=tmp;
		return;
	}
	p_last->p_next=tmp;
	p_last=tmp;
}*/
template<class T>
bool linked_list<T>::find(const T & d){
	node<T> *p;
	find(p,d);
}
template<class T>
bool linked_list<T>::find(node<T>* &p ,const T & d){
	p=p_head;
	while (p!=NULL){
		if(p->dato==d){
			return 1;
		}
		p=p->p_next;
	}
	return 0;

}
template<class T>
void linked_list<T>::remove_front(){
	if(p_head != NULL){
            if(p_head->p_next != NULL){
                node<T> *tmp = p_head;
                p_head = tmp->p_next;
                tmp->p_next=NULL;
                delete tmp;
            }
            else {
                p_head = NULL;
            }
    }
}
template<class T>
void linked_list<T>::remove_back(){
	node<T> *tmp= p_head;
	node<T> *tmp2;
	while(tmp->p_next){
		tmp2=tmp;
		tmp=tmp->p_next;
	}
	tmp2->p_next=NULL;
	delete tmp;
}
template<class T>
void linked_list<T>::reverse(){
	if(p_head == NULL) return;

    node<T> *back = NULL, *tmp = NULL, *forward = NULL;
    tmp = p_head;
    while(tmp){
        forward = tmp->p_next;
        tmp->p_next = back;
        back = tmp;
        tmp = forward;
    }
    p_head = back;
}
template<class T>
T linked_list<T>::getFirstDato(){
	return p_head->dato;
}
template<class T>
T linked_list<T>::linked_list::getLastDato(){
	return p_last->dato;
}
template<class T>
void linked_list<T>::print(){
	node<T> *tmp= p_head;
	while(tmp!=NULL){
		tmp->print();
		tmp=tmp->p_next;
	}
	cout<<endl;
}
template<class T>
linked_list<T>::linked_list(const linked_list<T>& copy){
	if (copy.p_head == NULL) {
        p_head = NULL;
    }
    else {
        p_head = new node<T>(copy.p_head->dato);
        node<T> *copia = p_head;
        node<T> *itera = copy.p_head;
        while (itera->p_next != NULL) {
            copia->p_next = new node<T>(itera->p_next->dato);
            itera = itera->p_next;
            copia = copia->p_next;
        }
    }	

}
template<class T>
linked_list<T>& linked_list<T>:: operator =(const linked_list<T>& copia) 
{	
	linked_list<T> copy(copia);
	return copia;
}
