//
// Created by matimercado on 18/5/20.
//

#ifndef PARCIAL2_LISTA_H
#define PARCIAL2_LISTA_H

#include <iostream>
#include <sstream>
#include "Nodo.h"

using namespace std;

//================================= Clase Lista =================================

template<class T>
class Lista {
private:
    Nodo<T> *czo;

public:
    Lista() { czo = new Nodo<T>(); };
    Lista(Nodo<T> *n) { czo = n; };
    void add(T d);
    bool esvacia();
    T cabeza();
    Lista *resto();
    string toPrint(string p);
    void borrar();
    void concat(Lista<T> *l1);
    Nodo<T> *nodo() { return czo; };
    int size();
    Nodo<T> *getat(int);
    void swapNodes(Lista<T> *, int, int);
};

//================================ Metodos Lista ================================

template<class T>
void Lista<T>::add(T d) {
    Nodo<T> *nuevo = new Nodo<T>(d);
    nuevo->set_next(czo);
    czo = nuevo;
}

template<class T>
bool Lista<T>::esvacia() {
    return czo->es_vacio();
}

template<class T>
T Lista<T>::cabeza() {
    if (this->esvacia()) {
        cout << " Error, Cabeza de lista vacia";
        //return 0;
    }
    return czo->get_dato();
}

template<class T>
Lista<T> *Lista<T>::resto() {
    Lista *l = new Lista(czo->get_next());
    return (l);
}

template<class T>
string Lista<T>::toPrint(string p) {
    if (this->esvacia()) {
        return p;
    } else {
        //std::ostringstream stm;
        ostringstream stm;
        stm << this->cabeza() << endl;
        //stm << "" << endl;
        stm << this->resto()->toPrint(p);// << endl;
        //cout<<endl<<" stm.str()= "<<stm.str()<<endl;
        return stm.str();
    }
}

template<class T>
void Lista<T>::borrar() { //borra el nodo cabeza
    if (!this->esvacia()) {
        Nodo<T> *tmp = czo;
        czo = czo->get_next();
        delete tmp;
    }
}

template<class T>
void Lista<T>::concat(Lista<T> *l1) {// le transfiere los datos de l1 a this
    if (!(l1->esvacia())) {
        this->concat(l1->resto());
        this->add(l1->cabeza());
    }
}

template<class T>
int Lista<T>::size() {
    if (this->esvacia()) return 0;
    return 1 + this->resto()->size();
}

template<class T>
Nodo<T> *Lista<T>::getat(int a) {
    Nodo<T> *aux;
    bool valido = (!this->esvacia()) && a >= 0 && this->size() > a;
    if (valido) {
        aux = this->czo;
        for (int i = 0; i < a; i++) {
            aux = aux->get_next();
        }
        return aux;
    } else return NULL;
}

template<class T>
void Lista<T>::swapNodes(Lista<T> *l, int a, int b) {
    Nodo<T> *n = l->nodo(); //cabeza

    Nodo<T> *aux1 = nullptr;
    Nodo<T> *aux2 = nullptr;
    Nodo<T> *bef1 = nullptr;
    Nodo<T> *bef2 = nullptr;

    if (a > b) {
        int aux = b;
        b = a;
        a = aux;
    }

    //condicion
    bool vale = (!this->esvacia()) && a >= 0 && this->size() > a && b >= 0 && this->size() > b;

    if (vale) {

        for (int i = 0; i <= b; i++) {
            if (i == (b - 1)) { bef1 = n; };
            if (i == b) { aux1 = n; };
            if (i == (a - 1)) { bef2 = n; };
            if (i == a) { aux2 = n; };
            n = n->get_next();
        }

        if (bef1) {
            bef1->set_next(aux2);
        } else {
            l->czo = aux2;
        }

        if (bef2) {
            bef2->set_next(aux1);
        } else {
            l->czo = aux1;
        }

        Nodo<T> *tmp = aux1->get_next();
        aux1->set_next(aux2->get_next());
        aux2->set_next(tmp);

    }
}


//=====================================================================================================

#endif //PARCIAL2_LISTA_H
