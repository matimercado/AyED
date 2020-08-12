//
// Created by matimercado on 2/5/20.
//

#ifndef PARCIAL1_ARCHIVO_H
#define PARCIAL1_ARCHIVO_H

#include <fstream>
#include "Pila.h"

//================================= Clase Archivo =================================

class Archivo {

private:
    Pila<string> *p = new Pila<string>;
    Pila<string> *p2 = new Pila<string>;
    Pila<string> *p3 = new Pila<string>;
    fstream html;
    string line;
    string token;
    const long int NUM = 10000;

    void apilame();

    void apilame2();

public:
    void set_html(string);

    void set_html2(string);

    void get_html();

    void givePila(Pila<string> *);
};

//===================================================================================

#endif //PARCIAL1_ARCHIVO_H
