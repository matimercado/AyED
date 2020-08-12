//
// Created by matimercado on 28/4/20.
//

#ifndef PARCIAL1_NODO_H
#define PARCIAL1_NODO_H
#include "sstream"

using namespace std;

template <class T> class Nodo {
private:
    T dato;
    Nodo* next;
public:
    Nodo() { next = NULL; };
    Nodo(T a) { dato = a; next = NULL; };
    void set_dato(T a) { dato = a; };
    void set_next(Nodo* n) { next = n; };
    T get_dato() { return dato; };
    Nodo* get_next() { return next; };
    bool es_vacio() { return next == NULL; }
};

#endif //PARCIAL1_NODO_H
