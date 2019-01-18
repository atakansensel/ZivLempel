#ifndef BINARYNODE_H
#define BINARYNODE_H

#include <string>

using namespace std;


template <class Obj,class Obj2>
	class Tree;

template<class Obj,class Obj2>
class Binarynode{
private:
	Obj element;
	Obj2 word;
	Binarynode *left;
	Binarynode *right;
public:
	Binarynode(Obj obj,Obj2 obj2,Binarynode *rgt,Binarynode *lft){
	element=obj;
	word = obj2;
	left=lft;
	right=rgt;
	}

   
	friend class Tree<Obj,Obj2> ;
}; 




#endif