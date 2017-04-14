#include <iostream>
#include "LinkedQueue.h"
#include "Node.h"
using namespace std;

int main()
{
    LinkedQueue* lista = new LinkedQueue(); //Aqui creo la cola

    Node* Nave = new Node(23,true,12,21,45,45,67,78); //aqui se crea o establece la nave a ingresar

    lista->enqueue(Nave); //se mete a la cola

    Node* naveaux = lista->dequeue();//lo saco y lo guardo en una variable auxiliar ahi

    cout << naveaux->getID()<< endl;

    cout <<"OK";


    lista->~LinkedQueue();

    return 0;
}

