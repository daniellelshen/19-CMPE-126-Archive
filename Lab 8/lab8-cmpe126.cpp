//============================================================================
// Name        : lab8-cmpe126.cpp
// Author      : Danielle Shen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "arrayList.h"
#include "sortedarrayList.h"
#include "sortedLinkedList.h"
int main() {
	sortedarrayList<int> intTest;

	intTest.insert(6);
	intTest.print();

	cout << "seqIter: 6 is found at "<< intTest.seqSearchIter(6) << endl;
	cout << "seqRec: 6 is found at "<< intTest.seqSearchRec(6, 0) << endl;
	cout << "binIter: 5 is found at "<< intTest.binSearchIter (5) << endl;
	cout << "binRed: 5 is found at " << intTest.binSearchRec(5, 0, intTest.listSize()) << endl;

	linkedList<int> intLLTest;
	intLLTest.insert (4);
	intLLTest.insert(6);
	intLLTest.insert (2);

	if (intLLTest.seqSearchIter (2)){
		cout << "SeqSearchIter: True" << endl;
	}
	else{
		cout << "SeqSearchIter: False" << endl;
	}


//	struct nodeType<int>* head = NULL;
//	    int x = 21;
//
//	    /* Use push() to construct below list
//	     14->21->11->30->10  */
//	    push(&head, 10);
//	    push(&head, 30);
//	    push(&head, 11);
//	    push(&head, 21);
//	    push(&head, 14);

	if (intLLTest.seqSearchRec (2, intLLTest.getHead())){
		cout << "SeqSearchRec:  True" << endl;
	}
	else{
		cout << "SeqSearchRec: False" << endl;
	}



}
