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
}
template<class T>
linked_list<T>::~linked_list(){

}
template<class T>
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
}
template<class T>
bool linked_list<T>::find(const T & d){
	node<T> *p=p_head;
	while (p!=p_last){
		if(p->dato==d){
			return 1;
		}
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
	while(tmp){
		cout<<tmp->dato<<"->";
		tmp=tmp->p_next;
	}
	cout<<endl;
}