/*
 * hashtablechaining.h
 *
 *  Created on: Apr 15, 2019
 *      Author: danie
 */

#ifndef HASHTABLECHAINING_H_
#define HASHTABLECHAINING_H_
#include <iostream>
#include "sortedLinkedList.h"

using namespace std;


template <class elemType> class HashTableChaining {
public:
	HashTableChaining(int n);
	~HashTableChaining();
	void print();
	bool insert (elemType x);
	elemType search (elemType x);
	int getKey(elemType x){
		return (int)x%HTSize;
	}
	bool deleteT(elemType x);
private:
	int HTSize;
	linkedList <elemType> *HT;

};

template <class elemType>
HashTableChaining <elemType> :: HashTableChaining(int n){

	this->HTSize = n;
	HT = new linkedList<elemType>[HTSize];
};

template <class elemType>
HashTableChaining <elemType> :: ~HashTableChaining(){
	for (int i = 0; i<HTSize; i++){
		HT[i].clearList();
	}
	delete []HT;
}

template <class elemType>
bool HashTableChaining <elemType> :: insert(elemType x){
//	int count = 0;
	int tempKey = getKey(x);

	for (int i = 0; i<HT[tempKey].listSize(); i++){
			elemType tempVar = HT[tempKey].retreiveAt(i);
			if (tempVar == x){
				return false;
			}
		}
	HT[tempKey].insert(x);
	return true;
}

template <class elemType>
void HashTableChaining <elemType> :: print(){
	for (int i = 0; i<HTSize; i++){
	HT[i].print();
	}
}

template <class elemType>
elemType HashTableChaining <elemType> :: search(elemType x){
	int tempKey = getKey(x);

	//loop to look into the linkList located at that temp key
	//see if the payload is the same as the given element
	// if it is, then i want to return it and delete it
	// if not go to next element of the linkedList
	for (int i = 0; i<HT[tempKey].listSize(); i++){
		elemType tempVar = HT[tempKey].retreiveAt(i);
		if (tempVar == x){
			HT[tempKey].remove(x);
			//remove to null
			return tempVar;
		}
	}
	return -1;
}

template<class elemType>
bool HashTableChaining <elemType> :: deleteT(elemType x){
	int tempKey = getKey(x);
	return HT[tempKey].remove(x);
}

#endif /* HASHTABLECHAINING_H_ */
