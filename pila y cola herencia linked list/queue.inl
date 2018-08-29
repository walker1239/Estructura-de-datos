template<class T>
queue<T>::queue()
{
}
template<class T>
void queue<T>::push(const T & d)
{
    this->insert_back(d);
}
template<class T>
void queue<T>::remove()
{
    this->remove_front();
}