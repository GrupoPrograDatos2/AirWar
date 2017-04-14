#include "Node.h"
#include <cstddef>
using namespace std;

Node::Node(int ID, bool Vida, int Resistencia, int Velocidad,int posX,int posY,int boundX,int boundY, Node* next) //const Iniciar con valor
{
    this -> ID = ID;
    this -> Vida = Vida;
    this -> Resistencia = Resistencia;
    this -> Velocidad = Velocidad;
    this -> posX = posX;
    this -> posY = posY;
    this -> boundX = boundX;
    this -> boundY = boundY;
    this -> next = next;
}

Node::Node(Node* next) //const Iniciar sin valor
{
    this->next = next;
}

Node::~Node() //destructorcito
{
    //dtor
}

//Getters :D
int Node::getID() //Returna el ID del nodo actual
{
    return ID;
}

bool Node::getVida() //Retorna el valor booleano de Vida//
{
    return Vida;
}

int Node::getResistencia()
{
    return Resistencia;
}

int Node::getVelocidad()
{
    return Velocidad;
}

int Node::getposX()
{
    return posX;
}

int Node::getposY()
{
    return posY;
}

int Node::getboundX()
{
    return boundX;
}


int Node::getboundY()
{
    return boundY;
}

Node* Node::getNext() //Apunta al siguiente nodo
{
    return next;
}

void Node::setNext(Node* node) //Apunta a un nuevo nodo
{
    next = node;
}
