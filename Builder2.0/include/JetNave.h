#ifndef JETNAVE_H
#define JETNAVE_H
#include "NaveBuilder.h"
#include "Nave.h"
//clase para construir el tipo de enemigo, osea la clase concreta//
class JetNave:public NaveBuilder{
    public:
        JetNave();
        virtual ~JetNave();
        void buildID();
        void buildVida();
        void buildResistencia();
        void buildVelocidad();
        void buildAtaque();
        void buildX();
        void buildY();
        void buildBoundX();
        void buildBoundY();
        Nave* getNave();

    protected:

    private:
        Nave *nave;
};

#endif // JETNAVE_H
