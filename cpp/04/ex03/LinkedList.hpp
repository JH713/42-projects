#ifndef LINKEDLIST_HPP
# define LINKEDLIST_HPP

#include "Node.hpp"

class LinkedList
{
private:
	Node* head;

	LinkedList(LinkedList& copy);
	LinkedList& operator=(LinkedList& ref);

public:
	LinkedList();
	~LinkedList();

	void append(AMateria *materia);
};

#endif