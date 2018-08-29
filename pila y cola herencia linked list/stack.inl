template<class T>
stack<T>::stack()
{
}
template<class T>
void stack<T>::push(const T & d)
{
    this->insert_back(d);
}
template<class T>
void stack<T>::remove()
{
    this->remove_back();
}