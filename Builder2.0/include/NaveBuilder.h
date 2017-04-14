#ifndef NAVEBUILDER_H
#define NAVEBUILDER_H
#include "Nave.h"
//Builder Class  :D //
class NaveBuilder
{
    public:
        NaveBuilder();
        virtual ~NaveBuilder();
        //funciones abstractas para construir los atributos de las navecitas//
        virtual void buildID() = 0;
        virtual void buildVida() = 0;
        virtual void buildResistencia() = 0;
        virtual void buildVelocidad() = 0;
        virtual void buildAtaque() = 0;
        virtual void buildX() = 0;
        virtual void buildY() = 0;
        virtual void buildBoundX() = 0;
        virtual void buildBoundY() = 0;
        //La navecita es retornada mediante esta funcioncita//
        virtual Nave* getNave() = 0;

    protected:

    private:
};

#endif // NAVEBUILDER_H
