//
// Created by matimercado on 4/5/20.
//

#ifndef PARCIAL1_TOKENHTML_H
#define PARCIAL1_TOKENHTML_H

#include "Archivo.h"

//================================= Clase Padre TokenHtml =================================

class TokenHtml {

protected:
    Lista<string> *tagsAnidados = new Lista<string>;
    Pila<string> *aux = new Pila<string>;

public:
    virtual void get_parseo();

    virtual void show();

};

//================================= Subclases de TokenHtml =================================
//----------------------------------------- Thml -------------------------------------------

class Thtml : public TokenHtml {
public:
    void show();

    void get_parseo(Pila<string> *);
};

//----------------------------------------- Tbody -------------------------------------------

class Tbody : public TokenHtml {
public:
    void show();

    void get_parseo(Pila<string> *);
};

//------------------------------------------ Th2 ---------------------------------------------

class Th2 : public TokenHtml {
public:
    void show();

    void get_parseo(Pila<string> *);
};

//----------------------------------------- Ttable -------------------------------------------

class Ttable : public TokenHtml {
public:
    void show();

    void get_parseo(Pila<string> *);
};

//------------------------------------------- Ttr ---------------------------------------------

class Ttr : public TokenHtml {
public:
    void show();

    void get_parseo(Pila<string> *);
};

//------------------------------------------- Tth ---------------------------------------------

class Tth : public TokenHtml {
public:
    void show();

    void get_parseo(Pila<string> *);
};

//------------------------------------------- Ttd ---------------------------------------------

class Ttd : public TokenHtml {
public:
    void show();

    void get_parseo(Pila<string> *);
};

//=============================================================================================

#endif //PARCIAL1_TOKENHTML_H
