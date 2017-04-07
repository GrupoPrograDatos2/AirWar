#include <iostream>
#include <fstream>
#include <string>
using namespace std;

main () {


 ifstream fichero;
 string frase;
 string nombres;

 fichero.open ("ficheroTexto.txt",ios::in);
 getline (fichero,frase);
 while (!fichero.eof()){
    cout << frase << endl;
    getline(fichero ,frase);
 }

 fichero.close();

 }
