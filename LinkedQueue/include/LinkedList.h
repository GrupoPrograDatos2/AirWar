#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
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
        Node* first; //head
        Node* last; //tail
        Node* curr; //current
        int size;
        int pos;
};

#endif // LINKEDLIST_H
