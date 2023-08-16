#include "Node.hpp"

Node::Node() {}
Node::Node(AMateria *materia) : materia(materia), next(0) {}
Node::Node(Node& copy)
{
	materia = copy.materia->clone();
	next = 0;
}
Node& Node::operator=(Node& ref)
{ 
	materia = ref.materia->clone();
	next = 0;
	return (*this);
}
Node::~Node() { delete materia; }