//============================================================================
// Name        : lab2.cpp
// Author      : Danielle Shen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctype.h>

using namespace std;
#include "arrayList.h"

int main() {

	cout << "intTest" << endl;

	arrayList<int> intTest;
	cout << "intTest2" << endl;
	arrayList<int> intTest2;

	intTest2 = intTest;
	cout << "intTest2: " << endl;
	intTest2.print ();

	if (intTest.isEmpty()){
		cout << "The array list is empty" << endl;
	}
	else {
		cout << "The array list is NOT empty" << endl;
	}

	if (intTest.isFull()){
		cout << "The array list is full" << endl;
	}
	else {
		cout << "The array list is NOT full" << endl;
	}

	cout << "Using listSize Function size is: " << intTest.listSize () << endl;

	cout << "Using maxListSize Function max size is: " << intTest.maxListSize () << endl;

	if (intTest.isItemAtEqual (0, 1)){
		cout << "Using isItemAtEqual: There is a 1 in the first element" << endl;
	}
	else{
		cout << "Using isItemAtEqual: There is NOT a 1 in the first element" << endl;

	}

	cout << endl;

	cout << "Using insertAt Function: Insert 2 into the second spot" << endl;
	intTest.insertAt(1,2);
	intTest.print ();

	cout << "Using insertEnd function: Insert 0 into the end" << endl;
	intTest.insertEnd(0);
	cout << "list size: " << intTest.listSize() << endl;
	intTest.print ();

	cout << "Using removeAt: removing the first element" << endl;
	intTest.removeAt(0);
	intTest.print ();

	cout<< "Using retrieveAt: Retrieve the first element: " << intTest.retreiveAt (0) << endl;

	cout << "Using replaceAt: Replacing the first element with 0" << endl;
	intTest.replaceAt(0,0);
	intTest.print ();

	cout << endl;

	cout << "Using listSize Function size is: " << intTest.listSize () << endl;

	cout << "Using maxListSize Function max size is: " << intTest.maxListSize () << endl;

	cout << endl;

	cout << "Using clearList: clearing intTest" << endl;
		intTest.clearList ();
		intTest.print ();
	if (intTest.isEmpty()){
		cout << "The array list is empty" << endl;
	}
	else {
		cout << "The array list is NOT empty" << endl;
	}

	return 0;
}

