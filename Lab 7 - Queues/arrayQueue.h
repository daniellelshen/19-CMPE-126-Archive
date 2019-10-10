/*
 * arrayQueue.h
 *
 *  Created on: Mar 18, 2019
 *      Author: Danielle Shen
 */

#ifndef ARRAYQUEUE_H_
#define ARRAYQUEUE_H_
#include <iostream>
using namespace std;

template <class T> class arrayQueue {


public:
	arrayQueue (int sizeOfQueue);
	void enqueue(T elem);
	T dequeue();
	T front();
	int size();
	int maxSize();
	bool isEmpty();
	bool isFull();
	void print();

private:
	T* queue;
	int length;
	int frontOfQueue;
	int backOfQueue;

};

template <class T> arrayQueue <T> :: arrayQueue(int sizeOfQueue) {
	if (sizeOfQueue < 1) {
		throw "ERROR: Size of queue cannot be 0.";
	}
	length = sizeOfQueue;

	frontOfQueue = -1;
	backOfQueue = -1;
	queue = new T[length];
}

template <class T> int arrayQueue <T> :: maxSize(){
	return length;
}

template <class T> void arrayQueue <T> :: enqueue(T elem) {

	if (isFull()) {
//		cout << "FULL" << endl;
		length = length +2;
//		cout << "length " << length << endl;
//		cout << "maxSize " << maxSize() << endl;
		//throw "ERROR: Full queue.";
//		cout << "full- back: " << backOfQueue << endl;

	}

	backOfQueue++;
//	cout << "back: " << backOfQueue << endl;
	if (backOfQueue == length){
		length = length +2;
	}
	backOfQueue %= length;


//	cout << " back: " << backOfQueue << endl;
	// use the modulous operator for wrap around
	queue[backOfQueue] = elem;

	if (frontOfQueue == -1) {
		frontOfQueue = backOfQueue;
	}

}

template <class T> T arrayQueue <T> :: dequeue() {
	if (isEmpty()) {
		throw "ERROR: Empty queue.";
	}
	T num = queue[frontOfQueue];

	if (frontOfQueue == backOfQueue) {
		frontOfQueue = backOfQueue = -1;
	}
	else {
		frontOfQueue++;
		frontOfQueue %= length;
	}
	return num;
}

template <class T> T arrayQueue <T> :: front() {
	if (isEmpty()) {
		throw "ERROR: Empty queue.";
	}
	return queue[frontOfQueue];

}

template <class T> int arrayQueue <T> :: size() {
	return (length - frontOfQueue + backOfQueue) % length + 1;
}

template <class T> bool arrayQueue <T> :: isEmpty() {
	return (frontOfQueue == -1);
}

template <class T> bool arrayQueue <T> :: isFull() {
	return (((backOfQueue + 1) % length) == frontOfQueue);
}

template <class T> void arrayQueue <T> :: print() {
	int i = frontOfQueue;
	while (i != backOfQueue+1) {
		cout << queue[i] << " ";
		i++;
		i %= length;
	}
	cout << "\n";
}




#endif /* ARRAYQUEUE_H_ */
