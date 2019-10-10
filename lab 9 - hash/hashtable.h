/*
 * hashtable.h
 *
 *  Created on: Apr 15, 2019
 *      Author: danie
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include <iostream>
//#include "arrayList.h"

using namespace std;

template <class elemType> class HashT {
public:
	HashT(int n);
	virtual ~HashT();
	void print();
	bool insert (elemType x);
	elemType search (elemType x);
	bool deleteT(elemType x);
private:
	int HTSize;
	elemType hashTable[];
	//		arrayList <elemType> *hashTable;
	//		hashItem <elemType> *item;
};

template <class elemType>
HashT <elemType> :: HashT (int n){
	//	hashTable = new arrayList<elemType>(n);
	for (int i = 0; i<n; i++){
		hashTable[i] = '\0';
	}
	//	hashTable[n] = { };
	HTSize = n;
	//	item = NULL;
};

template <class elemType>
HashT <elemType> :: ~HashT(){
	delete[] this->hashTable;
}

template <class elemType>
bool HashT <elemType> :: insert(elemType x){
	int count = 0;
	int tempkey = (int)x%HTSize;
	while (hashTable[tempkey] != '\0' && count<HTSize){
		tempkey ++;
		tempkey = tempkey%HTSize;
		count ++;
	}
	if (hashTable[tempkey] == '\0'){
		hashTable[tempkey] = x;
		return true;
	}
	return false;

};

template <class elemType>
void HashT <elemType> :: print(){
	//	hashTable.print();
	cout << "***Printing Hash Table***" << endl;
	for (int i = 0; i < HTSize; i++){
		cout << hashTable [i] << " ";
	}
	cout << endl;
	cout << "Hash Table Size: " << HTSize << endl;
	cout << "***  ***" <<endl;
}

template <class elemType>
elemType HashT <elemType> :: search(elemType x){
	int tempkey = (int)x%HTSize;
	int count = 0;
	elemType tempVar = hashTable [tempkey];
	if (tempVar == x){
		hashTable [tempkey] = '\0';
		return tempVar;
	}

	while (hashTable[tempkey] != x && count<HTSize){
		tempkey ++;
		tempkey = tempkey%HTSize;
		count ++;
		tempVar = hashTable [tempkey];
	}
	if (tempVar == x){
		hashTable [tempkey] = '\0';
		return tempVar;
	}


	return -999;
}

template <class elemType>
bool HashT <elemType> :: deleteT(elemType x){
	int tempkey = (int)x%HTSize;
	int count = 0;
	elemType tempVar = hashTable [tempkey];
	if (tempVar == x){
		hashTable [tempkey] = '\0';
		return true;
	}

	while (hashTable[tempkey] != x && count<HTSize){
		tempkey ++;
		tempkey = tempkey%HTSize;
		count ++;
		tempVar = hashTable [tempkey];
	}
	if (tempVar == x){
		hashTable [tempkey] = '\0';
		return true;
	}


	return false;
}


#endif /* HASHTABLE_H_ */
