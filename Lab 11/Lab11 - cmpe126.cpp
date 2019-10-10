//============================================================================
// Name        : Lab11.cpp
// Author      : Danielle Shen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "treeheap.h"

int main() {
	int myArray[3] = {1, 3, 6};
	treeHeap <int> myHeap;
//	cout << myArray[2] << endl;
	myHeap.buildHeap(myArray, 3);

	myHeap.print();

	const nodeType <int> *out;
 //   nodeType <int> *none;
    cout << "Checking for 1..." << endl;
	out = myHeap.dfs(1);
    if (out == NULL) {
        cout << "nothing found" << endl;
     } else {
	    cout << "DFS: result/out: " << out << " : " << out-> info<< endl;
     }

    cout << "Checking for 6..." << endl;
    out = myHeap.dfs(6);
    if (out == NULL) {
        cout << "nothing found" << endl;
     } else {
	    cout << "DFS: result/out: " <<out << " : " << out-> info<< endl;
     }

    cout << "Checking for 1..." << endl;
	out = myHeap.bfs(1);
    if (out == NULL) {
        cout << "nothing found" << endl;
     } else {
	    cout << "BFS: result/out: " << out << " : " << out-> info<< endl;
     }

    cout << "Checking for 6..." << endl;
    out = myHeap.bfs(6);
    if (out == NULL) {
        cout << "nothing found" << endl;
     } else {
	    cout << "BFS: result/out: " <<out << " : " << out-> info<< endl;
     }


	myHeap.~treeHeap();
	myHeap.print();
}
