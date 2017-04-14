#include "LinkedQueue.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include "Node.h"
using namespace std;

LinkedQueue::LinkedQueue()
{
    //Constructor
    first = new Node();
    last = first;
    curr = first;
    size = 0;
}

LinkedQueue::~LinkedQueue()
{
    //Destructor
}

void LinkedQueue::enqueue(Node* Navecita) //Inserta un elemento en la cola
{
    goToEnd();
    insert(Navecita);
}

Node* LinkedQueue::dequeue() //Elimina un elemento en la cola
{
    goToStart();

    if(curr==last)
    {
        throw runtime_error("No hay elementos en la lista");
    }

    Node* change = curr;
    next();
    Node* Aux = curr;
    change->setNext(curr->getNext());
    size--;

    return Aux;
}
/*
int LinkedQueue::getFront() //Retorna el valor del primer elemento
{
    return getValue(1);
}
*/
void LinkedQueue::goToStart() //Se mueve al inicio de la lista
{
    curr = first;
}

void LinkedQueue::goToEnd() //Se mueve al final de la lista
{
    curr = last;
}

void LinkedQueue::next() //Se mueve a la siguiente posicion
{
    curr = curr->getNext();
    pos++;
}

void LinkedQueue::insert(Node* newNode) //Inserta un elemento
{
    newNode->setNext(curr->getNext());
    curr->setNext(newNode);

    if(curr==last)
    {
        last = last->getNext();
    }

    size++;
}



void LinkedQueue::move(int pos) //Mueve curr a cualquier posicion
{
    goToStart();
    this->pos = pos;

    if(pos>size)
    {
        throw runtime_error("La posicion esta fuera de la lista");
    }

    for(int i=0; i!=pos; i++)
    {
        next();
    }
}
/*
int LinkedQueue::getValue(int pos) //Retorna el valor del elemento
{
    move(pos);
    return curr->getValue();
}
*/
