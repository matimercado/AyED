#ifndef PARCIAL2_SCHEHS_H
#define PARCIAL2_SCHEHS_H
#include "Scheduler.h"

using namespace std;

//================================= ScheHS =================================

class ScheHS : public Scheduler {
private:
    int hsc; // comparaciones
    vector <Event> events;

public:
    void heapify(vector<Event> &, int, int);
    void heapsort(vector<Event> &, int);

    void addEvents();
    Event getNextEvent() override;
    string getCompares() override { return std::to_string(hsc) + " comparaciones con HeapSort <<\n"; };
    //T *get_eventsArray() {return events;};
};

//=============================================================================

#endif //PARCIAL2_SCHEHS_H
