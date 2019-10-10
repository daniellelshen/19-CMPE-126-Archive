/*
 * stlInfixPostfix.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: Danielle Shen
 */

#include <iostream>
#include "stlInfixPostfix.h"

using namespace std;

void stlReadLine(string toRead) {
	stack<char> opr;
	//	char p;
	for (unsigned int i = 0; i < toRead.length(); i++) {
		char c = toRead[i];

		readSymbols(c, opr);

	}
}

bool isMultiDiv(char k) {
	if (k == '*' || k == '/'){
		return true;
	}
	else{
		return false;
	}
}

bool isPlusMinus(char t) {
	if (t == '+' || t == '-'){
		return true;
	}
	else {
		return false;
	}
}

void MultiDiv(char c, stack<char> &opr) {
	if (opr.empty()) {
		opr.push(c);
	} else if (opr.top() == '*' || opr.top() == '/') {
		cout << opr.top() << " ";
		opr.pop();
		opr.push(c);
	} else {
		opr.push(c);
	}
}

void PlusMinus(char c, stack<char> &opr) {
	if (opr.empty()) {
		opr.push(c);
	} else if (opr.top() == '(') {
		opr.push(c);
	} else {
		cout << opr.top() << " ";
		opr.pop();
//		cout << c << " in else of + and -" << endl;
		opr.push(c);
	}
}

void readSymbols(char c, stack<char> &opr) {
	if (isMultiDiv(c) == true) {
		MultiDiv(c, opr);
	}

	else if (isPlusMinus(c) == true) {
		PlusMinus(c, opr);
	}

	else if (c == '(') {
		opr.push(c);
	}

	else if (c == ')') {
		while (opr.top() != '(') {
			cout << opr.top() << " ";
			opr.pop();
		}
		opr.pop();
	}

	else if (c == ' ') {
		return;
	} else if (c == ';') {
		while (!opr.empty()) {
			cout << opr.top() << " ";
			opr.pop();
		}
	} else {
		cout << c << " ";
	}
}
