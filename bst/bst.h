#ifndef BST_H
#define BST_H
#include <iostream>

using namespace std;

template <class K, class D>
class bst;

template <class K, class D>
class node
{
	private:
		K key;
		D data;
		node<K, D> * p_child[2];
	
	public:
		node(const K & _key, const D & _data);
		virtual ~node();
		
	friend class bst<K, D>;
};

template <class K, class D>
class bst
{
	private:
		node<K, D> * root;
	
	public:
		bst();
		virtual ~bst();
		bool find(const K & _key, D & _data);
		bool insert(const K & _key, const D & _data);
		bool remove(const K &_key);
		void print();
		
	
	private:
		void print(node<K,D> *n);
		bool find(const K & _key, node<K, D> **& n);

};

#include "bst.inl"
#endif 