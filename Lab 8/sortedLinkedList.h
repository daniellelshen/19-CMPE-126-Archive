/*
 * sortedlinkedList.h
 *
 *  Created on: Feb 25, 2019
 *      Author: danie
 */

#ifndef SORTEDLINKEDLIST_H_
#define SORTEDLINKEDLIST_H_

using namespace std;
#include <iostream>

template <class elemType>
struct nodeType {
	elemType info;
	nodeType <elemType> *link;
};

template <class elemType>
class linkedList
{
public:
	linkedList ();
	elemType elem;
	//	linkedList <elemType> *next;
	void initializeList ();
	virtual ~linkedList();
	bool isEmpty () const;
	bool isFull () const;
	int listSize () const;
	nodeType <elemType>* getHead();
	int maxListSize ()  const;
	void print () const;
	bool isItemAtEqual (int, const elemType& ) const;

	void insert (elemType);

	void remove (elemType);
	elemType retreiveAt (int);

	void clearList ();
	const linkedList <elemType> & operator = (const linkedList <elemType> &otherList);

	bool seqSearchIter (elemType element);
	bool seqSearchRec (const elemType& element, nodeType<elemType>* current);



protected:
	int count;

	nodeType <elemType> *first;
	//	nodeType <elemType> *last;

private:
	void copyList(const linkedList<elemType> &list);


};



template <class elemType>
linkedList <elemType> :: linkedList(){

	first = NULL;
	//last = NULL;
	count = 0;


}


template <class elemType>
linkedList <elemType> :: ~linkedList(){
	nodeType <elemType> *temp;
	while (first != NULL){
		temp = first;
		first = first -> link;
		delete temp;
	}
	count = 0;
}

template <class elemType>
bool linkedList <elemType> :: isEmpty () const{
	return (count == 0);
}

template <class elemType>
bool linkedList <elemType> :: isFull () const{
	return (false );
}

template< class elemType>
int linkedList <elemType> :: listSize () const{
	return count;
}

template<class elemType>
nodeType <elemType>* linkedList<elemType> ::getHead(){
	return first;
}

template< class elemType>
int linkedList <elemType> :: maxListSize () const{
	return 999 ;
}

template< class elemType>
void linkedList <elemType> :: print () const{

	cout << "***Printing Linked Array List***" << endl;
	nodeType <elemType> *temp;
	temp = first;
	while (temp != NULL){
		cout << temp->info << " " ;
		temp = temp -> link;
	}
	cout << endl;

	delete temp;
}

template <class elemType>
bool linkedList <elemType> :: isItemAtEqual (int loc,const elemType& ob) const{

	nodeType <elemType> *current;
	current = first;
	//int nodeCount = count;
	if (loc > count || loc < 0) {
		cout << "Location is outside of range" << endl;
		return false;
	}
	else{
		for (int i = 1; i < loc; i++){
			current = current -> link;
		}

	}
	elemType result = current -> info;
	delete current;
	return (result == ob);

}
template <class elemType>
void linkedList <elemType> :: insert (elemType ob){
	nodeType <elemType> *newNode;
	nodeType <elemType> *previous ;
	nodeType <elemType> *current;

	bool found;

	newNode = new nodeType <elemType>;
	newNode -> info = ob;
	newNode ->link = NULL;

	if (first == NULL){
		first = newNode;

	}
	else{
		current = first;
		found = false;
		while (current != NULL && !found){
			if (current -> info <= ob){
				found = true;
			}
			else {
				previous = current;
				current = current -> link;
			}

		}
		if (current == first){
			newNode -> link = first;
			first = newNode;

		}
		else{
			previous -> link = newNode;
			newNode -> link = current;
		}


	}
	count++;
}


template <class elemType>
void linkedList <elemType> :: remove (elemType ob){
	nodeType <elemType> *previous ;
	nodeType <elemType> *current;

	bool found;

	if (first == NULL){
		cout << "Cannot remove from an empty list" << endl;

	}
	else{
		current = first;
		found = false;
		while (current != NULL && !found){
			if (current -> info == ob){
				found = true;
			}
			else {
				previous = current;
				current = current -> link;
			}

		}


		if (current == NULL){
			cout << "The item to be deleted is not located in the list" << endl;
		}
		else{
			if (current -> info == ob){
				if (first == current){
					first = first -> link;
					delete current;
				}
				else{
					previous ->link = current -> link;

					delete current;
				}
			}
			count--;
		}

	}

}

template <class elemType>
elemType linkedList <elemType> :: retreiveAt (int loc){

	nodeType <elemType> *current;
	current = first;
	//int nodeCount = count;
	if (loc > count) {
		cout << "Location is outside of range, returning error value" << endl;
		return -999;
	}
	else{
		for (int i = 1; i < loc; i++){
			current = current -> link;
		}
		return current -> info;
	}


}

template <class elemType>
void linkedList <elemType> :: clearList (){

	nodeType <elemType> *temp;
	while (first != NULL){
		temp = first;
		first = first -> link;
		delete temp;
	}
	count = 0;
}

template <class elemType>
const linkedList <elemType> &linkedList <elemType> :: operator = (const linkedList <elemType>&list){
	cout << "Using Operator =: " << endl;

	if (this != & list){
		copyList (list);
	}

	return *this;

}

template <class elemType>
void linkedList <elemType> :: copyList(const linkedList<elemType> &otherList){
	nodeType <elemType> *newNode;
	nodeType <elemType> *current;
	nodeType <elemType> *newCurrent; // temporary pointer for new list

	if(first != NULL){
		clearList();
	}

	if (otherList.first == NULL){
		first = NULL;
		count = 0;
	}
	else {
		current = otherList.first;
		count = otherList.count;

		first = new nodeType <elemType>;
		first -> info = current -> info; // transferring data over
		first -> link = current -> link;
		current = current -> link;
		newCurrent = first; // temporary pointer points to first node of new list

		while (current !=NULL){
			newNode = new nodeType <elemType>;
			newNode -> info = current -> info;
			newNode -> link = NULL;
			newCurrent -> link = newNode;  // update link for previous node in new list
			newCurrent = newNode;            // update temporary pointer to next item
			current = current -> link;
		}
	}
}

template <class elemType>
bool linkedList <elemType> ::seqSearchIter (elemType element){
	if (count == 0){
		return false;
	}

	nodeType <elemType> *temp;
	temp = first;
	while (temp != NULL){
		if (temp->info == element){
			delete temp;
			return true;
		}
		temp = temp -> link;
	}
	delete temp;
	return false;
}

template <class elemType>
bool linkedList <elemType> ::seqSearchRec (const elemType& element, nodeType<elemType>* current){
if(current == NULL){
	return false;
}
if(current->info == element){
	return true;
}
else{
return seqSearchRec (element, current->link);
}
// TODO : figure out how to do this
}


#endif /* SORTEDLINKEDLIST_H_ */
