/*
 * myInfixPostfix.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: Danielle Shen
 */

#include <iostream>
#include "arrayStack.h"

using namespace std;

void myReadLine(string toRead) {
	arrayStack <char> opr(10);
	opr.initializeStack();
	//	char p;
	for (unsigned int i = 0; i < toRead.length(); i++) {
		char c = toRead[i];


		if (c == '*' || c == '/'){

			if (opr.isEmptyStack() ){
				opr.push (c);
			}
			else if ( opr.top() == '*' || opr.top() == '/'){
				cout << opr.top() << " ";
				opr.pop();
				opr.push(c);
			}
			else{
				opr.push(c);
			}
		}

		else if (c == '+' || c == '-'){
			if (opr.isEmptyStack() ){
				opr.push (c);
			}
			else if ( opr.top() == '('){
				opr.push(c);
			}
			else{
				cout << opr.top() << " ";
				opr.pop();
				//	    		cout << c << " in else of + and -" << endl;
				opr.push(c);
			}
		}

		else if (c == '('){
			opr.push (c);
		}

		else if (c == ')'){
			while (opr.top() != '('){
				cout << opr.top() << " ";
				opr.pop();
			}
			opr.pop();
		}

		else if (c == ' ')
		{ continue;
		}
		else if (c == ';'){
			while (!opr.isEmptyStack()){
				cout << opr.top() << " ";
				opr.pop();
			}
		}
		else {
			cout << c <<" ";
		}

	}

}

//void myreadLine(string toRead);



