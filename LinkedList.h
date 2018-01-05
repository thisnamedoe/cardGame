#pragma once
//obtained from lecture slides

//templated so it functions like a vector
template <class Item>

//declaration for class linked list
class LinkedList {

	//private members
private:
	//another class of type Node is a private member of LinkedList
	class Node { 
	//Node contains the current Item, and the next pointer which points to the next item on the list
	public:
		Node(Item val, Node * nx = NULL) : value(val), next(nx) { }
		Item value;
		Node * next;
	};

	//public members
public:
	
	//constructor for LinkedList that initalizes the head and tail pointers to null and the size to 0
	LinkedList<Item>::LinkedList() : m_head(NULL), m_tail(NULL), m_size(0)
	{
	}

	//deconstructor for LinkedList that destroys the nodes
	LinkedList<Item> :: ~LinkedList() {
		Node * here = m_head, *nextNode;
		while (here != NULL) {
			nextNode = here->next;
			delete here;
			here = nextNode;
		}
	}

	//returns the size of the linked list
	unsigned int LinkedList<Item> ::size() const {
		return m_size;
	}

	//checks if the linked list is empty
	bool LinkedList<Item> ::isEmpty() const {
		return (m_size == 0); // true if list is empty, false otherwise 
	}
	
	//adds an item to the head of the linked list
	void LinkedList<Item> ::addHead(Item item) {
		m_head = new Node(item, m_head);
		if (m_tail == NULL) m_tail = m_head;
		m_size++;
	}

	//removes an item from the head of the linked list
	Item LinkedList<Item> ::removeHead() {
		// precondition: list is not already empty
		Node * oldNode = m_head;
		Item returnVal = m_head->value;
		m_head = m_head->next;
		if (m_head == NULL) m_tail = NULL;
		m_size--;
		delete oldNode;
		return returnVal;
	}

	//retrieves the item on the head of the linked list
	Item LinkedList<Item> ::retrieveHead() const 
	{
		// precondition: list is not already empty
		return m_head->value;
	}

	//adds an item to the tail of the linked list
	void LinkedList<Item> ::addTail(Item item) {
		if (isEmpty()) addHead(item);
		else {
			m_tail = m_tail->next = new Node(item);
			m_size++;
		}
	}

	//removes an item from the tail of the linked list
	Item LinkedList<Item> ::removeTail() {
		// precondition: list is not already empty
		if (m_head == m_tail) return removeHead();
		Node * preTail = m_head;
		Item returnVal = m_tail->value;
		while (preTail->next != m_tail)
			preTail = preTail->next;
		preTail->next = NULL;
		delete m_tail;
		m_tail = preTail;
		m_size--;
		return returnVal;
	}

	//retrieves an item from the tail of the linked list
	Item LinkedList<Item> ::retrieveTail() const 
	{
		// precondition: list is not already empty
		return m_tail->value;
	}

	//removes an item from a position of the linked list
	Item LinkedList<Item> ::remove(unsigned int n) {
		// precondition: n must be a valid current list position 1<=n<=size()
		if (n == 1)
			return removeHead();
		if (n == size())
			return removeTail();
		Node * here = m_head;
		for (unsigned int k = 1; k < n - 1; k++)
			here = here->next;
		Node * kill = here->next;
		Item returnVal = kill->value;
		here->next = kill->next;
		delete kill;
		m_size--;
		return returnVal;
	}

	//retrieves an item from a certain position in the linked list
	Item LinkedList<Item>::retrieve(unsigned int n) const {
		// precondition: n must be a valid current list position 1<=n<=size()
		if (n == 1) return retrieveHead();
		if (n == size()) return retrieveTail();
		Node * here = m_head;
		for (unsigned int k = 1; k < n; k++) here = here->next;
		return here->value;
	}
private:
	Node * m_head;
	Node * m_tail;
	unsigned int m_size;
};