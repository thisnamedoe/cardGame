#pragma once
//obtained from the lecture slides

#include "LinkedList.h"
template <class T>
class Queue {
public:
	//default constructor, nothing is required
	Queue<T>::Queue() {}

	//default destructor
	Queue<T>::~Queue() {}

	//checks to see if the queue is empty
	bool Queue<T> ::isEmpty() const {
		return m_container.isEmpty();
	}

	//checks to see if the queue is full
	bool Queue<T> ::isFull() const {
		return false;
	}

	//adds an item into the queue at the end
	void Queue<T> ::enqueue(T k) {
		m_container.addTail(k);
	}

	//removes an item from the at the beginning
	T Queue<T> ::dequeue() {
		// precondition: queue must not be empty already
		return m_container.removeHead();
	}

	//returns the item on top of the queue
	T Queue<T> ::peek() const {
		// precondition: queue must not be empty already
		return m_container.retrieveHead();
	}

	//private members of the queue 
private:
	LinkedList<T> m_container; //a linkedlist variable named m_container
};
