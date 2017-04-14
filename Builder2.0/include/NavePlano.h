#ifndef NAVEPLANO_H
#define NAVEPLANO_H

//Clase interfaz del producto Enemigo//
class NavePlano
{
    public:
        NavePlano();
        virtual ~NavePlano();
        virtual void setID(int pid) = 0;
        virtual void setResistencia(int resistencia) = 0;
        virtual void setVida(bool vida) = 0;
        virtual void setVelocidad(int velocidad) = 0;
        virtual void setAtaque(int ataque) = 0;
        virtual void setX(int px) = 0;
        virtual void setY(int py) = 0;
        virtual void setBoundX(int X) = 0;
        virtual void setBoundY(int Y) = 0;

    protected:

    private:
};

#endif // NAVEPLANO_H
