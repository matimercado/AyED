#ifndef PARCIAL2_CLOCK_H
#define PARCIAL2_CLOCK_H
#include <string>
#include <cstdlib>
#include <ctime>
#include "Lista.h"
#include "Event.h"

using namespace std;

//================================= Clock =================================

class Clock {
private:
    int number;
    string name;
    string type;
    int repeat;
    Lista<Event> *eventsClock = new Lista<Event>;

public:
    Clock() {};
    Clock(int, string, string, int);

    int random();
    void createEvents();
    string get_name() { return name; };
    string get_type() { return type; };
    int get_repeat() { return repeat; };
    Lista<Event> *get_events() { return eventsClock; };
};

//=============================================================================

#endif //PARCIAL2_CLOCK_H
