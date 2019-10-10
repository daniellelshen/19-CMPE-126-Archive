/*
 * arrayStack.h
 *
 *  Created on: Mar 11, 2019
 *      Author: Danielle Shen
 */

#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_

template <class Type>
class arrayStack
{
public:
	arrayStack(int stackSize);
	void initializeStack();
	bool isEmptyStack() const;

	//	bool isFullStack () const;

	int size();
	int maxSize();
	void push (const Type& newItem);
	// add to the end of the array
	// check array size
	// insert end from arraylist.h lab 3
	Type top() const;
	// retrieveAt (int size-1) lab 3
	void pop();
	// add to the end of the array
	// retrieveAt (int size -1)
	// removeAt (int size-1)
	// size -- ((verify))
	void empty();
	// size = 0;
	// delete list

private:

	int maxStackSize;
	int stackTop;
	Type *list;

};

template <class Type>
arrayStack<Type>::arrayStack(int stackSize)	{
	if (stackSize < 1)
	{
		throw "Error: Size must be positive";
	}
	maxStackSize = stackSize;

	stackTop = 0;
	list = new Type[maxStackSize];
}

template <class Type>
void arrayStack <Type> :: initializeStack(){
	stackTop = 0;
	maxStackSize = 10;
}


template <class Type>
bool arrayStack <Type> :: isEmptyStack() const{
	return (stackTop == 0);
}

template <class Type>
int arrayStack <Type> :: size() {
	return (stackTop);
}

template <class Type>
int arrayStack <Type> :: maxSize(){
	return (maxStackSize);
}

template <class Type>
void arrayStack <Type> :: push(const Type& newItem){
	if (stackTop == maxStackSize){
		maxStackSize = maxStackSize*2;
		Type * tmp = list;
		list = new Type[maxStackSize];
		for(int i=0; i < stackTop; ++i){
			list[i] = tmp[i];
		}
		delete[] tmp;
		list[stackTop++] = newItem; //add newItem at the top
	}
	else {
		list[stackTop++] = newItem; //add newItem at the top
	}
}

template <class Type>
Type arrayStack <Type> :: top() const {
	if (stackTop != 0){
		return (list [stackTop - 1]);
	}
	throw "Error: Stack is empty.";
}

template <class Type>
void arrayStack <Type>::pop()
{
	if (isEmptyStack()){
		throw "Cannot remove from an empty stack.";
	}
	stackTop--;
}

template <class Type>
void arrayStack <Type> :: empty (){
	delete [] list;
	stackTop = 0;
}

#endif /* ARRAYSTACK_H_ */
