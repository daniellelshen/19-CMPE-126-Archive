/*
 * arrayList.h
 *
 *  Created on: Feb 19, 2019
 *      Author: danie
 */

#ifndef SORTEDARRAYLIST_H_
#define SORTEDARRAYLIST_H_
#define MAX 5
using namespace std;
#include <iostream>



template <class elemType>
class sortedarrayList
{
public:
	sortedarrayList();
	//	arrayList (arrayList* list);
	virtual ~sortedarrayList();
	bool isEmpty () const;
	bool isFull () const;
	int listSize () const;
	int maxListSize ()  const;
	void print () const;
	//	bool isItemAtEqual (int, const elemType& ) const;
	void insert(elemType item);
	//	void insertEnd (elemType);
	void removeAt (int);
	elemType retreiveAt (int);
	//	void replaceAt (int, elemType);
	void clearList ();
	sortedarrayList & operator = (const sortedarrayList &list);
	unsigned int seqSearchIter (elemType element);
	unsigned int seqSearchRec (elemType element, int i);
	unsigned int binSearchIter (elemType element);
	unsigned int binSearchRec (elemType element, int first, int last);


private:
	int currentSize = 0;
	elemType *listArray;
	int maxSize;



};



template <class elemType>
sortedarrayList <elemType> :: sortedarrayList(){
	int maxsize, length;
	elemType elem;

	cout << "Please enter the Max size of your array list: " << endl;
	cin >> maxsize;
	maxSize = maxsize;
	listArray = new elemType [maxSize];

	cout << "Please enter the length of your array list: " << endl;
	cin >> length;

	if (length > maxsize) {
		cout << "ERROR: Your length is bigger than your max size" << endl;
		exit (1);
	}
//	else{
//		currentSize = length;
//	}

	cout << "Enter your elements in the list, separated with a space" << endl;


	for(int i = 0; i<length; i++){
		cin>>elem;
		this->insert(elem);
	}


}

//template <class elemType>
//arrayList <elemType> :: arrayList(arrayList *list){
//	maxSize = 5;
//	listArray = list;
//	currentSize = 0;
//}

template <class elemType>
sortedarrayList <elemType> :: ~sortedarrayList(){
	delete [] listArray;
}

template <class elemType>
bool sortedarrayList <elemType> :: isEmpty () const{
	return (currentSize == 0);
}

template <class elemType>
bool sortedarrayList <elemType> :: isFull () const{
	return (currentSize == maxSize);
}

template< class elemType>
int sortedarrayList <elemType> :: listSize () const{
	return currentSize;
}

template< class elemType>
int sortedarrayList <elemType> :: maxListSize () const{
	return maxSize;
}

template< class elemType>
void sortedarrayList <elemType> :: print () const{

	cout << "***Printing Array List***" << endl;
	for (int i = 0; i < currentSize; i++){
		cout << listArray [i] << " ";
	}
	cout << endl;
	cout << "List Size: " << currentSize << endl;
	cout << "***  ***" <<endl;
}

//template <class elemType>
//bool sortedarrayList <elemType> :: isItemAtEqual (int loc,const elemType& ob) const{
//	return (listArray [loc] == ob);
//}

template <class elemType>
void sortedarrayList <elemType> :: insert(elemType item){
	if (currentSize >= maxSize) {
		cout << "ERROR: Cannot Insert, List Is Full" << endl;
		cout << "Doubling maxSize now" << endl;
		maxSize = maxSize*2;
		cout << "maxSize is now: " << maxSize << endl;

		elemType *temp = new elemType [maxSize];
		for (int i = 0; i < currentSize; i++){
			temp [i] = listArray [i];
		}



		delete [] listArray;
		listArray = temp;
	}

	if (currentSize == 0){
		listArray [0] = item;
		currentSize++;
		return;
	}


	currentSize ++;

	int ij = 0;
	elemType *temp2 = new elemType [maxSize];
	for (int i = 0; item > listArray [i] && i <currentSize; i++){
		temp2 [i] = listArray [i];
		ij++;
	}
//	cout << "ij " << ij << endl;
	temp2 [ij] = item;
	ij++;
	for (int j = ij; j <currentSize; j++){
		temp2 [j] = listArray [j-1];
	}

	delete [] listArray;
	listArray = temp2;


}


//template <class elemType>
//void sortedarrayList <elemType> :: insertEnd (elemType ob){
//	if (currentSize == maxSize){
//
//		cout<< "ERROR: Full List" << endl;
//		cout << "Doubling maxSize now" << endl;
//		maxSize = maxSize*2;
//		cout << "maxSize is now: " << maxSize << endl;
//
//		elemType *temp = new elemType [maxSize];
//
//		for (int i = 0; i < currentSize; i++){
//			temp [i] = listArray [i];
//		}
//
//		delete [] listArray; // no memory leaks
//		cout << "Inserting values" << endl;
//
//
//		listArray = temp;
//
//		listArray [currentSize] = ob;
//		currentSize++;
//
//		cout << "Done Transfer" << endl;
//
//	}
//	else {
//		cout << "Inserting values" << endl;
//		listArray [currentSize] = ob;
//		currentSize++;
//	}
//}

template <class elemType>
void sortedarrayList <elemType> :: removeAt (int loc){
	if (loc < 0 || loc >= currentSize){
		cout << "ERROR: Item to-be-removed's location is out of range" << endl;
		cout << "Location is either negative or does not hold any objects" << endl;

	}
	else {
		for (int i = loc; i < currentSize - 1; i++){
			listArray [i] = listArray [i+1];
		}
		currentSize --;
	}
}

template <class elemType>
elemType sortedarrayList <elemType> :: retreiveAt (int loc){

	return listArray [loc];
}

//template <class elemType>
//void sortedarrayList <elemType> :: replaceAt (int loc, elemType ob){
//	if (loc < 0 || loc >= currentSize){
//		cout << "ERROR: Item to-be-removed's location is out of range" << endl;
//		cout << "Location is either negative or does not hold any objects" << endl;
//
//	}
//	else{
//		listArray [loc] = ob;
//	}
//}

template <class elemType>
void sortedarrayList <elemType> :: clearList (){
	currentSize = 0;
}

template <class elemType>
sortedarrayList <elemType> & sortedarrayList <elemType> ::  operator = (const sortedarrayList <elemType> &other){
	cout << "Using Operator =: " << endl;

	if(this != &other){// check not to copy same thing over

		delete []listArray;
		maxSize = other.maxSize;
		currentSize = other.currentSize;
		//		cout << "current size: " << currentSize << endl;

		listArray = new elemType[maxSize];
		for(int i = 0; i<currentSize; i++){
			listArray[i] = other.listArray[i];
			cout << "List array: " << listArray [i] << endl;
			cout << "Other list Array: " << other.listArray [i] << endl;
		}
	}

	return *this;


}
template <class elemType>
unsigned int sortedarrayList <elemType> :: seqSearchIter (elemType element){
	cout << "List Size: " << listSize() << endl;
	for (int i = 0; i < listSize(); i++){
		if (listArray[i] == element){
			return i;
		}
	}
	cout << endl << "404: Element not found" << endl;
	return 999;
}

template <class elemType>
unsigned int sortedarrayList <elemType> :: seqSearchRec (elemType element, int i){
	if (i == listSize()){
		return 999;
	}
	if (listArray [i] == element){
		return i;
	}
	i++;
	return seqSearchRec (element, i);
}

template <class elemType>
unsigned int sortedarrayList <elemType> :: binSearchIter (elemType element){
	int first = 0;
	int last = currentSize -1;
	int mid;
	bool found = false;

	while (first <= last && !found){
	mid = (first + last)/2;

	if (listArray[mid] == element){
	found = true;
	}
	else if (listArray[mid] > element){
	last = mid -1;
	}
	else{
	first = mid +1;
	}
	}
	if (found){
	return mid;
	}
	else {
	return 999;
	}
}
template <class elemType>
unsigned int sortedarrayList <elemType> :: binSearchRec (elemType element, int first, int last){
//	int first = 0;
//	int last = currentSize -1;
//	cout << "first " << first << endl;
//	cout << "last " << listSize() << endl;
	int mid;
	mid = (first+last+1)/2;
//	cout << "mid " << mid << endl;
	//mid = (first + last)/2;

	if (listArray [mid] == element){
	return mid;
	}
	if (first == last){
	return 999;
	}
	if (listArray[mid] > element){
	return binSearchRec(element, first, mid-1);
//	cout << "mid > elem" << endl;
	}
	else{
//		cout << "***else***" << endl;
	return binSearchRec(element, mid, last);
	}

}
#endif /* SORTEDsortedarrayList_H_ */
