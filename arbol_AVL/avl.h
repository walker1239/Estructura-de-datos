#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <fstream>

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
		void printOficial(int num);
		void rotasimple(bool side, node<K,D> **n);
		int max(int a, int b);
		bool balance(node<K,D> **n,bool side);
		int altura(node<K,D> *n);

	
	private:
		void printOficial(ofstream & es, node<K,D> *n);
		bool insert(node<K, D> **n,const K & _key, const D & _data);
		bool find(const K & _key, node<K, D> **& n);
		node<K,D>* remove(node<K,D>**n, const K &_key);

};

#include "avl.inl"
#endif 