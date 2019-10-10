//============================================================================
// Name        : Lab10.cpp
// Author      : Danielle Shen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "maxheap.h"

int main() {
	maxHeap<char> myHeap (4);

	myHeap.insert('f');
	myHeap.insert('r');
	myHeap.insert('a');
	myHeap.insert('y');
	myHeap.print();
	myHeap.sort();
	cout << "After Sort: " << endl;
	myHeap.print();



	cout << "Search: " << myHeap.search('a') << " " << endl;
}
