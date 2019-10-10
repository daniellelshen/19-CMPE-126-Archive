//============================================================================
// Name        : 1.cpp
// Author      : Danielle Shen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "hashtable.h"
#include "hashtablechaining.h"

int main() {
	HashT<int> myTable(9);
	myTable.print();
	if(	myTable.insert(9)){
		cout << "Success :)" << endl;
	}
	else{
		cout << "fail :(" << endl;
	}
	cout <<"DeleteT: " << myTable.deleteT(9) << endl;
	if(	myTable.insert(12)){
		cout << "Success :)" << endl;
	}
	else{
		cout << "fail :(" << endl;
	}
	myTable.print();
	cout << myTable.search(12) << endl;
	cout << myTable.search (6) << endl;
	if (myTable.search(20) == 20){
		cout << "Success :)" << endl;
	}
	else{
		cout << "fail :(" << endl;
	}

	HashTableChaining<int> myTableChain (10);
	cout << "###Testing Insert###" << endl;

	cout << "Insert: " << myTableChain.insert(50) << endl;
	myTableChain.print();
	cout << "###Testing Insert###" << endl;
	myTableChain.insert(20);
	myTableChain.print();
	cout << "###Testing Insert Bool###" << endl;
	cout << "Insert: " << myTableChain.insert(50) << endl;
	myTableChain.print();
	cout << "search: " <<myTableChain.search(50) << endl;
	cout << "delete: " << myTableChain.deleteT(20) << endl;
	myTableChain.print();


}
