//
// Created by matimercado on 28/4/20.
//

#ifndef PARCIAL1_PILA_H
#define PARCIAL1_PILA_H
#include "Lista.h"

using namespace std;

template <class T> class Pila:public Lista<T>{
public:
    Pila(){Lista<T>();};
    void apilar(T d){this->add(d);};
    T tope(void){return this->cabeza();};
    void desapilar(void){this->borrar();};
    bool pilavacia(){return this->esvacia();};
};

#endif //PARCIAL1_PILA_H
