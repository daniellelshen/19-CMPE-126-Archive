/*
 * stlInfixPostfix.h
 *
 *  Created on: Mar 11, 2019
 *      Author: Danielle Shen
 */

#ifndef STLINFIXPOSTFIX_H_
#define STLINFIXPOSTFIX_H_
#include <stack>
#include <string>

using namespace std;

void stlReadLine (string toRead);
void readSymbols(char c, stack<char> & opr);
bool isMultiDiv(char k);
bool isPlusMinus(char t);
void MultiDiv(char c, stack<char> &opr);
void PlusMinus(char c, stack<char> &opr);



#endif /* STLINFIXPOSTFIX_H_ */
