#include "LinkedStack.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedStack::LinkedStack():LinkedList()
{
    ///Constructor
    //ctor
}

LinkedStack::~LinkedStack()
{
    ///Destructor
    LinkedList::goToStart();

    for(int i=0; i<size; i++)
    {
        LinkedList::remove();
    }
    delete first;
    delete curr;

    size = 0;
    pos = 0;
}

void LinkedStack::push(int value)
{
    ///Inserta un elemento en la pila
    LinkedStack::append(value);
}

int LinkedStack::pop()
{
    ///Saca un elemento de la pila
    if(isEmpty())
    {
        cout << "La lista esta vacia" << endl;
    }
    else
    {
        LinkedList::move(size-1);
        int stackValue = LinkedList::remove();
        return stackValue;
    }
}

int LinkedStack::topValue()
{
    ///Saca un elemento de la pila
    int stackValue = LinkedList::getValue(size);
    return stackValue;
}

bool LinkedStack::isEmpty()
{
    ///Retorna un 0 ó 1 si la pila está vacía
    bool exit = false;

    if(size==0)
    {
        exit = true;
    }

    return exit;
}
