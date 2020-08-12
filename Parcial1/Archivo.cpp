//
// Created by matimercado on 5/5/20.
//

#include <cstring>
#include "Archivo.h"

//================================= Metodos Clase Archivo =================================

void Archivo::set_html(string archivo) {
    html.open(archivo, ios::in);
    if (html.fail()) {
        cout << "No se puedo abrir el archivo" << endl;
    } else {

        apilame();
        html.close();

    }
}

void Archivo::set_html2(string archivo) {
    html.open(archivo, ios::in);
    if (html.fail()) {
        cout << "No se puedo abrir el archivo" << endl;
    } else {

        apilame2();
        html.close();

    }
}

void Archivo::apilame() {

    while (!html.eof()) {  //mientras no sea el final del archivo
        getline(html, line);

        for (int i = 0; i < line.length(); i++) {
            token = "";
            if (line.at(i) == '<') {
                for (int j = i; j < line.length(); j++) {
                    token = token + line.at(j);
                    if (line.at(j) == '>') {
                        j = line.length() + 1;
                    }
                }
                p->apilar(token);

            } else if (i < line.length() - 1) {

                if (line.at(i) == '>') {
                    for (int j = i + 1; j < line.length(); j++) {
                        if (line.at(j) != '<') {
                            token = token + line.at(j);
                        } else {
                            j = line.length();
                        }
                    }
                    p->apilar(token);
                }
            }
        }
    }

}

void Archivo::get_html() {
    cout << "La pila de tokens separados queda: \n" << endl;
    cout << p->toPrint("") << endl;
}

void Archivo::givePila(Pila<string> *h) {
    apilame2();
    h->concat(p3);
}

//========================================================================================

void Archivo::apilame2() {
    char lista[NUM];
    while (getline(html, line)) {  //mientras no sea el final del archivo

        strcpy(lista, line.c_str());
        char *a = strtok(lista, ">" "<");
        while (a != NULL) {
            p2->apilar(a);
            p3->apilar(p2->tope());
            p2->desapilar();

            a = strtok(NULL, ">" "<");
        }
    }
}



//=========================================================================================
