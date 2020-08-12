#include "ScheList.h"

//================================== Metodos Clase ScheList ==================================

void ScheList::addEvents() {
    cout << "\n=========== Ordenamiento por QuickSort ==========\n"<<endl;
    Nodo<Clock> *aux1;
    aux1 = clocks->nodo();

    for (int i = 0; i < get_clocksize(); i++) {
        events->concat(aux1->get_dato().get_events());
        aux1 = aux1->get_next();
        //aux1->get_dato().emptyList();
    }

    quicksort(0, events->size() - 1);
}

void ScheList::quicksort(int first, int last) {

    int i, j, pivot;
    if (last > first) {
        pivot = events->getat(last)->get_dato().get_id();
        i = first - 1;
        j = last;
        for (;;) {
            while (events->getat(++i)->get_dato().get_id() < pivot) qc++;
            while (events->getat(--j)->get_dato().get_id() > pivot) qc++;
            if (i >= j) break;
            events->swapNodes(events, i, j);
        }
        events->swapNodes(events, i, last);
        quicksort(first, i - 1);
        quicksort(i + 1, last);
    }
}

Event ScheList::getNextEvent() {
    events->borrar();
    return events->cabeza();
}