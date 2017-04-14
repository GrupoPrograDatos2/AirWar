#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include "Node.h"

class LinkedQueue
{
    public:
        LinkedQueue();
        virtual ~LinkedQueue();
        void enqueue(Node* Navecita);
        Node* dequeue();
        //int getFront();

        void goToStart();
        void goToEnd();
        void next();
        void insert(Node* newNode); //inserta un elemento en la posición curr
        void print();
        void move(int pos);
        //int getValue(int pos);

    protected:
        Node* first; //head
        Node* last; //tail
        Node* curr; //current
        int size;
        int pos;
};

#endif // LINKEDQUEUE_H
