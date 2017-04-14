#ifndef NODE_H
#define NODE_H
#include <cstddef> //Para que funcione el Null
using namespace std;

class Node
{
    public:
        Node(int ID, bool Vida, int Resistencia, int Velocidad, int posX, int posY, int boundX, int boundY, Node* next=NULL);
        Node(Node* next=NULL);
        virtual ~Node();
        //Getters
        int getID();
        bool getVida();
        int getResistencia();
        int getVelocidad();
        int getposX();
        int getposY();
        int getboundX();
        int getboundY();
        Node* getNext();
        //Setter a nodito siguente
        void setNext(Node* node);

    private:
        int ID;
        int Resistencia;
        int Velocidad;
        int posX;
        int posY;
        int boundX;
        int boundY;
        bool Vida;
        Node* next; //Apunta a una instancia de la clase Node
};

#endif // NODE_H
