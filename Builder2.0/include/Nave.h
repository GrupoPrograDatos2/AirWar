#ifndef NAVE_H
#define NAVE_H
#include <string>
#include "NavePlano.h"

//clase concreta interfaz del producto//
class Nave:public NavePlano{
    //metodos que armaran las navecitas//

    public:
        Nave();
        virtual ~Nave();
        void setID(int);
        void setVida(bool);
        void setResistencia(int);
        void setVelocidad(int );
        void setAtaque(int );
        void setX(int);
        void setY(int);
        void setBoundX(int );
        void setBoundY(int );


    protected:

    //variables de atributos de las navecitas//
    private:
        int pid, resistencia, velocidad, px, py, X, Y, ataque;
        bool vida;
};

#endif // NAVE_H
