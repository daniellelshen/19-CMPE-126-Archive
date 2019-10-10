/*
 * maxheap.h
 *
 *  Created on: Apr 22, 2019
 *      Author: danie
 */

#ifndef MAXHEAP_H_
#define MAXHEAP_H_

#include<iostream>
using namespace std;

template <class elemType>
class maxHeap {
public:
	maxHeap(int s);
	~maxHeap();
	void print();
	void sort();
	int insert (elemType item);
	int search (elemType element);
	void buildHeap();
private:
	elemType *heapArray;
	int size;
	int maxSize;
	void heapify (int low, int high);

};

template <class elemType>
maxHeap <elemType> :: maxHeap (int s){
	heapArray = new elemType [s];
	maxSize = s;
	size = 0;
}

template <class elemType>
maxHeap <elemType> :: ~maxHeap (){
	delete [] heapArray;
}

template <class elemType>
void maxHeap <elemType> :: print (){
	for (int i = 0; i<size; i++){
		cout << heapArray [i] << " " << endl;
	}
}

template <class elemType>
void maxHeap <elemType> :: sort (){
	elemType temp;
	buildHeap();

	for (int lastOutOfOrder = size-1; lastOutOfOrder >= 0; lastOutOfOrder--){
		temp = heapArray [lastOutOfOrder];
		heapArray[lastOutOfOrder] = heapArray [0];
		heapArray [0] = temp;
		heapify (0, lastOutOfOrder-1);
	}
}


template <class elemType>
int maxHeap <elemType> :: insert (elemType item){

		if (size == maxSize){
			throw "Heap Full";
		}

		heapArray [size++] = item;

		buildHeap();

		return search(item);

}

template <class elemType>
int maxHeap <elemType> :: search (elemType item){
	for (int i = 0; i < size; i++){
		if (heapArray[i] == item){
			return i;
		}
	}
	return -1;
}

template <class elemType>
void maxHeap <elemType> :: buildHeap (){
	for (int i = size/2 -1; i>=0; i--){
		heapify(i, size-1);
	}
}

template <class elemType>
void maxHeap <elemType> :: heapify (int low, int high){
	int largeIndex;

	elemType temp = heapArray[low];
	largeIndex = 2*low+1;

	while (largeIndex <= high){
		if (largeIndex < high){
			if (heapArray[largeIndex] < heapArray[largeIndex +1]){
				largeIndex++;
			}
		}
		if (temp > heapArray[largeIndex]){
			break;
		}
		else{
			heapArray[low] = heapArray[largeIndex];
			low = largeIndex;
			largeIndex = 2*low+1;
		}
	}

	heapArray [low] = temp;

}
#endif /* MAXHEAP_H_ */
