#include "Clock.h"

//================================== Metodos Clase Clock ==================================

Clock::Clock(int number, string name, string type, int repeat) {
    this->number = number;
    this->name = name;
    this->type = type;
    this->repeat = repeat;
}

void Clock::createEvents() {
    string n;
    int t = 0;

    if (get_type() == "periodico") {
        for (int i = 0; i < 50; i++) {
            t = get_repeat() + t;
            n = get_name() + " Evento " + to_string(i + 1);
            eventsClock->add(Event(n, t));
        }
    } else {
        for (int i = 0; i < 50; i++) {
            t = random() + t;
            n = get_name() + " Evento " + to_string(i + 1);
            eventsClock->add(Event(n, t));
        }
    }
}

int Clock::random() {
    int ran = rand() % get_repeat() + 1;
    return ran;
}