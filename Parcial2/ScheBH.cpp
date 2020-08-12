#include "ScheBH.h"

//================================== Metodos Clase ScheList ==================================

void ScheBH::addEvents() {
    cout << "\n=========== Ordenamiento por BinomialHeap ==========\n" << endl;
    Nodo<Clock> *aux1;
    aux1 = clocks->nodo();

    for (int i = 0; i < clocks->size(); i++) {

        for (int j = 0; j < 50; j++) {
            events.insert(aux1->get_dato().get_events()->getat(j)->get_dato());
        }
        aux1 = aux1->get_next();
    }
}

Event ScheBH::getNextEvent() {
  return events.extractMin();
}