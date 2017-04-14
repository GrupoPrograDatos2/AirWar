#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;

};
//funciones prototipo//
void insertar_elementos(Nodo *&, Nodo *&, int);
bool cola_vacia(Nodo *);
void eliminar_elemento(Nodo *&, Nodo *&,int &);

//funcion principal//
int main(){
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    int dato;

    int *lista = new int [100];
    srand(time(NULL));
    for(int i = 0; i<100; i++){
        lista[i] = (0 + rand() % (99-0));
        cout << lista[i] <<",";

    }
    for (int i = 0; i<100; i++){
        dato = lista[i];
        insertar_elementos(frente,fin,dato);

    }
    cout << "/n Quitando elementos de la cola: ";
    while (frente != NULL){
        eliminar_elemento(frente,fin,dato);
        if (frente != NULL){
            cout << dato << ",";
        }
        else{
            cout << dato << ".";
        }
    }
    return 0;

}
//agregar elementos a la cola//
void insertar_elementos(Nodo *&frente, Nodo *&fin, int n){
    //reservo memorria//
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo -> dato = n;
    nuevo_nodo -> siguiente = NULL;
    if (cola_vacia(frente)){
        frente = nuevo_nodo;
    }
    else{
        fin -> siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;
    cout << "/tElemento: "<< n << "insertado a la cola!!\n";

}

//funcion para saber si esta vacia la cola//
bool cola_vacia(Nodo *frente){
    return (frente == NULL)? true: false;

}

//eliminar elementos de la cola//
void eliminar_elemento(Nodo *&frente, Nodo *&fin, int &n){
    n = frente -> dato;
    Nodo *aux = frente;
    if (frente == fin){
        frente = NULL;
        fin == NULL;
    }
    else{
        frente = frente -> siguiente;
    }
    delete aux;
}

