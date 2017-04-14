#include "Node.h"
#include <cstddef>
using namespace std;

Node::Node(int value, Node* next)
{
    ///Constructor
    this->value = value;
    this->next = next;
}

Node::Node(Node* next)
{
    ///Constructor
    this->next = next;
}

Node::~Node()
{
    ///Destructor
    //dtor
}

int Node::getValue()
{
    ///Retorna el valor del nodo actual
    return value;
}

Node* Node::getNext()
{
    ///Apunta al siguiente nodo
    return next;
}

void Node::setNext(Node* node)
{
    ///Apunta a un nuevo nodo
    next = node;
}
