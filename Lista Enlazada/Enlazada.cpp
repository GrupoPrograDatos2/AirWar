#include "Enlazada.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>
using namespace std;

LinkedList::LinkedList()
{
    ///Constructor
    first = new Node();
    last = first;
    curr = first;
    size = 0;
}

LinkedList::~LinkedList()
{
    ///Destructor
    clear();
}

int LinkedList::getSize()
{
    ///Retorna el tamaño de la lista
    return size;
}

int LinkedList::getPos()
{
    ///Retorna la posicion actual de la lista
    return pos;
}

void LinkedList::goToStart()
{
    ///Se mueve al inicio de la lista
    curr = first;
}

void LinkedList::goToEnd()
{
    ///Se mueve al final de la lista
    curr = last;
}

void LinkedList::next()
{
    ///Moverse a la siguiente posicion
    curr = curr->getNext();
    pos++;
}

void LinkedList::insert(int element)
{
    ///Inserta un elemento
    Node* newNode = new Node(element, NULL);
    newNode->setNext(curr->getNext());
    curr->setNext(newNode);

    if(curr==last)
    {
        last = last->getNext();
    }

    size++;
}

void LinkedList::append(int element)
{
    ///Inserta un elemento al final de la lista
    if(size==0)
    {
        goToEnd();
        insert(element);
    }
    else
    {
        move(size);
        insert(element);
    }
}

int LinkedList::remove()
{
    ///Elimina un elemento
    if(curr==last)
    {
        throw runtime_error("No hay elementos en la lista");
    }

    Node* change = curr;
    next();
    int value = curr->getValue();
    change->setNext(curr->getNext());
    size--;

    return value;
}

void LinkedList::print()
{
    ///Imprime la lista
    goToStart();

    for(int i=0; i<size; i++)
    {
        curr = curr->getNext();
        cout << curr->getValue() << " ";
    }

    cout << endl;
}

void LinkedList::clear()
{
    ///Limpia la lista
    goToStart();

    for(int i=0; i<size; i++)
    {
        Node* temp = curr;
        next();
        delete temp;
    }

    first = new Node();
    last = first;
    curr = first;
    size = 0;
    pos = 0;
}

void LinkedList::reverse()
{
    ///Voltea la lista
    goToStart();
    int listAux[100];

    for(int i=0; i<size; i++)
    {
        curr = curr->getNext();
        listAux[i] = curr->getValue();
    }

    int tam = size;
    clear();

    for(int i=tam-1; i>=0; i--)
    {
        append(listAux[i]);
    }

    delete[] listAux;
}

void LinkedList::move(int pos)
{
    ///Mueve curr a cualquier posicion
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

int LinkedList::getValue(int pos)
{
    ///Retorna el valor del elemento
    move(pos);
    return curr->getValue();
}
