#ifndef PARCIAL2_NODO_H
#define PARCIAL2_NODO_H

using namespace std;

//================================= Clase Nodo =================================

template<class T>
class Nodo {
private:
    T data;
    Nodo *next;

public:
    Nodo() { next = NULL; };
    T get_dato() { return data; };
    void set_dato(T a) { data = a; };
    Nodo(T a) { data = a; next = NULL; };
    Nodo* get_next() { return this->next; };
    bool es_vacio() { return next == NULL; }
    void set_next(Nodo* n) { this->next=n; };
};

#endif //PARCIAL2_NODO_H
