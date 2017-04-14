#include "AirArmy.h"
#include "NaveBuilder.h"
#include "Nave.h"
//Director, me construye las navecitas//
AirArmy::AirArmy(NaveBuilder *naveBuilder){
    //ctor
    this -> naveBuilder = naveBuilder;

}

AirArmy::~AirArmy()
{
    //dtor
}

Nave* AirArmy::getNave(){
    return naveBuilder -> getNave();
}

void AirArmy::buildNave(){
    naveBuilder -> buildID();
    naveBuilder -> buildVida();
    naveBuilder -> buildResistencia();
    naveBuilder -> buildVelocidad();
    naveBuilder -> buildAtaque();
    naveBuilder -> buildX();
    naveBuilder -> buildY();
    naveBuilder -> buildBoundX();
    naveBuilder -> buildBoundY();
}

