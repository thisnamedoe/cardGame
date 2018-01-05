#pragma once
//obtained from lecture slides 

const int DEFAULT_LIST = 40;

template <class T>
class List {
public:

	//constructor for list that initalizes the parameter and the variables
	List<T>::List(unsigned capacity = DEFAULT_LIST) {
		m_max_capacity = capacity;
		m_container = new T [m_max_capacity];
		m_size = 0;
	}

	//destructor for list
	List<T>::~List() {
		}

	//checks if the list is empty, returns true if it is 
	bool List <T> ::isEmpty() const {
		return (m_size == 0);
	}

	//checks if the list is full, returns true if it is
	bool List <T> ::isFull() const {
		return (m_size == m_max_capacity);
	}

	//returns the size of the list
	unsigned List<T> ::getLength() const {
		return m_size;
	}

	//inserts an item into the list at a position 
	void List <T> ::insert(unsigned pos, T item)
	{

		if (m_size >= pos)
		{
			for (unsigned k = m_size; k >= pos; k--)
			{
				m_container[translate(k + 1)] = m_container[translate(k)];
			}
			m_container[translate(pos)] = item;
		}
		else
		{
			m_container[translate(pos)] = item;
		}
		m_size++;
	}

	//removes an item from the list
	T List<T> ::remove(unsigned pos){
		// PRECONDITION: the list is not empty,
		// and pos is between 1 and m_size
			T returnValue = m_container[translate(pos)];
			for (unsigned k = pos + 1; k <= m_size; k++)
				m_container[translate(k - 1)] = m_container[translate(k)];
			m_size--;
			return returnValue;
	}


	//retrieves an item from the list
	T List<T> ::retrieve(unsigned pos) const {
		// PRECONDITION: the list is not empty,
		// and pos is between 1 and m_size
		return m_container[translate(pos)];
	}

	//increases the maximum size of the list
	void List<T>::increaseMax()
	{
		m_max_capacity = m_max_capacity + 1;
		T * temp = new T [m_max_capacity];
		for (unsigned k = 1; k <= m_size; k++)
		{
			temp[k] = m_container[k];
		}
		m_container = temp;
		delete[] temp;
	}


	//private members of the list
private:
	T *m_container;
	unsigned m_max_capacity;
	unsigned m_size;	
	inline unsigned translate(unsigned pos) const { return pos - 1; }	
	
};