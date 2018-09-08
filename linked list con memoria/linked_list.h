#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>

using namespace std;

template <class T>
class linked_list;

template <class T>
class node
{
	private:
		T dato;
		node<T> * p_next;
	
	public:
		node(const T & d, node<T> * n = NULL);
		node();
		virtual ~node();
		void print();

	friend class linked_list<T>;
};

template <class T>
class linked_list
{
	private:
		node<T> * p_head;
		node<T> * p_last;
		node<T> * list;
		node<T> * p_free;
		int c;
	public:
		linked_list();
		linked_list(const linked_list<T> &copy);
		linked_list<T>& operator =(const linked_list<T>& copia);
		virtual ~linked_list();
		void insert(const T & d);
		void insert_front(const T & d);
		void insert_back(const T & d);
		bool find(const T & d);
		void remove(const T & d);
		void remove_front();
		void remove_back();
		void reverse();
		T getFirstDato();
		T getLastDato();
		void print();
	private:
		bool find(node<T>* &p,const T & d);

		class iterator
		{
			node<T> * n;
			
			public:
			iterator(node<T> * _n): n(_n) {}

			iterator & operator++()
			{
				n = n->p_next;
			}

			bool operator != (const iterator & it)
			{
				return n != it.n;
			}

			const T & operator*()
			{
				return n->dato;
			}
		};
		const iterator begin()
		{
			return p_head;
		}

		const iterator end()
		{
			return NULL;
		}
};
#include "linked_list.inl"
#endif
