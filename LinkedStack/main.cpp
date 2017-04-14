#include <iostream>
#include "LinkedStack.h"

using namespace std;

int main()
{
    LinkedStack* lista = new LinkedStack();
    cout << "La lista esta vacia: " << lista->isEmpty() << endl;
    for(int i=0; i<21; i++)
    {
        lista->push(i);
    }
    lista->print();
    cout << "Tamaño de la lista: " << lista->getSize() << endl;
    cout << "El elimino el elemento " << lista->pop() << endl;
    cout << "El elimino el elemento " << lista->pop() << endl;
    cout << "El elimino el elemento " << lista->pop() << endl;
    cout << "El elimino el elemento " << lista->pop() << endl;
    cout << "El elimino el elemento " << lista->pop() << endl;
    lista->print();
    cout << "El primer elemento de la lista es: " << lista->topValue() << endl;
    lista->clear();
    cout << "La lista esta vacia: " << lista->isEmpty() << endl;

    lista->~LinkedStack();
    return 0;
}
