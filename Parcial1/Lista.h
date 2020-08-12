//
// Created by matimercado on 28/4/20.
//

#ifndef PARCIAL1_LISTA_H
#define PARCIAL1_LISTA_H

#include <iostream>
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

    //~Lista(void);
    void add(T d); //sumar nodos a la lista
    bool esvacia(void);

    T cabeza(void); //retorna el dato del primer nodo
    Lista *resto(void); //retorna el puntero al "resto" de la lista  //resto= lo que queda de la lista sin la cabeza

    string toPrint(string p);

    void borrar(void); //borra la cabeza
    void concat(Lista<T> *l1);// le transfiere los datos de l1 a this


};

//================================ Metodos Lista ================================

template<class T>
void Lista<T>::add(T d) //100
{
    Nodo<T> *nuevo = new Nodo<T>(d);
    nuevo->set_next(czo);
    czo = nuevo;
}

template<class T>
bool Lista<T>::esvacia(void) {
    return czo->es_vacio();
}

template<class T>
T Lista<T>::cabeza(void) {
    if (this->esvacia()) {
        cout << " Error, Cabeza de lista vacia";
        return 0;
    }
    return czo->get_dato();
}

template<class T>
Lista<T> *Lista<T>::resto(void) {
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
void Lista<T>::borrar(void) { //borra el nodo cabeza
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



//=====================================================================================================

#endif //PARCIAL1_LISTA_H
