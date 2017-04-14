#include <iostream>
#include <time.h>
#include <algorithm>
#include <stdlib.h>


#include "JetNave.h"
#include "Nave.h"

JetNave::JetNave(){
    //ctor
    nave = new Nave();

}

JetNave::~JetNave()
{
    //dtor
}

void JetNave::buildID(){
    nave -> setID(0);
}
void JetNave::buildVida(){
    nave -> setVida(true);
}
void JetNave::buildResistencia(){
    nave -> setResistencia(10);
}

void JetNave::buildVelocidad(){
    nave -> setVelocidad(50);
}

void JetNave::buildAtaque(){
    nave -> setAtaque(10);
}

void JetNave::buildX(){
    srand(time(NULL));
    nave -> setX((0 + rand() % (99-0)));
}

void JetNave::buildY(){
    nave -> setY(0);
}

void JetNave::buildBoundX(){
    nave -> setBoundX(0);
}

void JetNave::buildBoundY(){
    nave -> setBoundY(100);
}

Nave* JetNave::getNave(){
    return this -> nave;
}
