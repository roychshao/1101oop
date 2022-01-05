#include <iostream>
#include "Queue.h"
#include "AnsiPrint.h"

template<class T>
Queue<T>::Queue() {
	head = NULL;
	tail = NULL;
}

// destructor
template<class T>
Queue<T>::~Queue() {
}

// copy constructor
template<class T>
Queue<T>::Queue(const Queue<T> &obj) {
	type<T> *tmp = obj.head;
	while(tmp != NULL)
	{
		Enqueue(tmp->Data);
		tmp = tmp->next;
	}
}

// '=' overload
template<class T>
Queue<T>
&Queue<T>::operator=(const Queue<T> &obj) {
	head = obj.head;
	tail = obj.tail;
	return *this;
}

template<class T>
void
Queue<T>::Enqueue(T data) {
	try {
		// check if head and tail pointer are both point to right place
		// if not , throw back and print error message(Internal Error)
		if(head != NULL && tail != NULL)
		{
			if(head->previous || tail->next)
				throw "Internal Error happened.";
		}
		type<T> *tmp;
		// check if the allocate is bad allocate
		// if yes , throw back and print error message(Bad Allocate)
		try {
			tmp = new type<T>;
		}
		catch(bad_alloc &err) {
			throw "Bad Allocate happened.";
		}
		// insert struct data into linked list
		tmp->Data = data;
		tmp->previous = NULL;
		tmp->next = NULL;
		if(!head)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->next = tmp;
			tmp->previous = tail;
			tail = tmp;
		}
	}
	// catch error
	catch(const char *err) {
		AnsiPrint(err, red, white, false);
		cout << endl;
	}
}

template<class T>
void
Queue<T>::Dequeue() {
	try {
		// avoid dequeue empty queue
		if(!head)
			throw "Attempt to dequeue empty queue.";
		// remove struct data from linked list
		type<T> *next = head->next;
		if(!next)
		{
			cout << head->Data << endl;
			head = NULL;
		}
		else
		{	next->previous = NULL;
			cout << head->Data << endl;
			head = NULL;
			head = next;
		}		
	}
	catch(const char *err) {
		AnsiPrint(err, red, white, false);
		cout << endl;
	}
}

// Explicitly instantiate the template, and its member definitions
template struct type<int>;
template struct type<char>;
template class Queue<int>;
template class Queue<char>;

