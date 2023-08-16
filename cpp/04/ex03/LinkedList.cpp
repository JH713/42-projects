#include "LinkedList.hpp"

LinkedList::LinkedList() : head(0) {}
LinkedList::LinkedList(LinkedList& copy) : head(copy.head) {}
LinkedList& LinkedList::operator=(LinkedList& ref)
{ 
	head = ref.head;
	return (*this);
}
LinkedList::~LinkedList() 
{
	Node *current = head;
	while (current != 0)
	{
		Node *next = current->next;
		delete current;
		current = next;
	}
}

void LinkedList::append(AMateria *materia)
{
	Node *newNode = new Node(materia);
	if (head == 0)
		head = newNode;
	else
	{
		Node* curr = head;
		while (curr->next != 0)
			curr = curr->next;
		curr->next = newNode;
	}
}