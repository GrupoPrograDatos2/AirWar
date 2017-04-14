#ifndef ENLAZADA_H
#define ENLAZADA_H
#include "Nodo.h"
#include <cstddef>

using namespace std;

class LinkedList
{
    public:
        LinkedList();
        virtual ~LinkedList();
        int getSize();
        int getPos();
        void goToStart();
        void goToEnd();
        void next();
        void insert(int element); //inserta un elemento en la posición curr
        void append(int element);
        int remove();
        void print();
        void clear();
        void reverse();
        void move(int pos);
        int getValue(int pos);

    protected:
        Nodo* first; //Head
        Nodo* last; //Tail
        Nodo* curr; //Actual
        int size;
        int pos;
};

#endif // ENLAZADA_H
