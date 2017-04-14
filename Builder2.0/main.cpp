#include <iostream>
#include "Nave.h"
#include "NavePlano.h"
#include "NaveBuilder.h"
#include "JetNave.h"
#include "AirArmy.h"

using namespace std;

int main()
{
    NaveBuilder *JetNaveBldr = new JetNave();

    AirArmy *JNA = new AirArmy(JetNaveBldr);

    JNA -> buildNave();

    Nave *nave1 = JNA -> getNave();
    cout <<"Nave del tipo Jet construida exitosamente! " << " " << nave1;
    return 0;
}
