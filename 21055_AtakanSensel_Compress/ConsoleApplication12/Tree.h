#ifndef TREE_H
#define TREE_H

#include<string>
#include"Binarynode.h"

using namespace std;


template<class Obj,class Obj2>
class Tree{

private:
	
	Binarynode<Obj,Obj2> *root;

	void insert_private(const Obj &obj,const Obj2 &obj2,Binarynode<Obj,Obj2> *&n);
	


public:
	Tree();
	void insert_public(const Obj &obj,const Obj2 &obj2);
	Obj find(const Obj2 &obj2);
};


template<class Obj,class Obj2>
Tree<Obj,Obj2>::Tree(){
	//Not_found2=ntfound2;
//	Not_found = ntfound;
	root=nullptr;
}

template<class Obj,class Obj2>
void Tree<Obj,Obj2>::insert_public(const Obj &obj,const Obj2 &obj2)
{
	insert_private(obj,obj2,root);
}

template<class Obj,class Obj2>
void Tree<Obj,Obj2>::insert_private(const Obj &obj,const Obj2 &obj2,Binarynode<Obj,Obj2> *&n)
{
	if(n == nullptr)
	{
		n = new Binarynode<Obj,Obj2>(obj,obj2,nullptr,nullptr);
	}
	else if(obj2 < n->word)
	{
		insert_private(obj,obj2,n->left);
	}
	else if(obj2 > n->word)
	{
		insert_private(obj,obj2,n->right);
	}
	else
	{
		;
	}


}

template<class Obj,class Obj2>
Obj Tree<Obj,Obj2>::find(const Obj2 &obj2)
{
	Binarynode<Obj,Obj2> *ptr = root;

	if(ptr == nullptr)
	{
		return -1;
	}

	while(ptr != nullptr){
		if(ptr->word == obj2)
		{
			return ptr->element;
		}
		else if(ptr->word > obj2)
		{
			ptr=ptr->left;
		}
		else if(ptr->word < obj2)
		{
			ptr=ptr->right;
		}

	}

	return -1;


}


#endif