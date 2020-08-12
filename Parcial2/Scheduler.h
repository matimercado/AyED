#ifndef PARCIAL2_SCHEDULER_H
#define PARCIAL2_SCHEDULER_H
#include <ctime>
#include <vector>
#include <fstream>
#include <iostream>
#include "Lista.h"
#include "Clock.h"
#include "BinomialHeap.h"

using namespace std;

//================================= Scheduler =================================

class Scheduler {
private:
    unsigned int see = time(0);

protected:
    int launchedEvents, aux;
    Lista<Clock> *clocks = new Lista<Clock>;

public:
    Scheduler(){};

    void run();
    void date(); // https://www.youtube.com/watch?v=qXB5icpo0qY
    void write2();
    void write(Event);
    void addClock(Clock *);
    virtual void addEvents() = 0;
    virtual string getCompares() = 0;
    virtual Event getNextEvent() = 0;
    int get_clocksize () {return clocks->size();};
};

//=============================================================================

#endif //PARCIAL2_SCHEDULER_H
