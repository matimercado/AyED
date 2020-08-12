//
// Created by matimercado on 5/5/20.
//

#include "TokenHtml.h"

//================================= Metodos Clase Padre TokenHtml =================================

void TokenHtml::get_parseo() {
    cout << "Parseando --> ";
}

void TokenHtml::show() {
    cout << tagsAnidados->toPrint("") << endl;
}

//================================= Metodos Subclases de TokenHtml =================================
//----------------------------------------- Metodos Thml -------------------------------------------

void Thtml::get_parseo(Pila<string> *p) {
    TokenHtml::get_parseo();
    cout << "html" << endl;
    aux->concat(p);

    if (aux->tope() == "/html") {
        aux->desapilar();
        while (aux->tope() != "html") {
            //cout << aux->tope() << endl;
            tagsAnidados->add(aux->tope());
            aux->desapilar();
        }
    }
    //cout<<aux->tope()<<endl;
    //cout<<tagsAnidados->toPrint("");
}

void Thtml::show() {
    TokenHtml::show();
}

//----------------------------------------- Metodos Tbody -------------------------------------------

void Tbody::get_parseo(Pila<string> *p) {
    TokenHtml::get_parseo();
    cout << "body" << endl;
    aux->concat(p);

    while (aux->tope() != "/body" && aux->tope() != "html") {
        aux->desapilar();
        if (aux->tope() == "/body") {
            aux->desapilar();
            while (aux->tope() != "body") {
                // cout << aux->tope() << endl;
                tagsAnidados->add(aux->tope());
                aux->desapilar();
            }
        }
    }
    //cout<<aux->tope()<<endl;
    //cout<<tagsAnidados->toPrint("");
}

void Tbody::show() {
    TokenHtml::show();
}

//------------------------------------------- Metodos Th2 -------------------------------------------

void Th2::get_parseo(Pila<string> *p) {
    TokenHtml::get_parseo();
    cout << "h2" << endl;
    aux->concat(p);

    while (aux->tope() != "/h2" && aux->tope() != "html") {
        aux->desapilar();
        if (aux->tope() == "/h2") {
            aux->desapilar();
            while (aux->tope() != "h2") {
                //cout << aux->tope() << endl;
                tagsAnidados->add(aux->tope());
                aux->desapilar();
            }
        }
    }
    //cout<<aux->tope()<<endl;
    //cout<<tagsAnidados->toPrint("");
}

void Th2::show() {
    TokenHtml::show();
}

//----------------------------------------- Metodos Ttable -------------------------------------------

void Ttable::get_parseo(Pila<string> *p) {
    TokenHtml::get_parseo();
    cout << "table" << endl;
    aux->concat(p);

    while (aux->tope() != "/table" && aux->tope() != "html") {
        aux->desapilar();
        if (aux->tope() == "/table") {
            aux->desapilar();
            while (aux->tope() != "table") {
                //cout << aux->tope() << endl;
                tagsAnidados->add(aux->tope());
                aux->desapilar();
            }
        }
    }
    //cout<<aux->tope()<<endl;
    //cout<<tagsAnidados->toPrint("");
}

void Ttable::show() {
    TokenHtml::show();
}

//------------------------------------------- Metodos Ttr ---------------------------------------------

void Ttr::get_parseo(Pila<string> *p) {
    TokenHtml::get_parseo();
    cout << "tr" << endl;
    aux->concat(p);

    while (aux->tope() != "/tr" && aux->tope() != "html") {
        aux->desapilar();
        if (aux->tope() == "/tr") {
            aux->desapilar();
            while (aux->tope() != "tr") {
                // cout << aux->tope() << endl;
                tagsAnidados->add(aux->tope());
                aux->desapilar();
            }
        }
    }
    //cout<<aux->tope()<<endl;
    //cout<<tagsAnidados->toPrint("");
}

void Ttr::show() {
    TokenHtml::show();
}
//------------------------------------------- Metodos Tth ---------------------------------------------

void Tth::get_parseo(Pila<string> *p) {
    TokenHtml::get_parseo();
    cout << "th" << endl;
    aux->concat(p);

    while (aux->tope() != "/th" && aux->tope() != "html") {
        aux->desapilar();
        if (aux->tope() == "/th") {
            aux->desapilar();
            while (aux->tope() != "th") {
                //cout << aux->tope() << endl;
                tagsAnidados->add(aux->tope());
                aux->desapilar();
            }
        }
    }
    //cout<<aux->tope()<<endl;
    //cout<<tagsAnidados->toPrint("");
}

void Tth::show() {
    TokenHtml::show();
}

//------------------------------------------- Metodos Ttd ---------------------------------------------

void Ttd::get_parseo(Pila<string> *p) {
    TokenHtml::get_parseo();
    cout << "td" << endl;
    aux->concat(p);

    while (aux->tope() != "/td" && aux->tope() != "html") {
        aux->desapilar();
        if (aux->tope() == "/td") {
            aux->desapilar();
            while (aux->tope() != "td") {
                //cout << aux->tope() << endl;
                tagsAnidados->add(aux->tope());
                aux->desapilar();
            }
        }
    }
    //cout<<aux->tope()<<endl;
    //cout << tagsAnidados->toPrint("");

}

void Ttd::show() {
    TokenHtml::show();
}

//=====================================================================================================