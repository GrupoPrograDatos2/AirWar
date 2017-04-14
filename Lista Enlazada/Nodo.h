#ifndef NODO_H
#define NODO_H
#include <cstddef> //Para que funcione el Null
using namespace std;

class Nodo
{
    public:
        Nodo(int value, Nodo* next=NULL);
        Nodo(Nodo* next=NULL);
        virtual ~Nodo();
        int getValue();
        Nodo* getNext();
        void setNext(Nodo* nodo);

    private:
        int value;
        Nodo* next; //Apunta a una instancia de la clase Nodo
};

#endif // NODo_H
