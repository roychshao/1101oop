#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>
using namespace std;

template<typename T>
struct type {
	T Data;
	type<T> *previous;
	type<T> *next;
};

//	define class Queue
template<class T>
class Queue {

public:
	Queue();
	~Queue();
	Queue(const Queue<T> &obj);
	Queue &operator=(const Queue<T> &obj);
	void Enqueue(T);	// enqueue function
	void Dequeue();		// dequeue function

private:
	type<T> *head;	// head and tail pointer with template type
	type<T> *tail;
};

#endif 	// _QUEUE_H
