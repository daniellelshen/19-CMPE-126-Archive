//============================================================================
// Name        : lab4-cmpe.cpp
// Author      : Danielle Shen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "sortedLinkedList.h"

int main() {

	linkedList<int> intTest;
	cout << " " << intTest.listSize() << endl;

	if (intTest.isEmpty()){
			cout << "The array list is empty" << endl;
		}
		else {
			cout << "The array list is NOT empty" << endl;
		}


	intTest.insert (4);

	cout << " " << intTest.listSize() << endl;
	intTest.insert(10);
	cout << " " << intTest.listSize() << endl;
	intTest.print ();
	intTest.insert (2);

	intTest.print ();

	cout << " " << intTest.listSize() << endl;

	linkedList <int> intTest2;
	intTest2 = intTest;
	cout << "intTest2" << endl;
	intTest2.print();

	cout << "RetreieveAt: " << intTest.retreiveAt (1) << endl;
	intTest.remove(4);
	intTest.print ();

	intTest.remove (7);
	intTest.print ();

//	intTest2.print();

	if (intTest.isItemAtEqual(1,10)){
			cout << "The array list is equal" << endl;
		}
		else {
			cout << "The array list is NOT equal" << endl;
		}
intTest2.print();

}
