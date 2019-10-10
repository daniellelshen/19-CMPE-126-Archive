//============================================================================
// Name        : lab6-cmpe126.cpp
// Author      : Danielle Shen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "stlInfixPostfix.h"
#include "myInfixPostfix.h"
#include "arrayStack.h"

using namespace std;

int main() {
	string test;
	test = "a * b + c - ( e + d * f - 3/7 + (3-7*(3+8)+3))-9;";
	stlReadLine (test);
	cout << endl;

	arrayStack <char> testS (20);
	string test2;
	test2 = "A * (B + C * D) + E/F-G;";
	myReadLine(test2);
}
