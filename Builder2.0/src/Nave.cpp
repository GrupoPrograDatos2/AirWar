#include "Nave.h"
#include "NavePlano.h"

Nave::Nave()
{
    //ctor
}

Nave::~Nave()
{
    //dtor
}

void Nave::setID(int _pid){
    this -> pid = _pid;
}

void Nave::setVida(bool _vida){
    this -> vida = _vida;
}

void Nave::setResistencia(int _resistencia){
    this -> resistencia = _resistencia;
}

void Nave::setVelocidad(int _velocidad){
    this -> velocidad = _velocidad;
}

void Nave::setAtaque(int _ataque){
    this -> ataque = _ataque;
}

void Nave::setX(int _px){
    this -> px = _px;
}

void Nave::setY(int _py){
    this -> py = _py;
}

void Nave::setBoundX(int _X){
    this -> X = _X;
}

void Nave::setBoundY(int _Y){
    this -> Y = _Y;
}
