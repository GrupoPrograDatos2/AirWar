#ifndef AIRARMY_H
#define AIRARMY_H
#include "NaveBuilder.h"

//Clase Director//
class AirArmy
{
    public:
        AirArmy();
        virtual ~AirArmy();
        AirArmy(NaveBuilder *naveBuilder);
        Nave *getNave();
        void buildNave();

    protected:

    private:
        NaveBuilder *naveBuilder;
};

#endif // AIRARMY_H
