#include "ScheHS.h"

//================================== Metodos Clase ScheHS =================================

void ScheHS::addEvents() {
    cout << "\n=========== Ordenamiento por HeapSort ==========\n"<<endl;
    Nodo<Clock> *aux1;
    aux1 = clocks->nodo();

    for (int i = 0; i < clocks->size(); i++) {

        for (int j = 0; j < 50; j++) {
            events.push_back(aux1->get_dato().get_events()->getat(j)->get_dato());
        }
        aux1 = aux1->get_next();
    }

    heapsort(events, events.size());
}

void ScheHS::heapsort(vector<Event> &arr, int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)

        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void ScheHS::heapify(vector<Event> &arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    hsc++;
    if (l < n && arr[l].get_id() > arr[largest].get_id())
        largest = l;

    // If right child is larger than largest so far
    hsc++;
    if (r < n && arr[r].get_id() > arr[largest].get_id())
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

Event ScheHS::getNextEvent() {
    events.erase(events.begin());
    return events.front();
}






