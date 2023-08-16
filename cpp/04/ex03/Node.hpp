#ifndef NODE_HPP
# define NODE_HPP

#include "AMateria.hpp"

class Node {
private:
	Node();
public:
	AMateria *materia;
	Node *next;

	Node(AMateria *materia);
	Node(Node& copy);
	Node& operator=(Node& ref);
	~Node();
};

#endif