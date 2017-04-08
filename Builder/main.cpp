#include <iostream>
#include <time.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

//clase interfaz del producto(enemigo)//

class NavePlano{
    public:
        virtual void setResistencia(int resistencia) = 0;
        virtual void setVelocidad(int velocidad) = 0;
        virtual void setAtaque(string ataque) = 0;
        virtual void setPos_X(int posX) = 0;
        virtual void setPos_Y(int posy) = 0;

};

//clase concreta interfaz del producto//

class Nave:public NavePlano{
    //variables de atributos de las navecitas//
    private:
        int resistencia, velocidad, posX, posY;
        string ataque;
    //metodos que armaran las navecitas//
    public:
        void setResistencia(int _resistencia){
            this -> resistencia = _resistencia;
        }
        void setVelocidad(int _velocidad){
            this -> velocidad = _velocidad;
        }
        void setAtaque(string _ataque){
            this -> ataque = _ataque;
        }
        void setPos_X(int _posX){
            this -> posX = _posX;
        }
        void setPos_Y(int _posY){
            this -> posY = _posY;
        }
};

//Builder Class  :D //

class NaveBuilder{
    public:
        //funciones abstractas apra construir los atributos de las navecitas//
        virtual void buildResistencia() = 0;
        virtual void buildVelocidad() = 0;
        virtual void buildAtaque() = 0;
        virtual void buildPos_X() = 0;
        virtual void buildPos_Y() = 0;
        //La navecita es retornada mediante esta funcioncita//
        virtual Nave* getNave() = 0;
};

//Clases concreta para la interface del Builder de arriba//
/* Esto me construye el enemigo Jet*/
class JetNave:public NaveBuilder{
    /*Defino un puntero nave*/
    private:
        Nave *nave;

    public:
        JetNave(){
            nave = new Nave();
        }
        void buildResistencia(){
            nave -> setResistencia(10);
        }
        void buildVelocidad(){
            nave -> setVelocidad(50);
        }
        void buildAtaque(){
            nave -> setAtaque("Bajo");
        }
        void buildPos_X(){
            srand(time(NULL));
            nave -> setPos_X((0 + rand() % (99-0)));
        }
        void buildPos_Y(){
            nave -> setPos_Y(100);
        }
        Nave* getNave(){
            return this -> nave;
        }
};

/*Esto me construye el enemigo Bomnardero*/

class BombarderoNave:public NaveBuilder{
    /*Defino un puntero nave*/
    private:
        Nave *nave;

    public:
        BombarderoNave(){
            nave = new Nave();
        }
        void buildResistencia(){
            nave -> setResistencia(20);
        }
        void buildVelocidad(){
            nave -> setVelocidad(20);
        }
        void buildAtaque(){
            nave -> setAtaque("Alto");
        }
        void buildPos_X(){
            srand(time(NULL));
            nave -> setPos_X((0 + rand() % (99-0)));
        }
        void buildPos_Y(){
            nave -> setPos_Y(100);
        }
        Nave* getNave(){
            return this -> nave;
        }
};

/*Esto me construye el enemigo definido por mi #1*/

class NemesisNave:public NaveBuilder{
    /*Defino un puntero nave*/
    private:
        Nave *nave;

    public:
        NemesisNave(){
            nave = new Nave();
        }
        void buildResistencia(){
            nave -> setResistencia(20);
        }
        void buildVelocidad(){
            nave -> setVelocidad(30);
        }
        void buildAtaque(){
            nave -> setAtaque("Alto");
        }
        void buildPos_X(){
            srand(time(NULL));
            nave -> setPos_X((0 + rand() % (99-0)));
        }
        void buildPos_Y(){
            nave -> setPos_Y(100);
        }
        Nave* getNave(){
            return this -> nave;
        }
};

/*Este me construye un enemigo opcional #2*/

class PinataNave:public NaveBuilder{
    /*Defino un puntero nave*/
    private:
        Nave *nave;

    public:
        PinataNave(){
            nave = new Nave();
        }
        void buildResistencia(){
            nave -> setResistencia(40);
        }
        void buildVelocidad(){
            nave -> setVelocidad(10);
        }
        void buildAtaque(){
            nave -> setAtaque("Bajo");
        }
        void buildPos_X(){
            srand(time(NULL));
            nave -> setPos_X((0 + rand() % (99-0)));
        }
        void buildPos_Y(){
            nave -> setPos_Y(100);
        }
        Nave* getNave(){
            return this -> nave;
        }
};

//Director, me construye las navecitas//
class AirArmy{
    private:
        NaveBuilder *naveBuilder;
    public:
        AirArmy(NaveBuilder *naveBuilder){
            this -> naveBuilder = naveBuilder;
        }
        Nave *getNave(){
            return naveBuilder -> getNave();
        }
        void buildNave(){
            naveBuilder -> buildResistencia();
            naveBuilder -> buildVelocidad();
            naveBuilder -> buildAtaque();
            naveBuilder -> buildPos_X();
            naveBuilder -> buildPos_Y();
        }

};

//Funcoin main para usar el patron Builder :D//
int main(){
    NaveBuilder *JetNaveBldr = new JetNave();

    AirArmy *JNA = new AirArmy(JetNaveBldr);

    JNA -> buildNave();

    Nave *nave1 = JNA -> getNave();
    cout <<"Nave Jet construida exitosamente! " << " " << nave1;
}


