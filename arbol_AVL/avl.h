#ifndef AVL_H
#define AVL_H
#include <iostream>

using namespace std;

template <class K, class D>
class avl;

template <class K, class D>
class node
{
	private:
		K key;
		D data;
		node<K, D> * p_child[2];
		int height;
	
	public:
		node(const K & _key, const D & _data);
		virtual ~node();
		int getheight();
		
	friend class avl<K, D>;
};
template <class K, class D>
class avl
{
	private:
		node<K, D> * root;	
	public:
		avl();
		virtual ~avl();
		bool find(const K & _key, D & _data);
		void insert(const K & _key, const D & _data);
		bool remove(const K &_key);
		void print();
		void rotasimple(bool side, node<K,D> **n);
		int max(int a, int b);
		bool balance(node<K,D> **n,bool side);
	
	
	private:
		void print(node<K,D> *n);
		bool insert(node<K, D> **n,const K & _key, const D & _data);
		bool find(const K & _key, node<K, D> **& n);
		void remove(node<K,D>**&n,const K &_key);

};

#include "avl.inl"
#endif 