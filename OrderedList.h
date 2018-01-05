#pragma once
#include <iostream>
#include "List.h"

//obtained from lecture slides

template <class T>
class OrderedList {


public:
	OrderedList<T>::OrderedList(unsigned cap) : m_container(cap)
	{
	}

	OrderedList<T>::~OrderedList()
	{
	}

	int OrderedList<T>::getLength() const
	{
		return m_container.getLength();
	}

	bool OrderedList<T>::isEmpty() const
	{
		return m_container.isEmpty();
	}

	T OrderedList<T>::remove(unsigned pos)
	{
		return m_container.remove(pos);

	}

	T OrderedList<T>::retrieve(unsigned pos) const 
	{
		return m_container.retrieve(pos);
	}

	int OrderedList<T>::insert(T item)
	{
		int k;
		if (m_container.isFull())
			m_container.increaseMax();
		for (k = 1; k <= m_container.getLength(); k++)
			if (item < retrieve(k))
				break;
		m_container.insert(k, item);
		return k;
	}

private:
	List<T> m_container; //pointer to array to hold list

};
