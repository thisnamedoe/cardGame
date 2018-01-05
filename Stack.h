#pragma once
#include "List.h"

//This file is a linked list obtained from the powerpoint slides

template <class T>

//declaring class Stack
class Stack {
	//public members
public:

	//constructor for stack that initializes capacity to 40 
	Stack<T>::Stack(int capacity = 40) : m_container(capacity)
	{
	}

	//deconstructor for the stack
	Stack<T>::~Stack()
	{
	}

	//checks to see if the stack is empty
	bool Stack<T>::isEmpty() const {
		return m_container.isEmpty();

	}

	//obtains the size of the stick
	unsigned Stack<T>::size() const {
		return m_container.getLength();
	}

	//inserts an item into the stack onto the top
	void Stack<T>::push(T k) {
		m_container.insert(size() + 1, k);
	}

	//removes an item from the stack from the bottom
	T Stack <T> ::pop() {
		return m_container.remove(size());
	}

	//retrieves the top of the stack
	T Stack<T>::peek() const {
		return m_container.retrieve(size());
	}

	//private members
private:

	List<T> m_container; //type List variable named m_container that contains the stack
};
