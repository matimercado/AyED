#ifndef PARCIAL2_SCHELIST_H
#define PARCIAL2_SCHELIST_H
#include "Scheduler.h"

using namespace std;

//================================= ScheList =================================

class ScheList : public Scheduler {
private:
    int qc; // comparaciones
    Lista<Event> *events = new Lista<Event>;

public:
    void addEvents();
    void quicksort(int, int);
    Event getNextEvent() override;
    string getCompares() override { return std::to_string(qc) + " comparaciones con QuickSort <<\n"; };
    Lista<Event> *get_events() { return events; };
};

//=============================================================================

#endif //PARCIAL2_SCHELIST_H
