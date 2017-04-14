#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include "LinkedList.h"

class LinkedStack:public LinkedList
{
    public:
        LinkedStack();
        virtual ~LinkedStack();
        void push(int value);
        int pop();
        int topValue();
        bool isEmpty();

    private:
};

#endif // LINKEDSTACK_H
