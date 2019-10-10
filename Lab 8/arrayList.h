/*
 * arrayList.h
 *
 *  Created on: Feb 19, 2019
 *      Author: danie
 */

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_
#define MAX 5
using namespace std;
#include <iostream>



template <class elemType>
class arrayList
{
public:
	arrayList ();
//	arrayList (arrayList* list);
	virtual ~arrayList();
	bool isEmpty () const;
	bool isFull () const;
	int listSize () const;
	int maxListSize ()  const;
	void print () const;
	bool isItemAtEqual (int, const elemType& ) const;
	void insertAt (int, elemType);
	void insertEnd (elemType);
	void removeAt (int);
	elemType retreiveAt (int);
	void replaceAt (int, elemType);
	void clearList ();
	arrayList & operator = (const arrayList &list);
	unsigned int seqSearchIter (elemType element);
	unsigned int seqSearchRec (elemType element, int i);


private:
	int currentSize;
	elemType *listArray;
	int maxSize;



};



template <class elemType>
arrayList <elemType> :: arrayList(){
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
	else{
		currentSize = length;
	}

	cout << "Enter your elements in the list, separated with a space" << endl;

	for(int i = 0; i<currentSize; i++){
		cin>>elem;
		listArray[i] = elem;
	}


}

//template <class elemType>
//arrayList <elemType> :: arrayList(arrayList *list){
//	maxSize = 5;
//	listArray = list;
//	currentSize = 0;
//}

template <class elemType>
arrayList <elemType> :: ~arrayList(){
	delete [] listArray;
}

template <class elemType>
bool arrayList <elemType> :: isEmpty () const{
	return (currentSize == 0);
}

template <class elemType>
bool arrayList <elemType> :: isFull () const{
	return (currentSize == maxSize);
}

template< class elemType>
int arrayList <elemType> :: listSize () const{
	return currentSize;
}

template< class elemType>
int arrayList <elemType> :: maxListSize () const{
	return maxSize;
}

template< class elemType>
void arrayList <elemType> :: print () const{

	cout << "***Printing Array List***" << endl;
	for (int i = 0; i < currentSize; i++){
		cout << listArray [i] << " ";
	}
	cout << endl;
	cout << "List Size: " << currentSize << endl;
	cout << "***  ***" <<endl;
}

template <class elemType>
bool arrayList <elemType> :: isItemAtEqual (int loc,const elemType& ob) const{
	return (listArray [loc] == ob);
}

template <class elemType>
void arrayList <elemType> :: insertAt (int loc, elemType ob){
	if (loc < 0 || loc >= maxSize){
		cout << "ERROR: The location for the to-be inserted item is out of range" << endl;
	}

	else {
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

		currentSize ++;

		elemType *temp2 = new elemType [maxSize];
		for (int i = currentSize; i>loc; i--){
			temp2 [i] = listArray [i-1];
		}
		cout << "Inserting values" << endl;
		temp2[loc] = ob;
		for (int i = 0; i<loc; i++){
			temp2[i] = listArray [i];
		}

		delete [] listArray;
		listArray = temp2;


	}
}

template <class elemType>
void arrayList <elemType> :: insertEnd (elemType ob){
	if (currentSize == maxSize){

		cout<< "ERROR: Full List" << endl;
		cout << "Doubling maxSize now" << endl;
		maxSize = maxSize*2;
		cout << "maxSize is now: " << maxSize << endl;

		elemType *temp = new elemType [maxSize];

		for (int i = 0; i < currentSize; i++){
			temp [i] = listArray [i];
		}

		delete [] listArray; // no memory leaks
		cout << "Inserting values" << endl;


		listArray = temp;

		listArray [currentSize] = ob;
		currentSize++;

		cout << "Done Transfer" << endl;

	}
	else {
		cout << "Inserting values" << endl;
		listArray [currentSize] = ob;
		currentSize++;
	}
}

template <class elemType>
void arrayList <elemType> :: removeAt (int loc){
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
elemType arrayList <elemType> :: retreiveAt (int loc){

	return listArray [loc];
}

template <class elemType>
void arrayList <elemType> :: replaceAt (int loc, elemType ob){
	if (loc < 0 || loc >= currentSize){
		cout << "ERROR: Item to-be-removed's location is out of range" << endl;
		cout << "Location is either negative or does not hold any objects" << endl;

	}
	else{
		listArray [loc] = ob;
	}
}

template <class elemType>
void arrayList <elemType> :: clearList (){
	currentSize = 0;
}

template <class elemType>
arrayList <elemType> & arrayList <elemType> ::  operator = (const arrayList <elemType> &other){
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
unsigned int arrayList <elemType> :: seqSearchIter (elemType element){
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
unsigned int arrayList <elemType> :: seqSearchRec (elemType element, int i){
	if (i == listSize()){
		return 999;
	}
	if (listArray [i] == element){
		return i;
	}
	i++;
	return seqSearchRec (element, i);
}
#endif /* ARRAYLIST_H_ */
