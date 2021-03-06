#ifndef REDBLACK_H
#define REDBLACK_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

template <class K, class D>
class redblack;

template <class K, class D>
class node
{
	private:
		K key;
		D data;
		node<K, D> * p_child[2];
		bool color;
	
	public:
		node(const K & _key, const D & _data);
		virtual ~node();
		bool getColor();
		void setColor(bool _color);
		
	friend class redblack<K, D>;
};
template <class K, class D>
class redblack
{
	private:
		node<K, D> * root;	
		
	public:
		redblack();
		virtual ~redblack();
		bool find(const K & _key, D & _data);
		bool insert(const K & _key,const D & _data);
	    void fixInsertRBTree(node<K,D> *&ptr,bool side);
		bool turnSide(node<K,D> **n, bool side);
	    void printARBOL(int num);
	    node<K,D>* successor(node<K,D> *p);
	    node<K,D>* insert(const K & key,const D & data, node<K,D> ** n, node<K,D> ** p);
		void fixInsertRBTree(node<K,D> **n,node<K,D> **p,bool side,node<K,D> *&ptr);
	    //bool remove(const K &_key);
		//node<K,D>* remove(node<K,D>**n, const K &_key);
	
	private:
		void printARBOL(ofstream & es,node<K,D> *n);
		void printCOLOR(ofstream & es,node<K,D> *n);
		//bool insert(node<K, D> **n,const K & _key, const D & _data);
		bool find(const K & _key, node<K, D> **& n);

};

#include "redblack.inl"
#endif 