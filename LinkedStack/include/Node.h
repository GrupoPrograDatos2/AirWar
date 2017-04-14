#ifndef NODE_H
#define NODE_H
#include <cstddef> //Para que funcione el Null
using namespace std;

class Node
{
    public:
        Node(int value, Node* next=NULL);
        Node(Node* next=NULL);
        virtual ~Node();
        int getValue();
        Node* getNext();
        void setNext(Node* node);

    private:
        int value;
        Node* next; //Apunta a una instancia de la clase Node
};

#endif // NODE_H
