#include "Poderes.h"
#include "Player.h"

Poderes::Poderes(ind id)
{
    ID=id;
}

void Poderes::Aplicar(Player jugador)
{
    if(ID==1){
        jugador.escudo=true;//activa el escudo del jugador
    }
    if(ID==2){
        jugador.misiles=true;//activa los misiles del jugador
    }
    else{
        jugador.laser=true;//activa el laser del jugador
    }
}


Poderes::~Poderes()
{
    //dtor
}
