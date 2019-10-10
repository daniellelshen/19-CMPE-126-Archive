/*
 * treeheap.h
 *
 *  Created on: Apr 29, 2019
 *      Author: danie
 */

#ifndef TREEHEAP_H_
#define TREEHEAP_H_

#include<iostream>
using namespace std;
#include <queue>

template <class elemType>
struct nodeType{
	elemType info;
	nodeType <elemType> *parentLink;
	nodeType <elemType> *leftLink;
	nodeType <elemType> *rightLink;
};

template <class elemType>
class treeHeap {
public:
	treeHeap ();
	~treeHeap();
	void print();
	void buildHeap (elemType *object, int size);
	const nodeType<elemType> * dfs(elemType object);
	nodeType<elemType> *bfs(elemType);
	nodeType<elemType> *search (elemType object);
	int treeNodeSize ();

private:
	nodeType <elemType> *none;
	nodeType <elemType> *root; //root of the heap tree
	nodeType <elemType> *tail; //the current left-most node on the lowest level of the tree TODO: need to make sure to have this
	int count = 0;
	void insert(elemType &object);
	void inorder (nodeType <elemType> *p)const{
		if (p!=NULL){
			inorder(p->leftLink);
			cout << p-> info << " " ;
			inorder(p->rightLink);
		}
	}


	void destroy (nodeType<elemType> * &p){
		if (p != NULL){
			destroy(p->leftLink);
			destroy(p->rightLink);
			delete p;
			p = NULL;
		}
	}


	nodeType <elemType> * discover (nodeType<elemType> * &p, elemType object){

		if (p!=NULL){
			if (p-> info == object){
				return p;
			}

			nodeType <elemType> *temp;
			temp = discover(p->leftLink, object);
			if(temp != this->none){
				return temp;
			}
			temp = discover(p->rightLink, object);
			if (temp != this->none){
				return temp;
			}
		}
		return NULL;

	}

	int nodeCount(nodeType<elemType>* node){
		if ( root == NULL )
			return 0;
		else {
			int count = 1;
			count += nodeCount(root->leftLink);
			count += nodeCount(root->rightLink);
			return count;
		}
	}

};

template <class elemType>
treeHeap <elemType> :: treeHeap () {
	root = NULL;
	tail = NULL;
	none = NULL;
}

template <class elemType>
treeHeap <elemType> :: ~treeHeap (){

	destroy (root);
}

template <class elemType>
void treeHeap <elemType> :: print(){
	inorder(root);
}
//TODO: tree heap has no constructor

template <class elemType>
void treeHeap<elemType> :: buildHeap (elemType *object, int size){
	for (int i = 0; i <size; i ++){
		this->insert(object[i]);
	}

}

template <class elemType>
void treeHeap<elemType> :: insert (elemType &object){
	nodeType<elemType> *current;
	nodeType <elemType> *trailCurrent;
	nodeType <elemType> *newNode;
	newNode = new nodeType<elemType>;

	newNode -> info = object;
	newNode ->leftLink = NULL;
	newNode -> rightLink = NULL;

	if (root == NULL){
		root = newNode;
	}
	else{
		current = root;
		while (current != NULL){
			trailCurrent = current;

			if (current -> info == object){
				cerr << "Object to be inserted is already in the list: " << object << endl;
				return;
			}
			if (current -> info > object){
				current = current->leftLink;
			}
			else{
				current = current->rightLink;
			}

		}
		if (trailCurrent -> info >object){
			trailCurrent ->leftLink = newNode;
		}
		else{
			trailCurrent -> rightLink = newNode;
		}
	}

}

template <class elemType>
const nodeType<elemType> * treeHeap<elemType> :: dfs (elemType object){
	return discover(root, object);
}

template <class elemType>
nodeType<elemType> * treeHeap<elemType> :: bfs (elemType object){
	queue<nodeType> myQueue;

	nodeType<elemType> temp;


	if (root->info == object){
		return root;
	}

	myQueue.push(root->leftLink);
	myQueue.push(root->rightLink);

	for (int index = 0; index < treeNodeSize()-1; index++){
		temp = myQueue.front();
		if (temp->info == object){
			return temp;
		}
		myQueue.push(temp->leftLink);
		myQueue.push(temp->rightLink);
	}


}


//TODO: check this
template <class elemType>
nodeType<elemType> * treeHeap <elemType> :: search (elemType object) {

	nodeType <elemType> *current;
	bool found = false;

	if (root == NULL) {
		throw "Binary tree is empty.";
	}
	else {
		current = root;
		while (current != NULL && !found) {
			if (current->info == object)
				found = true;
			else if (current->info > object)
				current = current->left;
			else
				current = current->right;
		}
	}
	return current;
}

template<class elemType>
int treeHeap<elemType> :: treeNodeSize (){
	return nodeCount(root);
}

#endif /* TREEHEAP_H_ */
